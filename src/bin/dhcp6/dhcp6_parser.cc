// A Bison parser, made by GNU Bison 3.3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.


// Take the name prefix into account.
#define yylex   parser6_lex



#include "dhcp6_parser.h"


// Unqualified %code blocks.
#line 34 "dhcp6_parser.yy" // lalr1.cc:435

#include <dhcp6/parser_context.h>

#line 51 "dhcp6_parser.cc" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if PARSER6_DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !PARSER6_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PARSER6_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "dhcp6_parser.yy" // lalr1.cc:510
namespace isc { namespace dhcp {
#line 146 "dhcp6_parser.cc" // lalr1.cc:510

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Dhcp6Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Dhcp6Parser::Dhcp6Parser (isc::dhcp::Parser6Context& ctx_yyarg)
    :
#if PARSER6_DEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      ctx (ctx_yyarg)
  {}

  Dhcp6Parser::~Dhcp6Parser ()
  {}

  Dhcp6Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  Dhcp6Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Dhcp6Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Dhcp6Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Dhcp6Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Dhcp6Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Dhcp6Parser::symbol_number_type
  Dhcp6Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Dhcp6Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Dhcp6Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 229: // value
      case 233: // map_value
      case 274: // ddns_replace_client_name_value
      case 315: // db_type
      case 332: // on_fail_mode
      case 422: // hr_mode
      case 558: // duid_type
      case 601: // ncr_protocol_value
        value.YY_MOVE_OR_COPY< ElementPtr > (YY_MOVE (that.value));
        break;

      case 212: // "boolean"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 211: // "floating point"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 210: // "integer"
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case 209: // "constant string"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Dhcp6Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 229: // value
      case 233: // map_value
      case 274: // ddns_replace_client_name_value
      case 315: // db_type
      case 332: // on_fail_mode
      case 422: // hr_mode
      case 558: // duid_type
      case 601: // ncr_protocol_value
        value.move< ElementPtr > (YY_MOVE (that.value));
        break;

      case 212: // "boolean"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 211: // "floating point"
        value.move< double > (YY_MOVE (that.value));
        break;

      case 210: // "integer"
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case 209: // "constant string"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Dhcp6Parser::stack_symbol_type&
  Dhcp6Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 229: // value
      case 233: // map_value
      case 274: // ddns_replace_client_name_value
      case 315: // db_type
      case 332: // on_fail_mode
      case 422: // hr_mode
      case 558: // duid_type
      case 601: // ncr_protocol_value
        value.move< ElementPtr > (that.value);
        break;

      case 212: // "boolean"
        value.move< bool > (that.value);
        break;

      case 211: // "floating point"
        value.move< double > (that.value);
        break;

      case 210: // "integer"
        value.move< int64_t > (that.value);
        break;

      case 209: // "constant string"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Dhcp6Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PARSER6_DEBUG
  template <typename Base>
  void
  Dhcp6Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 209: // "constant string"
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < std::string > (); }
#line 407 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 210: // "integer"
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < int64_t > (); }
#line 413 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 211: // "floating point"
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < double > (); }
#line 419 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 212: // "boolean"
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < bool > (); }
#line 425 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 229: // value
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 431 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 233: // map_value
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 437 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 274: // ddns_replace_client_name_value
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 443 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 315: // db_type
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 449 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 332: // on_fail_mode
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 455 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 422: // hr_mode
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 461 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 558: // duid_type
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 467 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      case 601: // ncr_protocol_value
#line 292 "dhcp6_parser.yy" // lalr1.cc:676
        { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 473 "dhcp6_parser.cc" // lalr1.cc:676
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  Dhcp6Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Dhcp6Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Dhcp6Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if PARSER6_DEBUG
  std::ostream&
  Dhcp6Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Dhcp6Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Dhcp6Parser::debug_level_type
  Dhcp6Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Dhcp6Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PARSER6_DEBUG

  Dhcp6Parser::state_type
  Dhcp6Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Dhcp6Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Dhcp6Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Dhcp6Parser::operator() ()
  {
    return parse ();
  }

  int
  Dhcp6Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 229: // value
      case 233: // map_value
      case 274: // ddns_replace_client_name_value
      case 315: // db_type
      case 332: // on_fail_mode
      case 422: // hr_mode
      case 558: // duid_type
      case 601: // ncr_protocol_value
        yylhs.value.emplace< ElementPtr > ();
        break;

      case 212: // "boolean"
        yylhs.value.emplace< bool > ();
        break;

      case 211: // "floating point"
        yylhs.value.emplace< double > ();
        break;

      case 210: // "integer"
        yylhs.value.emplace< int64_t > ();
        break;

      case 209: // "constant string"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 301 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 740 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 4:
#line 302 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.CONFIG; }
#line 746 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 6:
#line 303 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.DHCP6; }
#line 752 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 8:
#line 304 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.INTERFACES_CONFIG; }
#line 758 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 10:
#line 305 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.SUBNET6; }
#line 764 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 12:
#line 306 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.POOLS; }
#line 770 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 14:
#line 307 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.PD_POOLS; }
#line 776 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 16:
#line 308 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.RESERVATIONS; }
#line 782 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 18:
#line 309 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.DHCP6; }
#line 788 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 20:
#line 310 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.OPTION_DEF; }
#line 794 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 22:
#line 311 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.OPTION_DATA; }
#line 800 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 24:
#line 312 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 806 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 26:
#line 313 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.DHCP_DDNS; }
#line 812 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 28:
#line 314 "dhcp6_parser.yy" // lalr1.cc:919
    { ctx.ctx_ = ctx.CONFIG_CONTROL; }
#line 818 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 30:
#line 322 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 824 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 31:
#line 323 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 830 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 32:
#line 324 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 836 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 33:
#line 325 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 842 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 34:
#line 326 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 848 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 35:
#line 327 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 854 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 36:
#line 328 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 860 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 37:
#line 331 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 869 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 38:
#line 336 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 880 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 39:
#line 341 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 890 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 40:
#line 347 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 896 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 43:
#line 354 "dhcp6_parser.yy" // lalr1.cc:919
    {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 906 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 44:
#line 359 "dhcp6_parser.yy" // lalr1.cc:919
    {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 917 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 45:
#line 367 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 926 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 46:
#line 370 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // list parsing complete. Put any sanity checking here
}
#line 934 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 49:
#line 378 "dhcp6_parser.yy" // lalr1.cc:919
    {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 943 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 50:
#line 382 "dhcp6_parser.yy" // lalr1.cc:919
    {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 952 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 51:
#line 389 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // List parsing about to start
}
#line 960 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 52:
#line 391 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // list parsing complete. Put any sanity checking here
    //ctx.stack_.pop_back();
}
#line 969 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 55:
#line 400 "dhcp6_parser.yy" // lalr1.cc:919
    {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 978 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 56:
#line 404 "dhcp6_parser.yy" // lalr1.cc:919
    {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 987 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 57:
#line 415 "dhcp6_parser.yy" // lalr1.cc:919
    {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 998 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 58:
#line 424 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1009 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 59:
#line 429 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.

    // Dhcp6 is required
    ctx.require("Dhcp6", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
}
#line 1022 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 60:
#line 439 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // This code is executed when we're about to start parsing
    // the content of the map
    // Prevent against duplicate.
    ctx.unique("Dhcp6", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("Dhcp6", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP6);
}
#line 1037 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 61:
#line 448 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No global parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1047 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 62:
#line 456 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the Dhcp6 map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1057 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 63:
#line 460 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No global parameter is required
    // parsing completed
}
#line 1066 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 129:
#line 536 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("data-directory", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1075 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 130:
#line 539 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr datadir(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data-directory", datadir);
    ctx.leave();
}
#line 1085 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 131:
#line 545 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("preferred-lifetime", prf);
}
#line 1095 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 132:
#line 551 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("min-preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-preferred-lifetime", prf);
}
#line 1105 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 133:
#line 557 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-preferred-lifetime", prf);
}
#line 1115 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 134:
#line 563 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("valid-lifetime", prf);
}
#line 1125 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 135:
#line 569 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("min-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-valid-lifetime", prf);
}
#line 1135 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 136:
#line 575 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-valid-lifetime", prf);
}
#line 1145 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 137:
#line 581 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("renew-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("renew-timer", prf);
}
#line 1155 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 138:
#line 587 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("rebind-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rebind-timer", prf);
}
#line 1165 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 139:
#line 593 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("calculate-tee-times", ctx.loc2pos(yystack_[2].location));
    ElementPtr ctt(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("calculate-tee-times", ctt);
}
#line 1175 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 140:
#line 599 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("t1-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t1(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t1-percent", t1);
}
#line 1185 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 141:
#line 605 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("t2-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t2(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t2-percent", t2);
}
#line 1195 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 142:
#line 611 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("cache-threshold", ctx.loc2pos(yystack_[2].location));
    ElementPtr ct(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-threshold", ct);
}
#line 1205 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 143:
#line 617 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("cache-max-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr cm(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-max-age", cm);
}
#line 1215 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 144:
#line 623 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("decline-probation-period", ctx.loc2pos(yystack_[2].location));
    ElementPtr dpp(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("decline-probation-period", dpp);
}
#line 1225 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 145:
#line 629 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-send-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-send-updates", b);
}
#line 1235 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 146:
#line 635 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-no-update", b);
}
#line 1245 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 147:
#line 641 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-client-update", b);
}
#line 1255 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 148:
#line 647 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 1264 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 149:
#line 650 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("ddns-replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1273 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 150:
#line 656 "dhcp6_parser.yy" // lalr1.cc:919
    {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1281 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 151:
#line 659 "dhcp6_parser.yy" // lalr1.cc:919
    {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("never", ctx.loc2pos(yystack_[0].location)));
      }
#line 1289 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 152:
#line 662 "dhcp6_parser.yy" // lalr1.cc:919
    {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("always", ctx.loc2pos(yystack_[0].location)));
      }
#line 1297 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 153:
#line 665 "dhcp6_parser.yy" // lalr1.cc:919
    {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-not-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1305 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 154:
#line 668 "dhcp6_parser.yy" // lalr1.cc:919
    {
      error(yystack_[0].location, "boolean values for the replace-client-name are "
                "no longer supported");
      }
#line 1314 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 155:
#line 674 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1323 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 156:
#line 677 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-generated-prefix", s);
    ctx.leave();
}
#line 1333 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 157:
#line 683 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1342 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 158:
#line 686 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-qualifying-suffix", s);
    ctx.leave();
}
#line 1352 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 159:
#line 692 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-update-on-renew", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-update-on-renew", b);
}
#line 1362 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 160:
#line 698 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ddns-use-conflict-resolution", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-use-conflict-resolution", b);
}
#line 1372 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 161:
#line 704 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1381 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 162:
#line 707 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 1391 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 163:
#line 713 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1400 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 164:
#line 716 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 1410 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 165:
#line 722 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("store-extended-info", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("store-extended-info", b);
}
#line 1420 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 166:
#line 728 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("statistic-default-sample-count", ctx.loc2pos(yystack_[2].location));
    ElementPtr count(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-count", count);
}
#line 1430 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 167:
#line 734 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("statistic-default-sample-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr age(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-age", age);
}
#line 1440 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 168:
#line 740 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("server-tag", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1449 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 169:
#line 743 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr stag(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-tag", stag);
    ctx.leave();
}
#line 1459 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 170:
#line 749 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("parked-packet-limit", ctx.loc2pos(yystack_[2].location));
    ElementPtr ppl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("parked-packet-limit", ppl);
}
#line 1469 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 171:
#line 755 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ip-reservations-unique", ctx.loc2pos(yystack_[2].location));
    ElementPtr unique(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-reservations-unique", unique);
}
#line 1479 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 172:
#line 761 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("interfaces-config", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces-config", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.INTERFACES_CONFIG);
}
#line 1491 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 173:
#line 767 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No interfaces config param is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1501 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 174:
#line 773 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the interfaces-config map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1511 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 175:
#line 777 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No interfaces config param is required
    // parsing completed
}
#line 1520 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 183:
#line 793 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("interfaces", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1532 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 184:
#line 799 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1541 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 185:
#line 804 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("re-detect", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("re-detect", b);
}
#line 1551 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 186:
#line 810 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("lease-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lease-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.LEASE_DATABASE);
}
#line 1563 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 187:
#line 816 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1574 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 188:
#line 823 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hosts-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1586 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 189:
#line 829 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1597 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 190:
#line 836 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hosts-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1609 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 191:
#line 842 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1618 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 196:
#line 855 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1628 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 197:
#line 859 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1638 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 222:
#line 893 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_TYPE);
}
#line 1647 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 223:
#line 896 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1656 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 224:
#line 901 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("memfile", ctx.loc2pos(yystack_[0].location))); }
#line 1662 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 225:
#line 902 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("mysql", ctx.loc2pos(yystack_[0].location))); }
#line 1668 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 226:
#line 903 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("postgresql", ctx.loc2pos(yystack_[0].location))); }
#line 1674 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 227:
#line 904 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("cql", ctx.loc2pos(yystack_[0].location))); }
#line 1680 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 228:
#line 907 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("user", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1689 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 229:
#line 910 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("user", user);
    ctx.leave();
}
#line 1699 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 230:
#line 916 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("password", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1708 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 231:
#line 919 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr pwd(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("password", pwd);
    ctx.leave();
}
#line 1718 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 232:
#line 925 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("host", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1727 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 233:
#line 928 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr h(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host", h);
    ctx.leave();
}
#line 1737 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 234:
#line 934 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    ElementPtr p(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", p);
}
#line 1747 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 235:
#line 940 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1756 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 236:
#line 943 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1766 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 237:
#line 949 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("persist", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("persist", n);
}
#line 1776 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 238:
#line 955 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("lfc-interval", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lfc-interval", n);
}
#line 1786 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 239:
#line 961 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("readonly", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("readonly", n);
}
#line 1796 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 240:
#line 967 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("connect-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("connect-timeout", n);
}
#line 1806 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 241:
#line 973 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reconnect-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reconnect-wait-time", n);
}
#line 1816 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 242:
#line 979 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("on-fail", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_ON_FAIL);
}
#line 1825 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 243:
#line 982 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("on-fail", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1834 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 244:
#line 987 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("stop-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 1840 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 245:
#line 988 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 1846 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 246:
#line 989 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-continue", ctx.loc2pos(yystack_[0].location))); }
#line 1852 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 247:
#line 992 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-row-errors", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-row-errors", n);
}
#line 1862 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 248:
#line 998 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("request-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("request-timeout", n);
}
#line 1872 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 249:
#line 1004 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("tcp-keepalive", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tcp-keepalive", n);
}
#line 1882 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 250:
#line 1010 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("tcp-nodelay", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tcp-nodelay", n);
}
#line 1892 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 251:
#line 1016 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("contact-points", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1901 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 252:
#line 1019 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr cp(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("contact-points", cp);
    ctx.leave();
}
#line 1911 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 253:
#line 1025 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-reconnect-tries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reconnect-tries", n);
}
#line 1921 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 254:
#line 1031 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("keyspace", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1930 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 255:
#line 1034 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr ks(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("keyspace", ks);
    ctx.leave();
}
#line 1940 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 256:
#line 1040 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("consistency", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1949 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 257:
#line 1043 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr c(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("consistency", c);
    ctx.leave();
}
#line 1959 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 258:
#line 1049 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("serial-consistency", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1968 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 259:
#line 1052 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr c(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("serial-consistency", c);
    ctx.leave();
}
#line 1978 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 260:
#line 1058 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("sanity-checks", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sanity-checks", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SANITY_CHECKS);
}
#line 1990 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 261:
#line 1064 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1999 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 265:
#line 1074 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("lease-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2008 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 266:
#line 1077 "dhcp6_parser.yy" // lalr1.cc:919
    {

    if ( (string(yystack_[0].value.as < std::string > ()) == "none") ||
         (string(yystack_[0].value.as < std::string > ()) == "warn") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix-del") ||
         (string(yystack_[0].value.as < std::string > ()) == "del")) {
        ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("lease-checks", user);
        ctx.leave();
    } else {
        error(yystack_[0].location, "Unsupported 'lease-checks value: " + string(yystack_[0].value.as < std::string > ()) +
              ", supported values are: none, warn, fix, fix-del, del");
    }
}
#line 2028 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 267:
#line 1093 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("mac-sources", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("mac-sources", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.MAC_SOURCES);
}
#line 2040 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 268:
#line 1099 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2049 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 273:
#line 1112 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr duid(new StringElement("duid", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2058 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 274:
#line 1117 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr duid(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2067 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 275:
#line 1122 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("host-reservation-identifiers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host-reservation-identifiers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOST_RESERVATION_IDENTIFIERS);
}
#line 2079 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 276:
#line 1128 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2088 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 282:
#line 1142 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr hwaddr(new StringElement("hw-address", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(hwaddr);
}
#line 2097 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 283:
#line 1147 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr flex_id(new StringElement("flex-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(flex_id);
}
#line 2106 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 284:
#line 1154 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("relay-supplied-options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay-supplied-options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2118 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 285:
#line 1160 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2127 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 286:
#line 1167 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("multi-threading", ctx.loc2pos(yystack_[0].location));
    ElementPtr mt(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("multi-threading", mt);
    ctx.stack_.push_back(mt);
    ctx.enter(ctx.DHCP_MULTI_THREADING);
}
#line 2139 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 287:
#line 1173 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The enable parameter is required.
    ctx.require("enable-multi-threading", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2150 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 296:
#line 1192 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("enable-multi-threading", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-multi-threading", b);
}
#line 2160 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 297:
#line 1198 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("thread-pool-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("thread-pool-size", prf);
}
#line 2170 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 298:
#line 1204 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("packet-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("packet-queue-size", prf);
}
#line 2180 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 299:
#line 1210 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 2192 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 300:
#line 1216 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2201 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 305:
#line 1229 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2211 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 306:
#line 1233 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2221 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 307:
#line 1239 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2231 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 308:
#line 1243 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2241 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 314:
#line 1258 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2250 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 315:
#line 1261 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 2260 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 316:
#line 1267 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2269 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 317:
#line 1270 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2278 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 318:
#line 1276 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("expired-leases-processing", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("expired-leases-processing", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.EXPIRED_LEASES_PROCESSING);
}
#line 2290 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 319:
#line 1282 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No expired lease parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2300 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 328:
#line 1300 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reclaim-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reclaim-timer-wait-time", value);
}
#line 2310 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 329:
#line 1306 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("flush-reclaimed-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush-reclaimed-timer-wait-time", value);
}
#line 2320 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 330:
#line 1312 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hold-reclaimed-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hold-reclaimed-time", value);
}
#line 2330 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 331:
#line 1318 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-reclaim-leases", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-leases", value);
}
#line 2340 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 332:
#line 1324 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-reclaim-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-time", value);
}
#line 2350 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 333:
#line 1330 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("unwarned-reclaim-cycles", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("unwarned-reclaim-cycles", value);
}
#line 2360 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 334:
#line 1339 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("subnet6", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet6", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SUBNET6);
}
#line 2372 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 335:
#line 1345 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2381 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 340:
#line 1365 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2391 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 341:
#line 1369 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Once we reached this place, the subnet parsing is now complete.
    // If we want to, we can implement default values here.
    // In particular we can do things like this:
    // if (!ctx.stack_.back()->get("interface")) {
    //     ctx.stack_.back()->set("interface", StringElement("loopback"));
    // }
    //
    // We can also stack up one level (Dhcp6) and copy over whatever
    // global parameters we want to:
    // if (!ctx.stack_.back()->get("renew-timer")) {
    //     ElementPtr renew = ctx_stack_[...].get("renew-timer");
    //     if (renew) {
    //         ctx.stack_.back()->set("renew-timer", renew);
    //     }
    // }

    // The subnet subnet6 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2417 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 342:
#line 1391 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the subnet6 list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2427 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 343:
#line 1395 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The subnet subnet6 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2437 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 389:
#line 1452 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2446 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 390:
#line 1455 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr subnet(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet", subnet);
    ctx.leave();
}
#line 2456 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 391:
#line 1461 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2465 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 392:
#line 1464 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface", iface);
    ctx.leave();
}
#line 2475 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 393:
#line 1470 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("interface-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2484 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 394:
#line 1473 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface-id", iface);
    ctx.leave();
}
#line 2494 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 395:
#line 1479 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("client-class", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2503 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 396:
#line 1482 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr cls(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-class", cls);
    ctx.leave();
}
#line 2513 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 397:
#line 1488 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("require-client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("require-client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2525 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 398:
#line 1494 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2534 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 399:
#line 1499 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reservations-global", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-global", b);
}
#line 2544 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 400:
#line 1505 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reservations-in-subnet", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-in-subnet", b);
}
#line 2554 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 401:
#line 1511 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reservations-out-of-pool", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-out-of-pool", b);
}
#line 2564 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 402:
#line 1517 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reservation-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.RESERVATION_MODE);
}
#line 2573 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 403:
#line 1520 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("reservation-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2582 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 404:
#line 1525 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("disabled", ctx.loc2pos(yystack_[0].location))); }
#line 2588 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 405:
#line 1526 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("out-of-pool", ctx.loc2pos(yystack_[0].location))); }
#line 2594 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 406:
#line 1527 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("global", ctx.loc2pos(yystack_[0].location))); }
#line 2600 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 407:
#line 1528 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("all", ctx.loc2pos(yystack_[0].location))); }
#line 2606 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 408:
#line 1531 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("id", ctx.loc2pos(yystack_[2].location));
    ElementPtr id(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("id", id);
}
#line 2616 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 409:
#line 1537 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("rapid-commit", ctx.loc2pos(yystack_[2].location));
    ElementPtr rc(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rapid-commit", rc);
}
#line 2626 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 410:
#line 1545 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("shared-networks", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("shared-networks", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SHARED_NETWORK);
}
#line 2638 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 411:
#line 1551 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2647 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 416:
#line 1566 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2657 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 417:
#line 1570 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
}
#line 2665 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 460:
#line 1624 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("option-def", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-def", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DEF);
}
#line 2677 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 461:
#line 1630 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2686 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 462:
#line 1638 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2695 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 463:
#line 1641 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // parsing completed
}
#line 2703 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 468:
#line 1657 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2713 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 469:
#line 1661 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2725 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 470:
#line 1672 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the option-def list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2735 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 471:
#line 1676 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2747 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 487:
#line 1708 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("code", ctx.loc2pos(yystack_[2].location));
    ElementPtr code(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("code", code);
}
#line 2757 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 489:
#line 1716 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2766 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 490:
#line 1719 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("type", prf);
    ctx.leave();
}
#line 2776 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 491:
#line 1725 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("record-types", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2785 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 492:
#line 1728 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr rtypes(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("record-types", rtypes);
    ctx.leave();
}
#line 2795 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 493:
#line 1734 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("space", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2804 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 494:
#line 1737 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr space(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("space", space);
    ctx.leave();
}
#line 2814 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 496:
#line 1745 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("encapsulate", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2823 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 497:
#line 1748 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr encap(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("encapsulate", encap);
    ctx.leave();
}
#line 2833 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 498:
#line 1754 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("array", ctx.loc2pos(yystack_[2].location));
    ElementPtr array(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("array", array);
}
#line 2843 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 499:
#line 1764 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("option-data", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-data", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DATA);
}
#line 2855 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 500:
#line 1770 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2864 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 505:
#line 1789 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2874 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 506:
#line 1793 "dhcp6_parser.yy" // lalr1.cc:919
    {
    /// @todo: the code or name parameters are required.
    ctx.stack_.pop_back();
}
#line 2883 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 507:
#line 1801 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the option-data list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2893 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 508:
#line 1805 "dhcp6_parser.yy" // lalr1.cc:919
    {
    /// @todo: the code or name parameters are required.
    // parsing completed
}
#line 2902 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 523:
#line 1838 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("data", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2911 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 524:
#line 1841 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr data(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data", data);
    ctx.leave();
}
#line 2921 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 527:
#line 1851 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("csv-format", ctx.loc2pos(yystack_[2].location));
    ElementPtr space(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("csv-format", space);
}
#line 2931 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 528:
#line 1857 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("always-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("always-send", persist);
}
#line 2941 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 529:
#line 1866 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.POOLS);
}
#line 2953 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 530:
#line 1872 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2962 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 535:
#line 1887 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2972 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 536:
#line 1891 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2982 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 537:
#line 1897 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2992 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 538:
#line 1901 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3002 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 548:
#line 1920 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("pool", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3011 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 549:
#line 1923 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr pool(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pool", pool);
    ctx.leave();
}
#line 3021 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 550:
#line 1929 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3029 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 551:
#line 1931 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context = yystack_[0].value.as < ElementPtr > ();
    ConstElementPtr old = parent->get("user-context");

    // Handle already existing user context
    if (old) {
        // Check if it was a comment or a duplicate
        if ((old->size() != 1) || !old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the comment
        user_context->set("comment", old->get("comment"));
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 3056 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 552:
#line 1954 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3064 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 553:
#line 1956 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context(new MapElement(ctx.loc2pos(yystack_[3].location)));
    ElementPtr comment(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    user_context->set("comment", comment);

    // Handle already existing user context
    ConstElementPtr old = parent->get("user-context");
    if (old) {
        // Check for duplicate comment
        if (old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context/comment entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the user context in the comment
        merge(user_context, old);
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 3093 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 554:
#line 1984 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("pd-pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pd-pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.PD_POOLS);
}
#line 3105 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 555:
#line 1990 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3114 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 560:
#line 2005 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3124 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 561:
#line 2009 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The prefix, prefix len and delegated len parameters are required.
    ctx.require("prefix", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("prefix-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("delegated-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3136 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 562:
#line 2017 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the pd-pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3146 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 563:
#line 2021 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The prefix, prefix len and delegated len parameters are required.
    ctx.require("prefix", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("prefix-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("delegated-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3158 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 577:
#line 2046 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3167 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 578:
#line 2049 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefix", prf);
    ctx.leave();
}
#line 3177 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 579:
#line 2055 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("prefix-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefix-len", prf);
}
#line 3187 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 580:
#line 2061 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("excluded-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3196 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 581:
#line 2064 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("excluded-prefix", prf);
    ctx.leave();
}
#line 3206 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 582:
#line 2070 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("excluded-prefix-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("excluded-prefix-len", prf);
}
#line 3216 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 583:
#line 2076 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("delegated-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr deleg(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("delegated-len", deleg);
}
#line 3226 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 584:
#line 2085 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("reservations", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.RESERVATIONS);
}
#line 3238 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 585:
#line 2091 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3247 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 590:
#line 2104 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3257 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 591:
#line 2108 "dhcp6_parser.yy" // lalr1.cc:919
    {
    /// @todo: an identifier parameter is required.
    ctx.stack_.pop_back();
}
#line 3266 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 592:
#line 2113 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the reservations list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3276 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 593:
#line 2117 "dhcp6_parser.yy" // lalr1.cc:919
    {
    /// @todo: an identifier parameter is required.
    // parsing completed
}
#line 3285 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 609:
#line 2144 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ip-addresses", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-addresses", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3297 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 610:
#line 2150 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3306 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 611:
#line 2155 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("prefixes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefixes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3318 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 612:
#line 2161 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3327 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 613:
#line 2166 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("duid", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3336 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 614:
#line 2169 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr d(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("duid", d);
    ctx.leave();
}
#line 3346 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 615:
#line 2175 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hw-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3355 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 616:
#line 2178 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hw-address", hw);
    ctx.leave();
}
#line 3365 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 617:
#line 2184 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3374 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 618:
#line 2187 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr host(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", host);
    ctx.leave();
}
#line 3384 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 619:
#line 2193 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("flex-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3393 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 620:
#line 2196 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flex-id", hw);
    ctx.leave();
}
#line 3403 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 621:
#line 2202 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3415 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 622:
#line 2208 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3424 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 623:
#line 2216 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("relay", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.RELAY);
}
#line 3436 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 624:
#line 2222 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3445 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 627:
#line 2231 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3454 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 628:
#line 2234 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr addr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", addr);
    ctx.leave();
}
#line 3464 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 629:
#line 2243 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CLIENT_CLASSES);
}
#line 3476 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 630:
#line 2249 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3485 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 633:
#line 2258 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3495 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 634:
#line 2262 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The name client class parameter is required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3505 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 653:
#line 2293 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3514 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 654:
#line 2296 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("test", test);
    ctx.leave();
}
#line 3524 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 655:
#line 2302 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("only-if-required", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("only-if-required", b);
}
#line 3534 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 656:
#line 2311 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("server-id", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-id", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SERVER_ID);
}
#line 3546 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 657:
#line 2317 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The type parameter is required.
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3557 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 669:
#line 2339 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DUID_TYPE);
}
#line 3566 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 670:
#line 2342 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 3575 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 671:
#line 2347 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("LLT", ctx.loc2pos(yystack_[0].location))); }
#line 3581 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 672:
#line 2348 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("EN", ctx.loc2pos(yystack_[0].location))); }
#line 3587 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 673:
#line 2349 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("LL", ctx.loc2pos(yystack_[0].location))); }
#line 3593 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 674:
#line 2352 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("htype", ctx.loc2pos(yystack_[2].location));
    ElementPtr htype(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("htype", htype);
}
#line 3603 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 675:
#line 2358 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("identifier", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3612 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 676:
#line 2361 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr id(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("identifier", id);
    ctx.leave();
}
#line 3622 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 677:
#line 2367 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("time", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("time", time);
}
#line 3632 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 678:
#line 2373 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("enterprise-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enterprise-id", time);
}
#line 3642 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 679:
#line 2381 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("dhcp4o6-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp4o6-port", time);
}
#line 3652 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 680:
#line 2389 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 3664 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 681:
#line 2395 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3673 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 689:
#line 2411 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3682 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 690:
#line 2414 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 3692 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 691:
#line 2420 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3701 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 692:
#line 2423 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 3711 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 693:
#line 2432 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("dhcp-queue-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr qc(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-queue-control", qc);
    ctx.stack_.push_back(qc);
    ctx.enter(ctx.DHCP_QUEUE_CONTROL);
}
#line 3723 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 694:
#line 2438 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The enable queue parameter is required.
    ctx.require("enable-queue", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3734 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 703:
#line 2457 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("enable-queue", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-queue", b);
}
#line 3744 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 704:
#line 2463 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("queue-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3753 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 705:
#line 2466 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr qt(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("queue-type", qt);
    ctx.leave();
}
#line 3763 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 706:
#line 2472 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("capacity", ctx.loc2pos(yystack_[2].location));
    ElementPtr c(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("capacity", c);
}
#line 3773 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 707:
#line 2478 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3782 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 708:
#line 2481 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set(yystack_[3].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 3791 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 709:
#line 2488 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("dhcp-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP_DDNS);
}
#line 3803 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 710:
#line 2494 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3814 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 711:
#line 2501 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the dhcp-ddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3824 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 712:
#line 2505 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3834 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 733:
#line 2535 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("enable-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-updates", b);
}
#line 3844 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 734:
#line 2542 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3853 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 735:
#line 2545 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("qualifying-suffix", s);
    ctx.leave();
}
#line 3863 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 736:
#line 2551 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("server-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3872 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 737:
#line 2554 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-ip", s);
    ctx.leave();
}
#line 3882 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 738:
#line 2560 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("server-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-port", i);
}
#line 3892 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 739:
#line 2566 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("sender-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3901 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 740:
#line 2569 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-ip", s);
    ctx.leave();
}
#line 3911 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 741:
#line 2575 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("sender-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-port", i);
}
#line 3921 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 742:
#line 2581 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("max-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-queue-size", i);
}
#line 3931 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 743:
#line 2587 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 3940 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 744:
#line 2590 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 3949 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 745:
#line 2596 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 3955 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 746:
#line 2597 "dhcp6_parser.yy" // lalr1.cc:919
    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 3961 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 747:
#line 2600 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 3970 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 748:
#line 2603 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 3980 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 749:
#line 2610 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-no-update", b);
}
#line 3990 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 750:
#line 2617 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-client-update", b);
}
#line 4000 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 751:
#line 2624 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 4009 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 752:
#line 2627 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.back()->set("replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4018 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 753:
#line 2633 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4027 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 754:
#line 2636 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("generated-prefix", s);
    ctx.leave();
}
#line 4037 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 755:
#line 2643 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4046 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 756:
#line 2646 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 4056 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 757:
#line 2653 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4065 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 758:
#line 2656 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 4075 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 759:
#line 2665 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("config-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-control", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.CONFIG_CONTROL);
}
#line 4087 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 760:
#line 2671 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No config control params are required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4097 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 761:
#line 2677 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // Parse the config-control map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4107 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 762:
#line 2681 "dhcp6_parser.yy" // lalr1.cc:919
    {
    // No config_control params are required
    // parsing completed
}
#line 4116 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 767:
#line 2696 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("config-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CONFIG_DATABASE);
}
#line 4128 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 768:
#line 2702 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4137 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 769:
#line 2707 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("config-fetch-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-fetch-wait-time", value);
}
#line 4147 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 770:
#line 2715 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 4159 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 771:
#line 2721 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4168 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 774:
#line 2733 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 4178 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 775:
#line 2737 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
}
#line 4186 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 785:
#line 2754 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 4196 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 786:
#line 2760 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4205 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 787:
#line 2763 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 4215 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 788:
#line 2769 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 4227 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 789:
#line 2775 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4236 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 792:
#line 2784 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 4246 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 793:
#line 2788 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
}
#line 4254 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 801:
#line 2803 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4263 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 802:
#line 2806 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 4273 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 803:
#line 2812 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 4283 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 804:
#line 2818 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 4293 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 805:
#line 2824 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 4303 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 806:
#line 2830 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4312 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 807:
#line 2833 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 4322 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 808:
#line 2839 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("compatibility", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("compatibility", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.COMPATIBILITY);
}
#line 4334 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 809:
#line 2845 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4343 "dhcp6_parser.cc" // lalr1.cc:919
    break;

  case 814:
#line 2858 "dhcp6_parser.yy" // lalr1.cc:919
    {
    ctx.unique("lenient-option-parsing", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lenient-option-parsing", b);
}
#line 4353 "dhcp6_parser.cc" // lalr1.cc:919
    break;


#line 4357 "dhcp6_parser.cc" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Dhcp6Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Dhcp6Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Dhcp6Parser::yypact_ninf_ = -983;

  const signed char Dhcp6Parser::yytable_ninf_ = -1;

  const short
  Dhcp6Parser::yypact_[] =
  {
     421,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,    48,    30,    31,    47,    58,
     129,   137,   158,   172,   225,   251,   253,   285,   288,   295,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,    30,  -141,
      91,   141,    24,   645,   183,   215,   252,   102,    87,   304,
     -79,   433,   208,  -983,   110,   296,   323,   321,   327,  -983,
     325,  -983,  -983,  -983,  -983,  -983,  -983,   358,   365,   376,
     414,   418,   419,   422,   427,   428,   429,   430,   431,   432,
     434,  -983,   435,   438,   439,   440,   441,  -983,  -983,  -983,
     442,   446,   447,  -983,  -983,  -983,   448,  -983,  -983,  -983,
    -983,   450,   451,   454,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   455,  -983,  -983,  -983,  -983,  -983,  -983,
     456,  -983,  -983,   458,  -983,    78,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
     460,  -983,    94,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   462,   464,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   123,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,   130,  -983,
    -983,  -983,  -983,  -983,   465,  -983,   466,   467,  -983,  -983,
    -983,  -983,  -983,  -983,   143,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,   351,   406,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,   353,  -983,  -983,   470,  -983,  -983,  -983,   471,
    -983,  -983,   477,   483,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   485,   486,  -983,
    -983,  -983,  -983,   479,   488,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   160,  -983,  -983,
    -983,   491,  -983,  -983,   493,  -983,   496,   497,  -983,  -983,
     498,   499,  -983,  -983,  -983,  -983,  -983,  -983,  -983,   166,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   500,   170,  -983,
    -983,  -983,  -983,    30,    30,  -983,   298,   501,  -983,   505,
     506,   507,   510,   513,   514,   311,   313,   315,   324,   326,
     328,   329,   330,   331,   322,   333,   336,   338,   340,   531,
     342,   343,   344,   346,   347,   533,   550,   551,   349,   354,
     356,   561,   565,   567,   362,   569,   571,   572,   575,   369,
     370,   371,   581,   583,   584,   585,   586,   588,   603,   604,
     605,   401,   606,   608,   609,   627,   628,   630,   423,   632,
     633,  -983,   141,  -983,   634,   436,    24,  -983,   635,   636,
     637,   639,   640,   437,   443,   641,   642,   646,   645,  -983,
     647,   183,  -983,   648,   444,   649,   449,   452,   215,  -983,
     652,   653,   654,   656,   657,   659,   660,  -983,   252,  -983,
     661,   665,   461,   668,   669,   671,   468,  -983,    87,   672,
     469,   475,  -983,   304,   673,   674,    23,  -983,   476,   675,
     685,   481,   702,   509,   512,   703,   704,   508,   511,   705,
     720,   726,   727,   433,  -983,   728,   524,   208,  -983,  -983,
    -983,   733,   729,   529,   742,   743,   744,   745,   734,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   547,  -983,  -983,  -983,  -983,  -983,  -122,
     548,   549,  -983,  -983,  -983,   735,   754,   755,  -983,   756,
     757,   554,   266,  -983,  -983,  -983,   762,   763,   764,   765,
     766,   769,   770,   771,   772,  -983,   786,   787,   788,   789,
     568,   598,  -983,   805,   804,  -983,   807,  -983,  -983,   808,
     809,   607,   610,   611,  -983,  -983,   807,   612,   810,  -983,
     613,  -983,   614,  -983,   615,  -983,  -983,  -983,   807,   807,
     807,   616,   621,   624,   629,  -983,   638,   644,  -983,   650,
     655,   658,  -983,  -983,   662,  -983,  -983,  -983,   663,   757,
    -983,  -983,   664,   666,  -983,   667,  -983,  -983,   103,   594,
    -983,  -983,  -122,   670,   676,   677,  -983,   813,  -983,  -983,
      30,   141,  -983,   208,    24,   310,   310,   829,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   830,   832,   836,
     837,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,   -92,
      30,   292,   700,   838,   839,   841,   148,    79,   -47,    27,
      61,   433,  -983,  -983,   843,  -158,  -983,  -983,   844,   848,
    -983,  -983,  -983,  -983,  -983,   -46,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,   829,  -983,   177,   226,   227,
    -983,  -983,  -983,  -983,   852,   853,   854,   857,   858,  -983,
     859,   861,  -983,  -983,  -983,  -983,   862,   864,   865,   866,
    -983,   240,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,   265,  -983,   868,   773,  -983,  -983,
     871,   875,  -983,  -983,   874,   878,  -983,  -983,   876,   880,
    -983,  -983,   881,   885,  -983,  -983,  -983,    81,  -983,  -983,
    -983,   883,  -983,  -983,  -983,    85,  -983,  -983,  -983,  -983,
     290,  -983,  -983,  -983,   109,  -983,  -983,   884,   888,  -983,
    -983,   886,   890,  -983,   891,   892,   893,   894,   895,   896,
     312,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
     897,   898,   899,  -983,  -983,  -983,  -983,   318,  -983,  -983,
    -983,  -983,  -983,  -983,   900,   901,   902,  -983,   355,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
     357,  -983,  -983,  -983,   903,  -983,   904,  -983,  -983,  -983,
     386,  -983,  -983,  -983,  -983,  -983,   387,  -983,   131,  -983,
     905,  -983,   388,  -983,  -983,   701,  -983,   906,   908,  -983,
    -983,   909,   913,  -983,  -983,  -983,   910,  -983,   911,  -983,
    -983,  -983,   915,   916,   917,   918,   684,   711,   714,   713,
     716,   924,   719,   721,   928,   930,   931,   938,   741,   747,
     746,   750,   310,  -983,  -983,   310,  -983,   829,   645,  -983,
     830,    87,  -983,   832,   304,  -983,   836,   732,  -983,   837,
     -92,  -983,  -983,   292,  -983,   940,   700,  -983,    22,   838,
    -983,   252,  -983,   839,   -79,  -983,   841,   751,   778,   791,
     795,   797,   798,   148,  -983,   941,   950,   806,   811,   814,
      79,  -983,   753,   819,   855,   -47,  -983,   978,   979,    27,
    -983,   785,   994,   873,  1016,    61,  -983,  -983,   179,   843,
    -983,   860,  -158,  -983,  -983,  1036,  1046,   183,  -983,   844,
     215,  -983,   848,  1071,  -983,  -983,   405,   869,   872,   877,
    -983,  -983,  -983,  -983,  -983,   879,  -983,  -983,   207,   882,
     887,   889,  -983,  -983,  -983,  -983,  -983,   390,  -983,   394,
    -983,  1076,  -983,  1077,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,   396,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
     907,  -983,  -983,  1083,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  1081,  1087,  -983,  -983,  -983,
    -983,  -983,  1084,  -983,   400,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,    45,   912,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   914,   919,  -983,  -983,   920,  -983,    30,
    -983,  -983,  1089,  -983,  -983,  -983,  -983,  -983,   402,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   921,   403,  -983,
     404,  -983,   922,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   732,  -983,  -983,  1090,   923,  -983,    22,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  1091,   926,  1093,   179,  -983,  -983,  -983,  -983,  -983,
    -983,   925,  -983,  -983,  1094,  -983,   929,  -983,  -983,  1095,
    -983,  -983,   263,  -983,   127,  1095,  -983,  -983,  1096,  1097,
    1099,  -983,   412,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    1100,   927,   934,   936,  1101,   127,  -983,   932,  -983,  -983,
    -983,   939,  -983,  -983,  -983
  };

  const unsigned short
  Dhcp6Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    45,    38,    34,    33,    30,    31,    32,    37,     3,
      35,    36,    58,     5,    62,     7,   174,     9,   342,    11,
     537,    13,   562,    15,   592,    17,   462,    19,   470,    21,
     507,    23,   307,    25,   711,    27,   761,    29,    47,    41,
       0,     0,     0,     0,     0,     0,   594,     0,   472,   509,
       0,     0,     0,    49,     0,    48,     0,     0,    42,    60,
       0,   129,   759,   172,   186,   188,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,   148,   155,   157,
       0,     0,     0,   334,   460,   499,     0,   410,   550,   552,
     402,     0,     0,     0,   267,   284,   275,   260,   629,   584,
     299,   318,   656,     0,   286,   680,   693,   709,   161,   163,
       0,   770,   808,     0,   128,     0,    64,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   105,   106,   107,   108,
     109,    75,   113,   114,   115,   116,   117,   118,   119,   120,
     111,   112,   121,   122,   123,   100,   127,   125,    78,    79,
      80,    81,    97,    82,    84,    83,   124,    88,    89,    76,
     102,   103,   104,   101,    77,    86,    87,    95,    96,    98,
      85,    90,    91,    92,    93,    94,    99,   110,   126,   183,
       0,   182,     0,   176,   178,   179,   180,   181,   529,   554,
     389,   391,   393,     0,     0,   397,   395,   623,   388,   346,
     347,   348,   349,   350,   351,   352,   353,   372,   373,   374,
     375,   376,   379,   380,   381,   382,   383,   384,   385,   386,
     377,   378,   387,     0,   344,   357,   358,   359,   362,   363,
     366,   367,   368,   365,   360,   361,   354,   355,   370,   371,
     356,   364,   369,   548,   547,   543,   544,   542,     0,   539,
     541,   545,   546,   577,     0,   580,     0,     0,   576,   570,
     571,   569,   574,   575,     0,   564,   566,   567,   572,   573,
     568,   621,   609,   611,   613,   615,   617,   619,   608,   605,
     606,   607,     0,   595,   596,   600,   601,   598,   602,   603,
     604,   599,     0,   489,   235,     0,   493,   491,   496,     0,
     485,   486,     0,   473,   474,   476,   488,   477,   478,   479,
     495,   480,   481,   482,   483,   484,   523,     0,     0,   521,
     522,   525,   526,     0,   510,   511,   513,   514,   515,   516,
     517,   518,   519,   520,   314,   316,   311,     0,   309,   312,
     313,     0,   734,   736,     0,   739,     0,     0,   743,   747,
       0,     0,   751,   753,   755,   757,   732,   730,   731,     0,
     713,   715,   727,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   728,   729,   767,     0,     0,   763,
     765,   766,    46,     0,     0,    39,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    63,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   343,
       0,     0,   538,     0,     0,     0,     0,     0,     0,   563,
       0,     0,     0,     0,     0,     0,     0,   593,     0,   463,
       0,     0,     0,     0,     0,     0,     0,   471,     0,     0,
       0,     0,   508,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   712,     0,     0,     0,   762,    50,
      43,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,     0,   166,   167,   145,   146,   147,     0,
       0,     0,   159,   160,   165,     0,     0,     0,   170,     0,
       0,     0,     0,   399,   400,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   679,     0,     0,     0,     0,
       0,     0,   171,     0,     0,    65,     0,   185,   177,     0,
       0,     0,     0,     0,   408,   409,     0,     0,     0,   345,
       0,   540,     0,   579,     0,   582,   583,   565,     0,     0,
       0,     0,     0,     0,     0,   597,     0,     0,   487,     0,
       0,     0,   498,   475,     0,   527,   528,   512,     0,     0,
     310,   733,     0,     0,   738,     0,   741,   742,     0,     0,
     749,   750,     0,     0,     0,     0,   714,     0,   769,   764,
       0,     0,   130,     0,     0,     0,     0,   192,   169,   150,
     151,   152,   153,   154,   149,   156,   158,   336,   464,   501,
     412,    40,   551,   553,   404,   405,   406,   407,   403,     0,
      47,     0,     0,     0,   586,   301,     0,     0,     0,     0,
       0,     0,   162,   164,     0,     0,    51,   184,   531,   556,
     390,   392,   394,   398,   396,     0,   549,   578,   581,   622,
     610,   612,   614,   616,   618,   620,   490,   236,   494,   492,
     497,   524,   315,   317,   735,   737,   740,   745,   746,   744,
     748,   752,   754,   756,   758,   192,    44,     0,     0,     0,
     222,   228,   230,   232,     0,     0,     0,     0,     0,   251,
       0,     0,   242,   254,   256,   258,     0,     0,     0,     0,
     221,     0,   198,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   212,   213,   220,   214,   215,   216,   210,
     211,   217,   218,   219,     0,   196,     0,   193,   194,   340,
       0,   337,   338,   468,     0,   465,   466,   505,     0,   502,
     503,   416,     0,   413,   414,   273,   274,     0,   269,   271,
     272,     0,   282,   283,   279,     0,   277,   280,   281,   265,
       0,   262,   264,   633,     0,   631,   590,     0,   587,   588,
     305,     0,   302,   303,     0,     0,     0,     0,     0,     0,
       0,   320,   322,   323,   324,   325,   326,   327,   669,   675,
       0,     0,     0,   668,   665,   666,   667,     0,   658,   660,
     663,   661,   662,   664,     0,     0,     0,   295,     0,   288,
     290,   291,   292,   293,   294,   689,   691,   688,   686,   687,
       0,   682,   684,   685,     0,   704,     0,   707,   700,   701,
       0,   695,   697,   698,   699,   702,     0,   774,     0,   772,
       0,   813,     0,   810,   812,    53,   535,     0,   532,   533,
     560,     0,   557,   558,   627,   626,     0,   625,     0,    61,
     760,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   189,     0,   191,     0,     0,   335,
       0,   472,   461,     0,   509,   500,     0,     0,   411,     0,
       0,   268,   285,     0,   276,     0,     0,   261,   635,     0,
     630,   594,   585,     0,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,     0,     0,     0,
       0,   657,     0,     0,     0,     0,   287,     0,     0,     0,
     681,     0,     0,     0,     0,     0,   694,   710,     0,     0,
     771,     0,     0,   809,    55,     0,    54,     0,   530,     0,
       0,   555,     0,     0,   624,   768,     0,     0,     0,     0,
     234,   237,   238,   239,   240,     0,   253,   241,     0,     0,
       0,     0,   248,   249,   250,   247,   199,     0,   195,     0,
     339,     0,   467,     0,   504,   459,   434,   435,   436,   438,
     439,   440,   424,   425,   443,   444,   445,   446,   447,   450,
     451,   452,   453,   454,   455,   456,   457,   448,   449,   458,
     420,   421,   422,   423,   432,   433,   429,   430,   431,   428,
     437,     0,   418,   426,   441,   442,   427,   415,   270,   278,
       0,   263,   653,     0,   651,   645,   646,   647,   648,   649,
     650,   652,   642,   643,   644,     0,   636,   637,   639,   640,
     641,   632,     0,   589,     0,   304,   328,   329,   330,   331,
     332,   333,   321,     0,     0,   674,   677,   678,   659,   296,
     297,   298,   289,     0,     0,   683,   703,     0,   706,     0,
     696,   788,     0,   786,   784,   778,   782,   783,     0,   776,
     780,   781,   779,   773,   814,   811,    52,     0,     0,   534,
       0,   559,     0,   224,   225,   226,   227,   223,   229,   231,
     233,   252,   244,   245,   246,   243,   255,   257,   259,   197,
     341,   469,   506,     0,   417,   266,     0,     0,   634,     0,
     591,   306,   671,   672,   673,   670,   676,   690,   692,   705,
     708,     0,     0,     0,     0,   775,    56,   536,   561,   628,
     419,     0,   655,   638,     0,   785,     0,   777,   654,     0,
     787,   792,     0,   790,     0,     0,   789,   801,     0,     0,
       0,   806,     0,   794,   796,   797,   798,   799,   800,   791,
       0,     0,     0,     0,     0,     0,   793,     0,   803,   804,
     805,     0,   795,   802,   807
  };

  const short
  Dhcp6Parser::yypgoto_[] =
  {
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,   -10,  -983,  -566,  -983,
     205,  -983,  -983,  -983,  -983,   377,  -983,  -564,  -983,  -983,
    -983,   -71,  -983,  -983,  -983,  -983,  -983,  -983,   407,   617,
    -983,  -983,   -43,   -14,    12,    16,    20,    33,   -59,   -31,
     -30,   -28,   -27,   -26,    19,  -983,    34,    37,    38,    41,
    -983,   420,    49,  -983,    52,  -983,    54,    55,    56,  -983,
      59,  -983,    62,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   409,   618,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,   332,  -983,   113,  -983,  -690,   114,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
     -45,  -983,  -726,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,    95,  -983,  -983,  -983,
    -983,  -983,   105,  -709,  -983,  -983,  -983,  -983,   106,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,    77,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,    92,  -983,  -983,  -983,    96,   578,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,    93,  -983,  -983,
    -983,  -983,  -983,  -983,  -982,  -983,  -983,  -983,   125,  -983,
    -983,  -983,   134,   619,  -983,  -983,  -980,  -983,  -979,  -983,
      73,  -983,    75,  -983,    66,    69,    70,    72,  -983,  -983,
    -983,  -978,  -983,  -983,  -983,  -983,   124,  -983,  -983,  -106,
    1070,  -983,  -983,  -983,  -983,  -983,   146,  -983,  -983,  -983,
     149,  -983,   620,  -983,   -67,  -983,  -983,  -983,  -983,  -983,
     -64,  -983,  -983,  -983,  -983,  -983,     4,  -983,  -983,  -983,
     145,  -983,  -983,  -983,   150,  -983,   622,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,    83,  -983,
    -983,  -983,    86,   651,  -983,  -983,   -55,  -983,   -12,  -983,
    -983,  -983,  -983,  -983,    84,  -983,  -983,  -983,    89,   643,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   -60,  -983,  -983,
    -983,   132,  -983,  -983,  -983,   136,  -983,   679,   408,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -976,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
     147,  -983,  -983,  -983,   -89,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,   128,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,   115,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,   112,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,   445,   678,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,   472,   602,  -983,  -983,  -983,
    -983,  -983,  -983,   111,  -983,  -983,   -93,  -983,  -983,  -983,
    -983,  -983,  -983,  -112,  -983,  -983,  -131,  -983,  -983,  -983,
    -983,  -983,  -983,  -983,  -983,  -983,  -983,   117,  -983
  };

  const short
  Dhcp6Parser::yydefgoto_[] =
  {
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    83,    39,    40,    69,
     722,    87,    88,    41,    68,    84,    85,   747,   955,  1065,
    1066,   810,    43,    70,    90,   427,    45,    71,   155,   156,
     157,   429,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     455,   714,   176,   456,   177,   457,   178,   179,   180,   486,
     181,   487,   182,   183,   184,   185,   449,   186,   187,   188,
     431,    47,    72,   222,   223,   224,   494,   225,   189,   432,
     190,   433,   191,   434,   836,   837,   838,   995,   811,   812,
     813,   972,  1227,   814,   973,   815,   974,   816,   975,   817,
     818,   531,   819,   820,   821,   822,   823,   824,   984,  1235,
     825,   826,   827,   828,   829,   981,   830,   831,   985,   832,
     986,   833,   987,   192,   475,   870,   871,   872,  1015,   193,
     472,   857,   858,   859,   860,   194,   474,   865,   866,   867,
     868,   195,   473,   196,   482,   918,   919,   920,   921,   922,
     197,   478,   881,   882,   883,  1024,    63,    80,   377,   378,
     379,   544,   380,   545,   198,   479,   890,   891,   892,   893,
     894,   895,   896,   897,   199,   461,   840,   841,   842,   998,
      49,    73,   263,   264,   265,   500,   266,   501,   267,   502,
     268,   506,   269,   505,   200,   201,   202,   203,   468,   728,
     274,   275,   204,   465,   852,   853,   854,  1007,  1141,  1142,
     205,   462,    57,    77,   844,   845,   846,  1001,    59,    78,
     342,   343,   344,   345,   346,   347,   348,   530,   349,   534,
     350,   533,   351,   352,   535,   353,   206,   463,   848,   849,
     850,  1004,    61,    79,   363,   364,   365,   366,   367,   539,
     368,   369,   370,   371,   277,   498,   957,   958,   959,  1067,
      51,    74,   288,   289,   290,   510,   207,   466,   208,   467,
     280,   499,   961,   962,   963,  1070,    53,    75,   304,   305,
     306,   513,   307,   308,   515,   309,   310,   209,   477,   877,
     878,   879,  1021,    55,    76,   322,   323,   324,   325,   521,
     326,   522,   327,   523,   328,   524,   329,   525,   330,   526,
     331,   520,   282,   507,   966,   967,  1073,   210,   476,   874,
     875,  1018,  1165,  1166,  1167,  1168,  1169,  1246,  1170,   211,
     480,   907,   908,   909,  1035,  1255,   910,   911,  1036,   912,
     913,   212,   213,   483,   930,   931,   932,  1047,   933,  1048,
     214,   484,   940,   941,   942,   943,  1052,   944,   945,  1054,
     215,   485,    65,    81,   399,   400,   401,   402,   549,   403,
     550,   404,   405,   552,   406,   407,   408,   555,   779,   409,
     556,   410,   411,   412,   559,   413,   560,   414,   561,   415,
     562,   216,   430,    67,    82,   418,   419,   420,   565,   421,
     217,   489,   948,   949,  1058,  1208,  1209,  1210,  1211,  1263,
    1212,  1261,  1282,  1283,  1284,  1292,  1293,  1294,  1300,  1295,
    1296,  1297,  1298,  1304,   218,   490,   952,   953,   954
  };

  const unsigned short
  Dhcp6Parser::yytable_[] =
  {
     154,   221,   238,   284,   298,   318,    38,   340,   359,   376,
     396,   904,   361,   281,   245,   362,   834,   226,   278,   291,
     302,   320,   864,   354,   372,  1131,   397,  1132,  1133,  1140,
     239,  1146,   855,   341,   360,    31,   950,    32,    42,    33,
     219,   220,   246,   247,   721,   248,   249,   250,    30,   128,
     129,   153,   374,   375,    44,   709,   710,   711,   712,   240,
     227,   279,   292,   303,   321,    46,   355,   373,    86,   398,
      97,    98,    99,   100,   101,   102,   312,   276,   287,   301,
     319,   492,   753,   964,  1010,   241,   493,  1011,  1013,   242,
     713,  1014,   251,   243,   759,   760,   761,   496,   125,   334,
     898,    89,   497,   914,   915,   916,   244,   252,   333,   795,
     253,   254,  1019,   721,   255,  1020,   422,   856,   128,   129,
     128,   129,   256,   128,   129,   257,   508,   258,   259,   260,
     153,   509,   261,   511,  1059,   262,    48,  1060,   512,   270,
    1152,  1153,   271,   272,    50,   273,   518,   285,   299,   286,
     300,   519,    91,    92,   374,   375,    93,   128,   129,    94,
      95,    96,   153,   546,   334,    52,   335,   336,   547,   563,
     337,   338,   339,   567,   564,   128,   129,   124,   568,    54,
     492,   925,   926,   128,   129,   969,  1252,  1253,  1254,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   934,   935,
     936,   416,   417,   899,   900,   901,   902,   126,   127,   567,
     496,   153,    56,   153,   970,   971,   153,   128,   129,    34,
      35,    36,    37,   992,   130,  1232,  1233,  1234,   993,   131,
     132,   133,   134,   135,   136,   137,   334,   138,    58,   125,
      60,  1131,   139,  1132,  1133,  1140,  1285,  1146,   992,  1286,
     937,   140,   283,   994,   141,   128,   129,   777,   778,   128,
     129,   142,   884,   885,   886,   887,   888,   889,   153,   143,
     144,   125,    62,  1016,   145,    64,   153,   146,  1017,   423,
     235,   147,    66,   236,   864,  1097,   293,   294,   295,   296,
     297,   128,   129,  1287,   904,  1033,  1288,  1289,  1290,  1291,
    1034,  1040,   148,   149,   150,   151,  1041,   424,   125,   425,
     426,   790,   235,   428,   152,   236,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   128,   129,
     153,   803,   804,   805,   806,   807,   808,   809,  1045,   527,
    1049,   529,   435,  1046,  1201,  1050,  1202,  1203,   311,   436,
     724,   725,   726,   727,   312,   313,   314,   315,   316,   317,
     437,   334,   356,   335,   336,   357,   358,   334,   153,  1055,
     563,  1062,   153,   992,  1056,  1057,  1063,   508,  1239,  1243,
     128,   129,  1240,   546,  1244,  1264,   511,   518,  1251,   528,
    1265,  1267,  1268,   569,   570,  1305,   855,   862,   438,   863,
    1306,   154,   439,   440,   153,   221,   441,  1223,  1224,  1225,
    1226,   442,   443,   444,   445,   446,   447,   238,   448,   450,
     284,   226,   451,   452,   453,   454,   458,   298,   281,   245,
     459,   460,   464,   278,   469,   470,   291,   318,   471,   481,
     488,   153,   491,   302,   495,   239,   503,   340,   504,   514,
     516,   517,   359,   320,   532,   536,   361,   246,   247,   362,
     248,   249,   250,   354,   227,   537,   538,   542,   372,   540,
     541,   543,   396,   341,   240,   548,   279,   551,   360,   292,
     553,   554,   557,   558,   566,   572,   303,   571,   397,   573,
     574,   575,   276,   153,   576,   287,   321,   577,   578,   153,
     241,   579,   301,   580,   242,   581,   355,   251,   243,   128,
     129,   373,   319,   588,   582,   593,   583,   599,   584,   585,
     586,   244,   252,   587,   589,   253,   254,   590,   591,   255,
     592,   398,   594,   595,   600,   601,   596,   256,   597,   598,
     257,   602,   258,   259,   260,   605,   603,   261,   604,   606,
     262,   607,   608,   609,   270,   610,   611,   271,   272,   612,
     273,   613,   614,   615,   285,   616,   286,   617,   618,   619,
     620,   299,   621,   300,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   622,   623,   624,
     626,   625,   627,   628,   394,   395,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     154,   629,   630,   221,   631,   632,   633,   634,   636,   639,
     640,   641,   153,   642,   643,   646,   647,   644,   637,   226,
     648,   650,   652,   654,   653,   645,   658,   659,   660,   655,
     661,   662,   656,   663,   664,   666,   903,   917,   927,   667,
     396,   668,   669,   670,   951,   671,   674,   678,   679,   682,
     672,   675,   905,   923,   928,   938,   397,   676,   681,   683,
     786,   684,   227,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   685,   688,   689,   692,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   686,
     690,   125,   687,   691,   693,   906,   924,   929,   939,   398,
     694,   695,   697,   228,   698,   229,   701,   700,   702,   707,
     717,   128,   129,   230,   231,   232,   233,   234,   130,   703,
     704,   705,   706,   131,   132,   133,   708,   715,   716,   718,
     719,   720,   235,   723,    32,   236,   139,   729,   730,   731,
     780,   733,   732,   237,   734,   735,   997,   742,   736,   737,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   738,   739,   740,   741,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   743,   125,   334,
     744,   745,   746,   748,   749,   869,   750,   755,   785,   751,
     752,   754,   756,   757,   758,   762,   148,   149,   128,   129,
     763,   231,   232,   764,   234,   130,   835,   839,   765,   843,
     131,   132,   133,   847,   851,   873,   876,   766,   880,   235,
     947,   956,   236,   767,   153,   960,   976,   977,   978,   768,
     237,   979,   980,   982,   769,   983,   988,   770,   989,   990,
     991,   771,   772,   774,   996,   775,   776,   999,  1000,   782,
    1002,  1003,  1005,  1006,   773,   783,   784,  1008,  1009,  1012,
    1022,  1023,  1025,  1026,  1080,  1027,  1028,  1029,  1030,  1031,
    1032,  1037,  1038,  1039,  1042,  1043,  1044,  1051,  1053,  1061,
    1064,  1069,  1068,   148,   149,  1071,  1072,  1075,  1074,  1076,
    1077,  1078,  1079,  1081,  1082,  1083,  1084,   238,  1085,  1086,
     340,  1087,  1088,   359,  1089,  1090,  1105,   361,   281,   245,
     362,   153,  1091,   278,  1150,  1183,   354,  1154,  1112,   372,
     318,  1092,  1144,   376,  1184,   239,   341,  1093,  1094,   360,
    1095,  1176,  1130,  1163,  1106,  1189,   320,   246,   247,   903,
     248,   249,   250,  1161,   917,  1155,  1113,  1114,   927,  1115,
    1116,  1117,  1193,  1194,   240,   905,   279,  1204,  1177,   355,
     923,   951,   373,  1107,   928,  1145,   284,  1196,  1197,   298,
     938,  1178,   276,  1206,  1156,  1179,  1164,  1180,  1181,   321,
     241,  1143,   291,  1205,   242,   302,  1185,   251,   243,  1108,
    1199,  1186,  1162,  1109,  1187,   319,  1118,  1110,   906,  1190,
    1157,   244,   252,   924,  1158,   253,   254,   929,  1159,   255,
    1111,  1119,  1216,   939,  1120,  1121,  1207,   256,  1122,  1217,
     257,  1160,   258,   259,   260,   292,  1123,   261,   303,  1124,
     262,  1125,  1126,  1127,   270,  1191,  1128,   271,   272,  1129,
     273,   287,  1214,  1136,   301,  1222,  1137,  1138,  1228,  1139,
    1134,  1229,  1135,  1198,  1241,  1242,  1230,  1247,  1231,  1248,
    1249,  1236,  1250,  1262,  1271,  1274,  1237,  1276,  1238,  1279,
    1301,  1302,  1281,  1303,  1307,  1311,  1096,   861,   787,   635,
    1098,  1151,   781,   789,   638,  1148,  1245,   968,  1175,  1149,
    1174,  1256,  1192,  1257,   680,  1100,  1182,   649,  1258,  1259,
    1266,  1269,  1099,  1147,  1278,  1272,  1275,  1270,  1280,  1308,
     285,  1313,   286,   299,  1309,   300,  1310,   332,  1314,  1102,
    1101,  1104,  1219,  1218,  1103,  1173,  1221,  1172,   673,  1220,
    1273,   657,   651,   965,  1195,   677,  1171,  1200,  1188,   699,
    1213,  1277,  1105,  1299,  1312,   788,     0,     0,  1154,  1215,
       0,     0,     0,     0,  1112,     0,   946,     0,  1144,  1260,
       0,     0,     0,  1204,  1163,     0,     0,     0,  1130,     0,
    1106,     0,     0,     0,  1161,     0,  1155,   665,     0,  1206,
       0,     0,  1113,  1114,     0,  1115,  1116,  1117,     0,  1205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
       0,  1145,     0,     0,     0,  1156,     0,  1164,     0,     0,
       0,   696,     0,     0,     0,     0,     0,  1143,     0,     0,
       0,     0,  1207,  1162,     0,  1108,     0,     0,     0,  1109,
       0,  1157,  1118,  1110,     0,  1158,     0,     0,     0,  1159,
       0,     0,     0,     0,     0,     0,  1111,  1119,     0,     0,
    1120,  1121,  1160,     0,  1122,     0,     0,     0,     0,     0,
       0,     0,  1123,     0,     0,  1124,     0,  1125,  1126,  1127,
       0,     0,  1128,     0,     0,  1129,     0,     0,     0,  1136,
       0,     0,  1137,  1138,     0,  1139,  1134,     0,  1135
  };

  const short
  Dhcp6Parser::yycheck_[] =
  {
      71,    72,    73,    74,    75,    76,    16,    78,    79,    80,
      81,   737,    79,    73,    73,    79,   706,    72,    73,    74,
      75,    76,   731,    78,    79,  1007,    81,  1007,  1007,  1007,
      73,  1007,   124,    78,    79,     5,   194,     7,     7,     9,
      16,    17,    73,    73,   610,    73,    73,    73,     0,    96,
      97,   209,   131,   132,     7,   177,   178,   179,   180,    73,
      72,    73,    74,    75,    76,     7,    78,    79,   209,    81,
      48,    49,    50,    51,    52,    53,   122,    73,    74,    75,
      76,     3,   646,   129,     3,    73,     8,     6,     3,    73,
     212,     6,    73,    73,   658,   659,   660,     3,    76,    77,
      21,    10,     8,   150,   151,   152,    73,    73,    21,    30,
      73,    73,     3,   679,    73,     6,     6,   209,    96,    97,
      96,    97,    73,    96,    97,    73,     3,    73,    73,    73,
     209,     8,    73,     3,     3,    73,     7,     6,     8,    73,
     118,   119,    73,    73,     7,    73,     3,    74,    75,    74,
      75,     8,    11,    12,   131,   132,    15,    96,    97,    18,
      19,    20,   209,     3,    77,     7,    79,    80,     8,     3,
      83,    84,    85,     3,     8,    96,    97,    75,     8,     7,
       3,   154,   155,    96,    97,     8,   141,   142,   143,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   157,   158,
     159,    13,    14,   144,   145,   146,   147,    86,    87,     3,
       3,   209,     7,   209,     8,     8,   209,    96,    97,   209,
     210,   211,   212,     3,   103,    38,    39,    40,     8,   108,
     109,   110,   111,   112,   113,   114,    77,   116,     7,    76,
       7,  1243,   121,  1243,  1243,  1243,     3,  1243,     3,     6,
     209,   130,    89,     8,   133,    96,    97,   174,   175,    96,
      97,   140,   134,   135,   136,   137,   138,   139,   209,   148,
     149,    76,     7,     3,   153,     7,   209,   156,     8,     3,
     117,   160,     7,   120,  1013,   995,    91,    92,    93,    94,
      95,    96,    97,   186,  1040,     3,   189,   190,   191,   192,
       8,     3,   181,   182,   183,   184,     8,     4,    76,     8,
       3,    21,   117,     8,   193,   120,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    96,    97,
     209,    41,    42,    43,    44,    45,    46,    47,     3,     8,
       3,     8,     4,     8,   185,     8,   187,   188,   116,     4,
     104,   105,   106,   107,   122,   123,   124,   125,   126,   127,
       4,    77,    78,    79,    80,    81,    82,    77,   209,     3,
       3,     3,   209,     3,     8,     8,     8,     3,     8,     3,
      96,    97,     8,     3,     8,     3,     3,     3,     8,     3,
       8,     8,     8,   423,   424,     3,   124,   125,     4,   127,
       8,   492,     4,     4,   209,   496,     4,    22,    23,    24,
      25,     4,     4,     4,     4,     4,     4,   508,     4,     4,
     511,   496,     4,     4,     4,     4,     4,   518,   508,   508,
       4,     4,     4,   508,     4,     4,   511,   528,     4,     4,
       4,   209,     4,   518,     4,   508,     4,   538,     4,     4,
       4,     4,   543,   528,     4,     4,   543,   508,   508,   543,
     508,   508,   508,   538,   496,     8,     3,     8,   543,     4,
       4,     3,   563,   538,   508,     4,   508,     4,   543,   511,
       4,     4,     4,     4,     4,     4,   518,   209,   563,     4,
       4,     4,   508,   209,     4,   511,   528,     4,     4,   209,
     508,   210,   518,   210,   508,   210,   538,   508,   508,    96,
      97,   543,   528,   211,   210,     4,   210,     4,   210,   210,
     210,   508,   508,   212,   211,   508,   508,   211,   210,   508,
     210,   563,   210,   210,     4,     4,   212,   508,   212,   212,
     508,   212,   508,   508,   508,     4,   212,   508,   212,     4,
     508,     4,   210,     4,   508,     4,     4,   508,   508,     4,
     508,   212,   212,   212,   511,     4,   511,     4,     4,     4,
       4,   518,     4,   518,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     4,     4,     4,
       4,   210,     4,     4,   181,   182,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     701,     4,     4,   704,     4,   212,     4,     4,     4,     4,
       4,     4,   209,     4,     4,     4,     4,   210,   212,   704,
       4,     4,     4,     4,   210,   212,     4,     4,     4,   210,
       4,     4,   210,     4,     4,     4,   737,   738,   739,     4,
     741,   210,     4,     4,   745,     4,     4,     4,     4,     4,
     212,   212,   737,   738,   739,   740,   741,   212,   212,     4,
     700,   210,   704,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     4,     4,     4,     4,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   210,
     212,    76,   210,   212,     4,   737,   738,   739,   740,   741,
       4,     4,     4,    88,   210,    90,     7,     4,   209,     5,
       5,    96,    97,    98,    99,   100,   101,   102,   103,     7,
       7,     7,     7,   108,   109,   110,   209,   209,   209,     5,
       5,     5,   117,   209,     7,   120,   121,     5,     5,     5,
     176,     5,     7,   128,     5,     5,     3,   209,     7,     7,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,     7,     7,     7,     7,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   209,    76,    77,
       5,     7,     5,     5,     5,   115,   209,     7,     5,   209,
     209,   209,   209,   209,   209,   209,   181,   182,    96,    97,
     209,    99,   100,   209,   102,   103,     7,     7,   209,     7,
     108,   109,   110,     7,     7,     7,     7,   209,     7,   117,
       7,     7,   120,   209,   209,     7,     4,     4,     4,   209,
     128,     4,     4,     4,   209,     4,     4,   209,     4,     4,
       4,   209,   209,   209,     6,   209,   209,     6,     3,   209,
       6,     3,     6,     3,   679,   209,   209,     6,     3,     6,
       6,     3,     6,     3,   210,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     209,     3,     6,   181,   182,     6,     3,     6,     8,     4,
       4,     4,     4,   212,   210,   212,   210,   998,     4,   210,
    1001,   210,     4,  1004,     4,     4,  1007,  1004,   998,   998,
    1004,   209,     4,   998,     4,     4,  1001,  1018,  1007,  1004,
    1021,   210,  1007,  1024,     4,   998,  1001,   210,   212,  1004,
     210,   210,  1007,  1018,  1007,   212,  1021,   998,   998,  1040,
     998,   998,   998,  1018,  1045,  1018,  1007,  1007,  1049,  1007,
    1007,  1007,     4,     4,   998,  1040,   998,  1058,   210,  1001,
    1045,  1062,  1004,  1007,  1049,  1007,  1067,   212,     4,  1070,
    1055,   210,   998,  1058,  1018,   210,  1018,   210,   210,  1021,
     998,  1007,  1067,  1058,   998,  1070,   210,   998,   998,  1007,
       4,   210,  1018,  1007,   210,  1021,  1007,  1007,  1040,   210,
    1018,   998,   998,  1045,  1018,   998,   998,  1049,  1018,   998,
    1007,  1007,     6,  1055,  1007,  1007,  1058,   998,  1007,     3,
     998,  1018,   998,   998,   998,  1067,  1007,   998,  1070,  1007,
     998,  1007,  1007,  1007,   998,   210,  1007,   998,   998,  1007,
     998,  1067,   212,  1007,  1070,     4,  1007,  1007,   209,  1007,
    1007,   209,  1007,   210,     8,     8,   209,     4,   209,     8,
       3,   209,     8,     4,     4,     4,   209,     4,   209,     5,
       4,     4,     7,     4,     4,     4,   992,   730,   701,   492,
     997,  1016,   692,   704,   496,  1010,   209,   785,  1026,  1013,
    1024,   209,  1045,   209,   546,  1000,  1033,   508,   209,   209,
     209,   209,   998,  1009,   209,   212,   210,  1243,   209,   212,
    1067,   209,  1067,  1070,   210,  1070,   210,    77,   209,  1003,
    1001,  1006,  1069,  1067,  1004,  1023,  1072,  1021,   538,  1070,
    1249,   518,   511,   755,  1049,   543,  1019,  1055,  1040,   567,
    1059,  1264,  1243,  1285,  1305,   703,    -1,    -1,  1249,  1062,
      -1,    -1,    -1,    -1,  1243,    -1,   741,    -1,  1243,  1199,
      -1,    -1,    -1,  1264,  1249,    -1,    -1,    -1,  1243,    -1,
    1243,    -1,    -1,    -1,  1249,    -1,  1249,   528,    -1,  1264,
      -1,    -1,  1243,  1243,    -1,  1243,  1243,  1243,    -1,  1264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,
      -1,  1243,    -1,    -1,    -1,  1249,    -1,  1249,    -1,    -1,
      -1,   563,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,
      -1,    -1,  1264,  1249,    -1,  1243,    -1,    -1,    -1,  1243,
      -1,  1249,  1243,  1243,    -1,  1249,    -1,    -1,    -1,  1249,
      -1,    -1,    -1,    -1,    -1,    -1,  1243,  1243,    -1,    -1,
    1243,  1243,  1249,    -1,  1243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1243,    -1,    -1,  1243,    -1,  1243,  1243,  1243,
      -1,    -1,  1243,    -1,    -1,  1243,    -1,    -1,    -1,  1243,
      -1,    -1,  1243,  1243,    -1,  1243,  1243,    -1,  1243
  };

  const unsigned short
  Dhcp6Parser::yystos_[] =
  {
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,     5,     7,     9,   209,   210,   211,   212,   229,   230,
     231,   236,     7,   245,     7,   249,     7,   294,     7,   403,
       7,   483,     7,   499,     7,   516,     7,   435,     7,   441,
       7,   465,     7,   379,     7,   585,     7,   616,   237,   232,
     246,   250,   295,   404,   484,   500,   517,   436,   442,   466,
     380,   586,   617,   229,   238,   239,   209,   234,   235,    10,
     247,    11,    12,    15,    18,    19,    20,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    86,    87,    96,    97,
     103,   108,   109,   110,   111,   112,   113,   114,   116,   121,
     130,   133,   140,   148,   149,   153,   156,   160,   181,   182,
     183,   184,   193,   209,   244,   251,   252,   253,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   275,   277,   279,   280,
     281,   283,   285,   286,   287,   288,   290,   291,   292,   301,
     303,   305,   346,   352,   358,   364,   366,   373,   387,   397,
     417,   418,   419,   420,   425,   433,   459,   489,   491,   510,
     540,   552,   564,   565,   573,   583,   614,   623,   647,    16,
      17,   244,   296,   297,   298,   300,   489,   491,    88,    90,
      98,    99,   100,   101,   102,   117,   120,   128,   244,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   269,   270,   271,   272,   275,   277,   279,   280,
     281,   283,   285,   405,   406,   407,   409,   411,   413,   415,
     417,   418,   419,   420,   423,   424,   459,   477,   489,   491,
     493,   510,   535,    89,   244,   413,   415,   459,   485,   486,
     487,   489,   491,    91,    92,    93,    94,    95,   244,   413,
     415,   459,   489,   491,   501,   502,   503,   505,   506,   508,
     509,   116,   122,   123,   124,   125,   126,   127,   244,   459,
     489,   491,   518,   519,   520,   521,   523,   525,   527,   529,
     531,   533,   433,    21,    77,    79,    80,    83,    84,    85,
     244,   323,   443,   444,   445,   446,   447,   448,   449,   451,
     453,   455,   456,   458,   489,   491,    78,    81,    82,   244,
     323,   447,   453,   467,   468,   469,   470,   471,   473,   474,
     475,   476,   489,   491,   131,   132,   244,   381,   382,   383,
     385,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   181,   182,   244,   489,   491,   587,
     588,   589,   590,   592,   594,   595,   597,   598,   599,   602,
     604,   605,   606,   608,   610,   612,    13,    14,   618,   619,
     620,   622,     6,     3,     4,     8,     3,   248,     8,   254,
     615,   293,   302,   304,   306,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,   289,
       4,     4,     4,     4,     4,   273,   276,   278,     4,     4,
       4,   398,   434,   460,     4,   426,   490,   492,   421,     4,
       4,     4,   353,   365,   359,   347,   541,   511,   374,   388,
     553,     4,   367,   566,   574,   584,   282,   284,     4,   624,
     648,     4,     3,     8,   299,     4,     3,     8,   478,   494,
     408,   410,   412,     4,     4,   416,   414,   536,     3,     8,
     488,     3,     8,   504,     4,   507,     4,     4,     3,     8,
     534,   522,   524,   526,   528,   530,   532,     8,     3,     8,
     450,   324,     4,   454,   452,   457,     4,     8,     3,   472,
       4,     4,     8,     3,   384,   386,     3,     8,     4,   591,
     593,     4,   596,     4,     4,   600,   603,     4,     4,   607,
     609,   611,   613,     3,     8,   621,     4,     3,     8,   229,
     229,   209,     4,     4,     4,     4,     4,     4,     4,   210,
     210,   210,   210,   210,   210,   210,   210,   212,   211,   211,
     211,   210,   210,     4,   210,   210,   212,   212,   212,     4,
       4,     4,   212,   212,   212,     4,     4,     4,   210,     4,
       4,     4,     4,   212,   212,   212,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   210,     4,     4,     4,     4,
       4,     4,   212,     4,     4,   252,     4,   212,   297,     4,
       4,     4,     4,     4,   210,   212,     4,     4,     4,   406,
       4,   486,     4,   210,     4,   210,   210,   502,     4,     4,
       4,     4,     4,     4,     4,   520,     4,     4,   210,     4,
       4,     4,   212,   445,     4,   212,   212,   469,     4,     4,
     382,   212,     4,     4,   210,     4,   210,   210,     4,     4,
     212,   212,     4,     4,     4,     4,   588,     4,   210,   619,
       4,     7,   209,     7,     7,     7,     7,     5,   209,   177,
     178,   179,   180,   212,   274,   209,   209,     5,     5,     5,
       5,   231,   233,   209,   104,   105,   106,   107,   422,     5,
       5,     5,     7,     5,     5,     5,     7,     7,     7,     7,
       7,     7,   209,   209,     5,     7,     5,   240,     5,     5,
     209,   209,   209,   240,   209,     7,   209,   209,   209,   240,
     240,   240,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   233,   209,   209,   209,   174,   175,   601,
     176,   274,   209,   209,   209,     5,   229,   251,   618,   296,
      21,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    41,    42,    43,    44,    45,    46,    47,
     244,   311,   312,   313,   316,   318,   320,   322,   323,   325,
     326,   327,   328,   329,   330,   333,   334,   335,   336,   337,
     339,   340,   342,   344,   311,     7,   307,   308,   309,     7,
     399,   400,   401,     7,   437,   438,   439,     7,   461,   462,
     463,     7,   427,   428,   429,   124,   209,   354,   355,   356,
     357,   238,   125,   127,   356,   360,   361,   362,   363,   115,
     348,   349,   350,     7,   542,   543,     7,   512,   513,   514,
       7,   375,   376,   377,   134,   135,   136,   137,   138,   139,
     389,   390,   391,   392,   393,   394,   395,   396,    21,   144,
     145,   146,   147,   244,   325,   489,   491,   554,   555,   556,
     559,   560,   562,   563,   150,   151,   152,   244,   368,   369,
     370,   371,   372,   489,   491,   154,   155,   244,   489,   491,
     567,   568,   569,   571,   157,   158,   159,   209,   489,   491,
     575,   576,   577,   578,   580,   581,   587,     7,   625,   626,
     194,   244,   649,   650,   651,   241,     7,   479,   480,   481,
       7,   495,   496,   497,   129,   521,   537,   538,   307,     8,
       8,     8,   314,   317,   319,   321,     4,     4,     4,     4,
       4,   338,     4,     4,   331,   341,   343,   345,     4,     4,
       4,     4,     3,     8,     8,   310,     6,     3,   402,     6,
       3,   440,     6,     3,   464,     6,     3,   430,     6,     3,
       3,     6,     6,     3,     6,   351,     3,     8,   544,     3,
       6,   515,     6,     3,   378,     6,     3,     4,     4,     4,
       4,     4,     4,     3,     8,   557,   561,     4,     4,     4,
       3,     8,     4,     4,     4,     3,     8,   570,   572,     3,
       8,     4,   579,     4,   582,     3,     8,     8,   627,     3,
       6,     4,     3,     8,   209,   242,   243,   482,     6,     3,
     498,     6,     3,   539,     8,     6,     4,     4,     4,     4,
     210,   212,   210,   212,   210,     4,   210,   210,     4,     4,
       4,     4,   210,   210,   212,   210,   312,   311,   309,   405,
     401,   443,   439,   467,   463,   244,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   269,
     270,   271,   272,   275,   277,   279,   280,   281,   283,   285,
     323,   397,   409,   411,   413,   415,   417,   418,   419,   420,
     424,   431,   432,   459,   489,   491,   535,   429,   355,   361,
       4,   349,   118,   119,   244,   255,   256,   257,   258,   259,
     260,   323,   459,   489,   491,   545,   546,   547,   548,   549,
     551,   543,   518,   514,   381,   377,   210,   210,   210,   210,
     210,   210,   390,     4,     4,   210,   210,   210,   555,   212,
     210,   210,   369,     4,     4,   568,   212,     4,   210,     4,
     576,   185,   187,   188,   244,   323,   489,   491,   628,   629,
     630,   631,   633,   626,   212,   650,     6,     3,   485,   481,
     501,   497,     4,    22,    23,    24,    25,   315,   209,   209,
     209,   209,    38,    39,    40,   332,   209,   209,   209,     8,
       8,     8,     8,     3,     8,   209,   550,     4,     8,     3,
       8,     8,   141,   142,   143,   558,   209,   209,   209,   209,
     229,   634,     4,   632,     3,     8,   209,     8,     8,   209,
     432,     4,   212,   547,     4,   210,     4,   629,   209,     5,
     209,     7,   635,   636,   637,     3,     6,   186,   189,   190,
     191,   192,   638,   639,   640,   642,   643,   644,   645,   636,
     641,     4,     4,     4,   646,     3,     8,     4,   212,   210,
     210,     4,   639,   209,   209
  };

  const unsigned short
  Dhcp6Parser::yyr1_[] =
  {
       0,   213,   215,   214,   216,   214,   217,   214,   218,   214,
     219,   214,   220,   214,   221,   214,   222,   214,   223,   214,
     224,   214,   225,   214,   226,   214,   227,   214,   228,   214,
     229,   229,   229,   229,   229,   229,   229,   230,   232,   231,
     233,   234,   234,   235,   235,   237,   236,   238,   238,   239,
     239,   241,   240,   242,   242,   243,   243,   244,   246,   245,
     248,   247,   250,   249,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   254,
     253,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   273,   272,
     274,   274,   274,   274,   274,   276,   275,   278,   277,   279,
     280,   282,   281,   284,   283,   285,   286,   287,   289,   288,
     290,   291,   293,   292,   295,   294,   296,   296,   297,   297,
     297,   297,   297,   299,   298,   300,   302,   301,   304,   303,
     306,   305,   307,   307,   308,   308,   310,   309,   311,   311,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   314,   313,   315,   315,   315,   315,   317,   316,
     319,   318,   321,   320,   322,   324,   323,   325,   326,   327,
     328,   329,   331,   330,   332,   332,   332,   333,   334,   335,
     336,   338,   337,   339,   341,   340,   343,   342,   345,   344,
     347,   346,   348,   348,   349,   351,   350,   353,   352,   354,
     354,   355,   355,   356,   357,   359,   358,   360,   360,   361,
     361,   361,   362,   363,   365,   364,   367,   366,   368,   368,
     369,   369,   369,   369,   369,   369,   370,   371,   372,   374,
     373,   375,   375,   376,   376,   378,   377,   380,   379,   381,
     381,   381,   382,   382,   384,   383,   386,   385,   388,   387,
     389,   389,   390,   390,   390,   390,   390,   390,   391,   392,
     393,   394,   395,   396,   398,   397,   399,   399,   400,   400,
     402,   401,   404,   403,   405,   405,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   408,
     407,   410,   409,   412,   411,   414,   413,   416,   415,   417,
     418,   419,   421,   420,   422,   422,   422,   422,   423,   424,
     426,   425,   427,   427,   428,   428,   430,   429,   431,   431,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     434,   433,   436,   435,   437,   437,   438,   438,   440,   439,
     442,   441,   443,   443,   444,   444,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   446,   447,   448,   450,
     449,   452,   451,   454,   453,   455,   457,   456,   458,   460,
     459,   461,   461,   462,   462,   464,   463,   466,   465,   467,
     467,   468,   468,   469,   469,   469,   469,   469,   469,   469,
     469,   469,   470,   472,   471,   473,   474,   475,   476,   478,
     477,   479,   479,   480,   480,   482,   481,   484,   483,   485,
     485,   486,   486,   486,   486,   486,   486,   486,   488,   487,
     490,   489,   492,   491,   494,   493,   495,   495,   496,   496,
     498,   497,   500,   499,   501,   501,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   504,   503,   505,
     507,   506,   508,   509,   511,   510,   512,   512,   513,   513,
     515,   514,   517,   516,   518,   518,   519,   519,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   522,
     521,   524,   523,   526,   525,   528,   527,   530,   529,   532,
     531,   534,   533,   536,   535,   537,   537,   539,   538,   541,
     540,   542,   542,   544,   543,   545,   545,   546,   546,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   548,   550,   549,   551,   553,   552,   554,   554,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   557,
     556,   558,   558,   558,   559,   561,   560,   562,   563,   564,
     566,   565,   567,   567,   568,   568,   568,   568,   568,   570,
     569,   572,   571,   574,   573,   575,   575,   576,   576,   576,
     576,   576,   576,   577,   579,   578,   580,   582,   581,   584,
     583,   586,   585,   587,   587,   588,   588,   588,   588,   588,
     588,   588,   588,   588,   588,   588,   588,   588,   588,   588,
     588,   588,   588,   589,   591,   590,   593,   592,   594,   596,
     595,   597,   598,   600,   599,   601,   601,   603,   602,   604,
     605,   607,   606,   609,   608,   611,   610,   613,   612,   615,
     614,   617,   616,   618,   618,   619,   619,   621,   620,   622,
     624,   623,   625,   625,   627,   626,   628,   628,   629,   629,
     629,   629,   629,   629,   629,   630,   632,   631,   634,   633,
     635,   635,   637,   636,   638,   638,   639,   639,   639,   639,
     639,   641,   640,   642,   643,   644,   646,   645,   648,   647,
     649,   649,   650,   650,   651
  };

  const unsigned char
  Dhcp6Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     1,     3,     5,     0,     4,     0,     1,     1,
       3,     0,     4,     0,     1,     1,     3,     2,     0,     4,
       0,     6,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     4,
       1,     1,     1,     1,     1,     0,     4,     0,     4,     3,
       3,     0,     4,     0,     4,     3,     3,     3,     0,     4,
       3,     3,     0,     6,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     0,     4,     3,     0,     6,     0,     6,
       0,     6,     0,     1,     1,     3,     0,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     3,     0,     4,     3,     3,     3,
       3,     3,     0,     4,     1,     1,     1,     3,     3,     3,
       3,     0,     4,     3,     0,     4,     0,     4,     0,     4,
       0,     6,     1,     3,     1,     0,     4,     0,     6,     1,
       3,     1,     1,     1,     1,     0,     6,     1,     3,     1,
       1,     1,     1,     1,     0,     6,     0,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     0,
       6,     0,     1,     1,     3,     0,     4,     0,     4,     1,
       3,     1,     1,     1,     0,     4,     0,     4,     0,     6,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     0,     6,     0,     1,     1,     3,
       0,     4,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       3,     3,     0,     4,     1,     1,     1,     1,     3,     3,
       0,     6,     0,     1,     1,     3,     0,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     0,     4,     0,     1,     1,     3,     0,     4,
       0,     4,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       4,     0,     4,     0,     4,     1,     0,     4,     3,     0,
       6,     0,     1,     1,     3,     0,     4,     0,     4,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     3,     3,     0,
       6,     0,     1,     1,     3,     0,     4,     0,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     0,     6,     0,     1,     1,     3,
       0,     4,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     3,
       0,     4,     3,     3,     0,     6,     0,     1,     1,     3,
       0,     4,     0,     4,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     6,     1,     1,     0,     4,     0,
       6,     1,     3,     0,     4,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     3,     0,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     1,     1,     3,     0,     4,     3,     3,     3,
       0,     6,     1,     3,     1,     1,     1,     1,     1,     0,
       4,     0,     4,     0,     6,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     0,     4,     3,     0,     4,     0,
       6,     0,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     4,     0,     4,     3,     0,
       4,     3,     3,     0,     4,     1,     1,     0,     4,     3,
       3,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       6,     0,     4,     1,     3,     1,     1,     0,     6,     3,
       0,     6,     1,     3,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     4,     0,     6,
       1,     3,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     0,     4,     3,     3,     3,     0,     4,     0,     6,
       1,     3,     1,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Dhcp6Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\",\"", "\":\"", "\"[\"",
  "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"Dhcp6\"", "\"data-directory\"",
  "\"config-control\"", "\"config-databases\"",
  "\"config-fetch-wait-time\"", "\"interfaces-config\"", "\"interfaces\"",
  "\"re-detect\"", "\"lease-database\"", "\"hosts-database\"",
  "\"hosts-databases\"", "\"type\"", "\"memfile\"", "\"mysql\"",
  "\"postgresql\"", "\"cql\"", "\"user\"", "\"password\"", "\"host\"",
  "\"port\"", "\"persist\"", "\"lfc-interval\"", "\"readonly\"",
  "\"connect-timeout\"", "\"contact-points\"", "\"max-reconnect-tries\"",
  "\"reconnect-wait-time\"", "\"on-fail\"", "\"stop-retry-exit\"",
  "\"serve-retry-exit\"", "\"serve-retry-continue\"", "\"keyspace\"",
  "\"consistency\"", "\"serial-consistency\"", "\"request-timeout\"",
  "\"tcp-keepalive\"", "\"tcp-nodelay\"", "\"max-row-errors\"",
  "\"preferred-lifetime\"", "\"min-preferred-lifetime\"",
  "\"max-preferred-lifetime\"", "\"valid-lifetime\"",
  "\"min-valid-lifetime\"", "\"max-valid-lifetime\"", "\"renew-timer\"",
  "\"rebind-timer\"", "\"calculate-tee-times\"", "\"t1-percent\"",
  "\"t2-percent\"", "\"cache-threshold\"", "\"cache-max-age\"",
  "\"decline-probation-period\"", "\"server-tag\"",
  "\"statistic-default-sample-count\"", "\"statistic-default-sample-age\"",
  "\"ddns-send-updates\"", "\"ddns-override-no-update\"",
  "\"ddns-override-client-update\"", "\"ddns-replace-client-name\"",
  "\"ddns-generated-prefix\"", "\"ddns-qualifying-suffix\"",
  "\"ddns-update-on-renew\"", "\"ddns-use-conflict-resolution\"",
  "\"store-extended-info\"", "\"subnet6\"", "\"option-def\"",
  "\"option-data\"", "\"name\"", "\"data\"", "\"code\"", "\"space\"",
  "\"csv-format\"", "\"always-send\"", "\"record-types\"",
  "\"encapsulate\"", "\"array\"", "\"parked-packet-limit\"",
  "\"shared-networks\"", "\"pools\"", "\"pool\"", "\"pd-pools\"",
  "\"prefix\"", "\"prefix-len\"", "\"excluded-prefix\"",
  "\"excluded-prefix-len\"", "\"delegated-len\"", "\"user-context\"",
  "\"comment\"", "\"subnet\"", "\"interface\"", "\"interface-id\"",
  "\"id\"", "\"rapid-commit\"", "\"reservation-mode\"", "\"disabled\"",
  "\"out-of-pool\"", "\"global\"", "\"all\"", "\"reservations-global\"",
  "\"reservations-in-subnet\"", "\"reservations-out-of-pool\"",
  "\"mac-sources\"", "\"relay-supplied-options\"",
  "\"host-reservation-identifiers\"", "\"sanity-checks\"",
  "\"lease-checks\"", "\"client-classes\"", "\"require-client-classes\"",
  "\"test\"", "\"only-if-required\"", "\"client-class\"",
  "\"reservations\"", "\"ip-addresses\"", "\"prefixes\"", "\"duid\"",
  "\"hw-address\"", "\"hostname\"", "\"flex-id\"", "\"relay\"",
  "\"ip-address\"", "\"hooks-libraries\"", "\"library\"", "\"parameters\"",
  "\"expired-leases-processing\"", "\"reclaim-timer-wait-time\"",
  "\"flush-reclaimed-timer-wait-time\"", "\"hold-reclaimed-time\"",
  "\"max-reclaim-leases\"", "\"max-reclaim-time\"",
  "\"unwarned-reclaim-cycles\"", "\"server-id\"", "\"LLT\"", "\"EN\"",
  "\"LL\"", "\"identifier\"", "\"htype\"", "\"time\"", "\"enterprise-id\"",
  "\"dhcp4o6-port\"", "\"multi-threading\"", "\"enable-multi-threading\"",
  "\"thread-pool-size\"", "\"packet-queue-size\"", "\"control-socket\"",
  "\"socket-type\"", "\"socket-name\"", "\"dhcp-queue-control\"",
  "\"enable-queue\"", "\"queue-type\"", "\"capacity\"", "\"dhcp-ddns\"",
  "\"enable-updates\"", "\"qualifying-suffix\"", "\"server-ip\"",
  "\"server-port\"", "\"sender-ip\"", "\"sender-port\"",
  "\"max-queue-size\"", "\"ncr-protocol\"", "\"ncr-format\"",
  "\"override-no-update\"", "\"override-client-update\"",
  "\"replace-client-name\"", "\"generated-prefix\"", "\"UDP\"", "\"TCP\"",
  "\"JSON\"", "\"when-present\"", "\"never\"", "\"always\"",
  "\"when-not-present\"", "\"hostname-char-set\"",
  "\"hostname-char-replacement\"", "\"ip-reservations-unique\"",
  "\"loggers\"", "\"output_options\"", "\"output\"", "\"debuglevel\"",
  "\"severity\"", "\"flush\"", "\"maxsize\"", "\"maxver\"", "\"pattern\"",
  "\"compatibility\"", "\"lenient-option-parsing\"", "TOPLEVEL_JSON",
  "TOPLEVEL_DHCP6", "SUB_DHCP6", "SUB_INTERFACES6", "SUB_SUBNET6",
  "SUB_POOL6", "SUB_PD_POOL", "SUB_RESERVATION", "SUB_OPTION_DEFS",
  "SUB_OPTION_DEF", "SUB_OPTION_DATA", "SUB_HOOKS_LIBRARY",
  "SUB_DHCP_DDNS", "SUB_CONFIG_CONTROL", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "value", "sub_json", "map2", "$@15",
  "map_value", "map_content", "not_empty_map", "list_generic", "$@16",
  "list_content", "not_empty_list", "list_strings", "$@17",
  "list_strings_content", "not_empty_list_strings", "unknown_map_entry",
  "syntax_map", "$@18", "global_object", "$@19", "sub_dhcp6", "$@20",
  "global_params", "global_param", "data_directory", "$@21",
  "preferred_lifetime", "min_preferred_lifetime", "max_preferred_lifetime",
  "valid_lifetime", "min_valid_lifetime", "max_valid_lifetime",
  "renew_timer", "rebind_timer", "calculate_tee_times", "t1_percent",
  "t2_percent", "cache_threshold", "cache_max_age",
  "decline_probation_period", "ddns_send_updates",
  "ddns_override_no_update", "ddns_override_client_update",
  "ddns_replace_client_name", "$@22", "ddns_replace_client_name_value",
  "ddns_generated_prefix", "$@23", "ddns_qualifying_suffix", "$@24",
  "ddns_update_on_renew", "ddns_use_conflict_resolution",
  "hostname_char_set", "$@25", "hostname_char_replacement", "$@26",
  "store_extended_info", "statistic_default_sample_count",
  "statistic_default_sample_age", "server_tag", "$@27",
  "parked_packet_limit", "ip_reservations_unique", "interfaces_config",
  "$@28", "sub_interfaces6", "$@29", "interfaces_config_params",
  "interfaces_config_param", "interfaces_list", "$@30", "re_detect",
  "lease_database", "$@31", "hosts_database", "$@32", "hosts_databases",
  "$@33", "database_list", "not_empty_database_list", "database", "$@34",
  "database_map_params", "database_map_param", "database_type", "$@35",
  "db_type", "user", "$@36", "password", "$@37", "host", "$@38", "port",
  "name", "$@39", "persist", "lfc_interval", "readonly", "connect_timeout",
  "reconnect_wait_time", "on_fail", "$@40", "on_fail_mode",
  "max_row_errors", "request_timeout", "tcp_keepalive", "tcp_nodelay",
  "contact_points", "$@41", "max_reconnect_tries", "keyspace", "$@42",
  "consistency", "$@43", "serial_consistency", "$@44", "sanity_checks",
  "$@45", "sanity_checks_params", "sanity_checks_param", "lease_checks",
  "$@46", "mac_sources", "$@47", "mac_sources_list", "mac_sources_value",
  "duid_id", "string_id", "host_reservation_identifiers", "$@48",
  "host_reservation_identifiers_list", "host_reservation_identifier",
  "hw_address_id", "flex_id", "relay_supplied_options", "$@49",
  "dhcp_multi_threading", "$@50", "multi_threading_params",
  "multi_threading_param", "enable_multi_threading", "thread_pool_size",
  "packet_queue_size", "hooks_libraries", "$@51", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@52",
  "sub_hooks_library", "$@53", "hooks_params", "hooks_param", "library",
  "$@54", "parameters", "$@55", "expired_leases_processing", "$@56",
  "expired_leases_params", "expired_leases_param",
  "reclaim_timer_wait_time", "flush_reclaimed_timer_wait_time",
  "hold_reclaimed_time", "max_reclaim_leases", "max_reclaim_time",
  "unwarned_reclaim_cycles", "subnet6_list", "$@57",
  "subnet6_list_content", "not_empty_subnet6_list", "subnet6", "$@58",
  "sub_subnet6", "$@59", "subnet6_params", "subnet6_param", "subnet",
  "$@60", "interface", "$@61", "interface_id", "$@62", "client_class",
  "$@63", "require_client_classes", "$@64", "reservations_global",
  "reservations_in_subnet", "reservations_out_of_pool", "reservation_mode",
  "$@65", "hr_mode", "id", "rapid_commit", "shared_networks", "$@66",
  "shared_networks_content", "shared_networks_list", "shared_network",
  "$@67", "shared_network_params", "shared_network_param",
  "option_def_list", "$@68", "sub_option_def_list", "$@69",
  "option_def_list_content", "not_empty_option_def_list",
  "option_def_entry", "$@70", "sub_option_def", "$@71",
  "option_def_params", "not_empty_option_def_params", "option_def_param",
  "option_def_name", "code", "option_def_code", "option_def_type", "$@72",
  "option_def_record_types", "$@73", "space", "$@74", "option_def_space",
  "option_def_encapsulate", "$@75", "option_def_array", "option_data_list",
  "$@76", "option_data_list_content", "not_empty_option_data_list",
  "option_data_entry", "$@77", "sub_option_data", "$@78",
  "option_data_params", "not_empty_option_data_params",
  "option_data_param", "option_data_name", "option_data_data", "$@79",
  "option_data_code", "option_data_space", "option_data_csv_format",
  "option_data_always_send", "pools_list", "$@80", "pools_list_content",
  "not_empty_pools_list", "pool_list_entry", "$@81", "sub_pool6", "$@82",
  "pool_params", "pool_param", "pool_entry", "$@83", "user_context",
  "$@84", "comment", "$@85", "pd_pools_list", "$@86",
  "pd_pools_list_content", "not_empty_pd_pools_list", "pd_pool_entry",
  "$@87", "sub_pd_pool", "$@88", "pd_pool_params", "pd_pool_param",
  "pd_prefix", "$@89", "pd_prefix_len", "excluded_prefix", "$@90",
  "excluded_prefix_len", "pd_delegated_len", "reservations", "$@91",
  "reservations_list", "not_empty_reservations_list", "reservation",
  "$@92", "sub_reservation", "$@93", "reservation_params",
  "not_empty_reservation_params", "reservation_param", "ip_addresses",
  "$@94", "prefixes", "$@95", "duid", "$@96", "hw_address", "$@97",
  "hostname", "$@98", "flex_id_value", "$@99",
  "reservation_client_classes", "$@100", "relay", "$@101", "relay_map",
  "ip_address", "$@102", "client_classes", "$@103", "client_classes_list",
  "client_class_entry", "$@104", "client_class_params",
  "not_empty_client_class_params", "client_class_param",
  "client_class_name", "client_class_test", "$@105", "only_if_required",
  "server_id", "$@106", "server_id_params", "server_id_param",
  "server_id_type", "$@107", "duid_type", "htype", "identifier", "$@108",
  "time", "enterprise_id", "dhcp4o6_port", "control_socket", "$@109",
  "control_socket_params", "control_socket_param", "socket_type", "$@110",
  "socket_name", "$@111", "dhcp_queue_control", "$@112",
  "queue_control_params", "queue_control_param", "enable_queue",
  "queue_type", "$@113", "capacity", "arbitrary_map_entry", "$@114",
  "dhcp_ddns", "$@115", "sub_dhcp_ddns", "$@116", "dhcp_ddns_params",
  "dhcp_ddns_param", "enable_updates", "dep_qualifying_suffix", "$@117",
  "server_ip", "$@118", "server_port", "sender_ip", "$@119", "sender_port",
  "max_queue_size", "ncr_protocol", "$@120", "ncr_protocol_value",
  "ncr_format", "$@121", "dep_override_no_update",
  "dep_override_client_update", "dep_replace_client_name", "$@122",
  "dep_generated_prefix", "$@123", "dep_hostname_char_set", "$@124",
  "dep_hostname_char_replacement", "$@125", "config_control", "$@126",
  "sub_config_control", "$@127", "config_control_params",
  "config_control_param", "config_databases", "$@128",
  "config_fetch_wait_time", "loggers", "$@129", "loggers_entries",
  "logger_entry", "$@130", "logger_params", "logger_param", "debuglevel",
  "severity", "$@131", "output_options_list", "$@132",
  "output_options_list_content", "output_entry", "$@133",
  "output_params_list", "output_params", "output", "$@134", "flush",
  "maxsize", "maxver", "pattern", "$@135", "compatibility", "$@136",
  "compatibility_params", "compatibility_param", "lenient_option_parsing", YY_NULLPTR
  };

#if PARSER6_DEBUG
  const unsigned short
  Dhcp6Parser::yyrline_[] =
  {
       0,   301,   301,   301,   302,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   307,   308,   308,   309,   309,
     310,   310,   311,   311,   312,   312,   313,   313,   314,   314,
     322,   323,   324,   325,   326,   327,   328,   331,   336,   336,
     347,   350,   351,   354,   359,   367,   367,   374,   375,   378,
     382,   389,   389,   396,   397,   400,   404,   415,   424,   424,
     439,   439,   456,   456,   465,   466,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   536,
     536,   545,   551,   557,   563,   569,   575,   581,   587,   593,
     599,   605,   611,   617,   623,   629,   635,   641,   647,   647,
     656,   659,   662,   665,   668,   674,   674,   683,   683,   692,
     698,   704,   704,   713,   713,   722,   728,   734,   740,   740,
     749,   755,   761,   761,   773,   773,   782,   783,   786,   787,
     788,   789,   790,   793,   793,   804,   810,   810,   823,   823,
     836,   836,   847,   848,   851,   852,   855,   855,   865,   866,
     869,   870,   871,   872,   873,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   887,   888,
     889,   890,   893,   893,   901,   902,   903,   904,   907,   907,
     916,   916,   925,   925,   934,   940,   940,   949,   955,   961,
     967,   973,   979,   979,   987,   988,   989,   992,   998,  1004,
    1010,  1016,  1016,  1025,  1031,  1031,  1040,  1040,  1049,  1049,
    1058,  1058,  1069,  1070,  1072,  1074,  1074,  1093,  1093,  1104,
    1105,  1108,  1109,  1112,  1117,  1122,  1122,  1133,  1134,  1137,
    1138,  1139,  1142,  1147,  1154,  1154,  1167,  1167,  1180,  1181,
    1184,  1185,  1186,  1187,  1188,  1189,  1192,  1198,  1204,  1210,
    1210,  1221,  1222,  1225,  1226,  1229,  1229,  1239,  1239,  1249,
    1250,  1251,  1254,  1255,  1258,  1258,  1267,  1267,  1276,  1276,
    1288,  1289,  1292,  1293,  1294,  1295,  1296,  1297,  1300,  1306,
    1312,  1318,  1324,  1330,  1339,  1339,  1353,  1354,  1357,  1358,
    1365,  1365,  1391,  1391,  1402,  1403,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1452,
    1452,  1461,  1461,  1470,  1470,  1479,  1479,  1488,  1488,  1499,
    1505,  1511,  1517,  1517,  1525,  1526,  1527,  1528,  1531,  1537,
    1545,  1545,  1557,  1558,  1562,  1563,  1566,  1566,  1574,  1575,
    1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,
    1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,
    1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,
    1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,
    1624,  1624,  1638,  1638,  1647,  1648,  1651,  1652,  1657,  1657,
    1672,  1672,  1686,  1687,  1690,  1691,  1694,  1695,  1696,  1697,
    1698,  1699,  1700,  1701,  1702,  1703,  1706,  1708,  1714,  1716,
    1716,  1725,  1725,  1734,  1734,  1743,  1745,  1745,  1754,  1764,
    1764,  1777,  1778,  1783,  1784,  1789,  1789,  1801,  1801,  1813,
    1814,  1819,  1820,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1836,  1838,  1838,  1847,  1849,  1851,  1857,  1866,
    1866,  1879,  1880,  1883,  1884,  1887,  1887,  1897,  1897,  1907,
    1908,  1911,  1912,  1913,  1914,  1915,  1916,  1917,  1920,  1920,
    1929,  1929,  1954,  1954,  1984,  1984,  1997,  1998,  2001,  2002,
    2005,  2005,  2017,  2017,  2029,  2030,  2033,  2034,  2035,  2036,
    2037,  2038,  2039,  2040,  2041,  2042,  2043,  2046,  2046,  2055,
    2061,  2061,  2070,  2076,  2085,  2085,  2096,  2097,  2100,  2101,
    2104,  2104,  2113,  2113,  2122,  2123,  2126,  2127,  2131,  2132,
    2133,  2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,  2144,
    2144,  2155,  2155,  2166,  2166,  2175,  2175,  2184,  2184,  2193,
    2193,  2202,  2202,  2216,  2216,  2227,  2228,  2231,  2231,  2243,
    2243,  2254,  2255,  2258,  2258,  2268,  2269,  2272,  2273,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,
    2287,  2288,  2291,  2293,  2293,  2302,  2311,  2311,  2324,  2325,
    2328,  2329,  2330,  2331,  2332,  2333,  2334,  2335,  2336,  2339,
    2339,  2347,  2348,  2349,  2352,  2358,  2358,  2367,  2373,  2381,
    2389,  2389,  2400,  2401,  2404,  2405,  2406,  2407,  2408,  2411,
    2411,  2420,  2420,  2432,  2432,  2445,  2446,  2449,  2450,  2451,
    2452,  2453,  2454,  2457,  2463,  2463,  2472,  2478,  2478,  2488,
    2488,  2501,  2501,  2511,  2512,  2515,  2516,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2535,  2542,  2542,  2551,  2551,  2560,  2566,
    2566,  2575,  2581,  2587,  2587,  2596,  2597,  2600,  2600,  2610,
    2617,  2624,  2624,  2633,  2633,  2643,  2643,  2653,  2653,  2665,
    2665,  2677,  2677,  2687,  2688,  2692,  2693,  2696,  2696,  2707,
    2715,  2715,  2728,  2729,  2733,  2733,  2741,  2742,  2745,  2746,
    2747,  2748,  2749,  2750,  2751,  2754,  2760,  2760,  2769,  2769,
    2780,  2781,  2784,  2784,  2792,  2793,  2796,  2797,  2798,  2799,
    2800,  2803,  2803,  2812,  2818,  2824,  2830,  2830,  2839,  2839,
    2850,  2851,  2854,  2855,  2858
  };

  // Print the state stack on the debug stream.
  void
  Dhcp6Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Dhcp6Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // PARSER6_DEBUG


#line 14 "dhcp6_parser.yy" // lalr1.cc:1242
} } // isc::dhcp
#line 5892 "dhcp6_parser.cc" // lalr1.cc:1242
#line 2864 "dhcp6_parser.yy" // lalr1.cc:1243


void
isc::dhcp::Dhcp6Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
