// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <asiolink/asio_wrapper.h>
#include <asiolink/io_service.h>
#include <asiolink/interval_timer.h>
#include <exceptions/exceptions.h>
#include <http/http_log.h>
#include <http/http_messages.h>
#include <http/thread_pool.h>
#include <util/multi_threading_mgr.h>
#include <util/unlock_guard.h>

#include <boost/shared_ptr.hpp>

#include <atomic>
#include <functional>
#include <iostream>
#include <list>
#include <mutex>
#include <thread>

using namespace isc;
using namespace isc::asiolink;
using namespace isc::http;
using namespace isc::util;

HttpThreadPool::HttpThreadPool(IOServicePtr io_service, size_t pool_size, bool defer_start /* = false */)
    : pool_size_(pool_size), io_service_(io_service), 
      run_state_(RunState::STOPPED), mutex_(), cv_()  {
    if (!pool_size) { 
        isc_throw(BadValue, "HttpThreadPool::ctor pool_size must be > 0");
    }

    if (!io_service_) {
        io_service_.reset(new IOService());
    }

    if (!defer_start) {
        start();
    }
}

HttpThreadPool::~HttpThreadPool() {
    if (getRunState() != RunState::STOPPED) {
        stop();
    }
}

void
HttpThreadPool::start() {
    if (getRunState() != RunState::STOPPED) {
        isc_throw(InvalidOperation, "HttpThreadPool::start already started!");
    }

    setRunState(RunState::RUN);

    // Prep IOservice for run() invocations.
    io_service_->restart();

    // Create a pool of threads, each calls run on the same, private
    // io_service instance
    for (std::size_t i = 0; i < pool_size_; ++i) {
        boost::shared_ptr<std::thread> thread(new std::thread(
            [this]() {
                bool done = false;
                while (!done) {
                    switch (getRunState()) {
                    case RunState::RUN:
                        io_service_->run();
                        break;
                    case RunState::PAUSED:
                    {
                        // We need to stop and wait to be released.
                        // Try it w/o timer. We don't care how we exit, we'll
                        // do whatever the current state dictates.
                        std::unique_lock<std::mutex> lck(mutex_);
                        static_cast<void>(cv_.wait_for(lck, std::chrono::seconds(60),
                            [&]() {
                                return (getRunState() != RunState::PAUSED);
                            }));

                        break;
                    }
                    case RunState::SHUTDOWN:
                        done = true;
                        break;
                    case RunState::STOPPED:
                        // THIS SHOULD NOT HAPPEN.
                        std::cout << "Somehow we're in stopped state and threads are alive!"
                                  << std::endl;
                        done = true;
                        break;
                    }
                }
            }));

        threads_.push_back(thread);
    }
}

void
HttpThreadPool::stop() {
    if (getRunState() == RunState::STOPPED) {
        // Nothing to do.
        return;
    }

    std::cout << "HttpThreadPool::stop - stopping" << std::endl;

    setRunState(RunState::SHUTDOWN);

    // Stop the private IOService.
    if (!io_service_->stopped()) {
        io_service_->stop();
    }

    // Shutdown the threads.
    for (auto const& thread : threads_) {
        thread->join();
    }

    // Empty the pool.
    threads_.clear();

    // Should we consider a reset()/poll() call here?

    setRunState(RunState::STOPPED);
}

void
HttpThreadPool::pause() {
    if (getRunState() !=  RunState::RUN) {
        std::cout << "HttpThreadPool::pause - not running" << std::endl;
        return;
    }

    std::cout << "HttpThreadPool pausing" << std::endl;
    setRunState(RunState::PAUSED);
    io_service_->stop();
}

void
HttpThreadPool::resume() {
    if (getRunState() !=  RunState::PAUSED) {
        std::cout << "HttpThreadPool::resume - not paused" << std::endl;
        return;
    }

    std::cout << "HttpThreadPool resuming" << std::endl;
    io_service_->restart();
    setRunState(RunState::RUN);
}

HttpThreadPool::RunState
HttpThreadPool::getRunState() const {
    return(run_state_.load());
}

void 
HttpThreadPool::setRunState(RunState state) {
    run_state_.store(state);
    if (threads_.size()) {
        cv_.notify_all();
    }
}

IOServicePtr
HttpThreadPool::getIOService() const {
    return (io_service_);
}

uint16_t
HttpThreadPool::getPoolSize() const {
    return (pool_size_);
}

uint16_t
HttpThreadPool::getThreadCount() const {
    return (threads_.size());
}
