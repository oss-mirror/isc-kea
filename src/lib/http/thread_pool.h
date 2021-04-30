// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef HTTP_THREAD_POOL_H
#define HTTP_THREAD_POOL_H

#include <asiolink/io_service.h>
#include <util/unlock_guard.h>

#include <boost/shared_ptr.hpp>

#include <atomic>
#include <condition_variable>
#include <list>
#include <mutex>
#include <thread>

namespace isc {
namespace http {

class HttpThreadPool {
public:
    enum class RunState {
        STOPPED,
        RUN,
        PAUSED,
        SHUTDOWN,
    };

    HttpThreadPool(asiolink::IOServicePtr io_service, size_t pool_size, bool defer_start = false);

    ~HttpThreadPool();

    void start();

    void stop();

    void pause();

    void resume();

    RunState getRunState() const;

private:
    void setRunState(RunState state);

public:
    asiolink::IOServicePtr getIOService() const;

    /// @brief Fetches the maximum size of the thread pool.
    ///
    /// @return the maximum size of the thread pool.
    uint16_t getPoolSize() const;

    /// @brief Fetches the number of threads in the pool.
    ///
    /// @return the number of running threads.
    uint16_t getThreadCount() const;

private:
    /// @brief Maxim number of threads in the thread pool.
    size_t pool_size_;

    /// @brief Pointer to private IOService used in multi-threaded mode.
    asiolink::IOServicePtr io_service_;

    std::atomic<RunState> run_state_;
    std::mutex mutex_;
    std::condition_variable cv_;

    /// @brief Pool of threads used to service connections in multi-threaded
    /// mode.
    std::list<boost::shared_ptr<std::thread> > threads_;
};

typedef boost::shared_ptr<HttpThreadPool> HttpThreadPoolPtr;

} // end of namespace isc::http
} // end of namespace isc

#endif

