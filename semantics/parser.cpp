/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <cstdio>
#include "ast.hpp"
#include "lexer.hpp"
#include <iostream>
#include <string>
SymbolTable st;
std::map<char, int> globals;


#line 82 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_and = 3,                      /* "and"  */
  YYSYMBOL_T_char = 4,                     /* "char"  */
  YYSYMBOL_T_div = 5,                      /* "div"  */
  YYSYMBOL_T_do = 6,                       /* "do"  */
  YYSYMBOL_T_else = 7,                     /* "else"  */
  YYSYMBOL_T_fun = 8,                      /* "fun"  */
  YYSYMBOL_T_if = 9,                       /* "if"  */
  YYSYMBOL_T_int = 10,                     /* "int"  */
  YYSYMBOL_T_mod = 11,                     /* "mod"  */
  YYSYMBOL_T_not = 12,                     /* "not"  */
  YYSYMBOL_T_nothing = 13,                 /* "nothing"  */
  YYSYMBOL_T_or = 14,                      /* "or"  */
  YYSYMBOL_T_ref = 15,                     /* "ref"  */
  YYSYMBOL_T_return = 16,                  /* "return"  */
  YYSYMBOL_T_then = 17,                    /* "then"  */
  YYSYMBOL_T_var = 18,                     /* "var"  */
  YYSYMBOL_T_while = 19,                   /* "while"  */
  YYSYMBOL_T_arrow = 20,                   /* "<-"  */
  YYSYMBOL_T_smaller = 21,                 /* "<="  */
  YYSYMBOL_T_greater = 22,                 /* ">="  */
  YYSYMBOL_T_id = 23,                      /* T_id  */
  YYSYMBOL_T_const = 24,                   /* T_const  */
  YYSYMBOL_T_charra = 25,                  /* T_charra  */
  YYSYMBOL_T_charr = 26,                   /* T_charr  */
  YYSYMBOL_T_string = 27,                  /* T_string  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '#'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* ':'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_46_func_def = 46,               /* func-def  */
  YYSYMBOL_47_local_deff = 47,             /* local-deff  */
  YYSYMBOL_48_local_def = 48,              /* local-def  */
  YYSYMBOL_header = 49,                    /* header  */
  YYSYMBOL_50_fpar_def = 50,               /* fpar-def  */
  YYSYMBOL_51_new_def = 51,                /* new-def  */
  YYSYMBOL_52_data_type = 52,              /* data-type  */
  YYSYMBOL_declaration = 53,               /* declaration  */
  YYSYMBOL_box = 54,                       /* box  */
  YYSYMBOL_55_fpar_type = 55,              /* fpar-type  */
  YYSYMBOL_56_func_decl = 56,              /* func-decl  */
  YYSYMBOL_57_var_def = 57,                /* var-def  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_block = 59,                     /* block  */
  YYSYMBOL_sol = 60,                       /* sol  */
  YYSYMBOL_61_func_call = 61,              /* func-call  */
  YYSYMBOL_komma = 62,                     /* komma  */
  YYSYMBOL_63_l_value = 63,                /* l-value  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_cond = 65                       /* cond  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    29,     2,     2,     2,     2,
      35,    36,    34,    32,    39,    33,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
      31,    28,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   109,   110,   114,   115,   119,   120,   121,
     125,   126,   130,   131,   132,   133,   134,   135,   136,   137,
     141,   142,   146,   147,   148,   152,   153,   157,   158,   162,
     163,   164,   165,   169,   173,   174,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   190,   191,   195,   196,   200,
     201,   202,   206,   207,   211,   212,   213,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"and\"", "\"char\"",
  "\"div\"", "\"do\"", "\"else\"", "\"fun\"", "\"if\"", "\"int\"",
  "\"mod\"", "\"not\"", "\"nothing\"", "\"or\"", "\"ref\"", "\"return\"",
  "\"then\"", "\"var\"", "\"while\"", "\"<-\"", "\"<=\"", "\">=\"", "T_id",
  "T_const", "T_charra", "T_charr", "T_string", "'='", "'#'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'('", "')'", "':'", "';'", "','", "'['", "']'",
  "'{'", "'}'", "$accept", "program", "func-def", "local-deff",
  "local-def", "header", "fpar-def", "new-def", "data-type", "declaration",
  "box", "fpar-type", "func-decl", "var-def", "stmt", "block", "sol",
  "func-call", "komma", "l-value", "expr", "cond", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,   -17,    30,   -93,     6,    28,   -93,    11,    86,   -93,
       6,   -93,     8,   -93,   -93,   -93,     0,    -2,   190,   211,
     190,    61,   -93,   -93,   -93,   -93,   -93,    88,    50,   -13,
     -93,   -93,   -93,    75,    22,    62,    64,    18,    80,    71,
     190,   -93,   -93,   -93,   242,   242,   190,   -93,    74,   198,
      53,   242,   -93,   140,    54,   228,   -93,   -93,   -93,   242,
     242,    25,    18,    84,    18,    85,   -93,   -93,   -93,    87,
      94,    97,    18,   -93,    -1,    -1,   165,    15,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   190,
     190,   133,   174,   -93,   133,   -93,   105,   150,    60,    18,
     103,    93,   112,    18,   -93,    18,   119,   -93,   -93,   -93,
     116,   -93,   -93,   -93,   -93,   157,   157,   157,   157,   157,
     157,    -1,    -1,   -93,   -93,   -93,   151,   -93,   -93,   242,
     121,   -93,   -93,   125,    18,    65,   -93,   -12,   126,   -93,
     118,   -93,   133,   114,   -93,   -12,   127,    87,   -93,   -12,
      87,   -93,   -93,   -93,   -12,   -93,   -93,   -93,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     0,     0,     7,
       0,     5,     0,     8,     9,     4,     0,     0,     0,     0,
       0,    54,    55,    36,    46,    47,    38,     0,     0,     0,
       6,     3,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    58,    57,     0,     0,     0,    64,    60,     0,
       0,     0,    43,     0,     0,     0,    45,    48,    39,     0,
       0,     0,     0,     0,     0,     0,    23,    22,    24,    26,
       0,    20,     0,    71,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    49,     0,     0,     0,     0,
       0,    32,    13,     0,    10,     0,     0,    25,    35,    21,
       0,    61,    70,    68,    69,    78,    79,    74,    75,    77,
      76,    65,    66,    67,    72,    73,    40,    42,    51,     0,
       0,    37,    56,    17,     0,     0,    31,     0,    15,    11,
       0,    34,     0,    52,    50,     0,    19,    30,    12,     0,
      28,    41,    53,    16,     0,    29,    14,    27,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   166,   -93,   159,   167,    96,   -29,   -20,   109,
     -92,   -91,   -93,   -93,   -25,   108,   -93,    -8,    34,    -7,
      -6,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    12,    36,    39,   101,    70,
     107,   102,    13,    14,    25,    26,    27,    47,   130,    48,
      49,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    29,    57,    33,    78,    63,     5,    59,   133,   136,
      79,    34,   138,    53,     1,    33,     1,    69,    89,    28,
      29,    54,    66,    34,     7,     1,     7,    60,    67,    90,
       6,    68,   100,    88,    17,    37,    35,    38,    74,    75,
      76,    73,   109,   146,   104,    92,    32,    77,     8,    96,
       8,   112,    69,    97,    98,   155,    89,    89,   157,    62,
      94,    38,    99,    16,    38,    78,   126,    90,    90,   127,
      91,    79,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    28,    29,   139,    28,    29,    58,   140,
     124,   125,    86,    87,    88,    18,    55,    18,    61,    64,
      65,   132,    19,    71,    19,    20,   147,    20,    72,    21,
      78,    21,    15,    22,    60,    22,    79,   151,    31,    78,
      15,   103,   105,   143,    23,    79,    23,   106,     8,    24,
       8,    56,   108,   135,    28,    29,    38,    86,    87,    88,
     134,   128,    18,   140,   129,    78,    86,    87,    88,    19,
     137,    79,    20,   129,   141,    78,    21,   144,   142,   150,
      22,    79,    78,   145,   149,   154,     3,     4,    79,    30,
      78,    23,    86,    87,    88,     8,    79,   152,    93,    78,
       0,   110,    86,    87,    88,    79,    80,    81,   131,    86,
      87,    88,     0,    82,    83,    84,    85,    86,    87,    88,
       0,   111,    40,    78,     0,     0,    86,    87,    88,    79,
     111,     0,     0,    21,    41,    42,    43,    22,     0,    80,
      81,     0,    44,    45,     0,    46,    82,    83,    84,    85,
      86,    87,    88,   148,    21,    41,    42,    43,    22,     0,
       0,   153,     0,    44,    45,   156,    51,     0,     0,    52,
     158,    21,    41,    42,    43,    22,     0,     0,     0,     0,
      44,    45,     0,    51,    95,    21,    41,    42,    43,    22,
       0,     0,     0,     0,    44,    45,     0,    51
};

static const yytype_int16 yycheck[] =
{
       8,     8,    27,    15,     5,    34,    23,    20,    99,   101,
      11,    23,   103,    19,     8,    15,     8,    37,     3,    27,
      27,    20,     4,    23,    18,     8,    18,    40,    10,    14,
       0,    13,    61,    34,    23,    37,    36,    39,    44,    45,
      46,    40,    71,   134,    64,    51,    38,    46,    42,    55,
      42,    36,    72,    59,    60,   147,     3,     3,   150,    37,
       6,    39,    37,    35,    39,     5,    91,    14,    14,    94,
      17,    11,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    91,    91,   105,    94,    94,    38,    24,
      89,    90,    32,    33,    34,     9,    35,     9,    23,    37,
      36,    41,    16,    23,    16,    19,    41,    19,    37,    23,
       5,    23,     4,    27,    40,    27,    11,   142,    10,     5,
      12,    37,    37,   129,    38,    11,    38,    40,    42,    43,
      42,    43,    38,    40,   142,   142,    39,    32,    33,    34,
      37,    36,     9,    24,    39,     5,    32,    33,    34,    16,
      38,    11,    19,    39,    38,     5,    23,    36,     7,    41,
      27,    11,     5,    38,    38,    38,     0,     0,    11,    10,
       5,    38,    32,    33,    34,    42,    11,   143,    38,     5,
      -1,    72,    32,    33,    34,    11,    21,    22,    38,    32,
      33,    34,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    12,     5,    -1,    -1,    32,    33,    34,    11,
      36,    -1,    -1,    23,    24,    25,    26,    27,    -1,    21,
      22,    -1,    32,    33,    -1,    35,    28,    29,    30,    31,
      32,    33,    34,   137,    23,    24,    25,    26,    27,    -1,
      -1,   145,    -1,    32,    33,   149,    35,    -1,    -1,    38,
     154,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    35,    36,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    32,    33,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    45,    46,    49,    23,     0,    18,    42,    46,
      47,    48,    49,    56,    57,    59,    35,    23,     9,    16,
      19,    23,    27,    38,    43,    58,    59,    60,    61,    63,
      48,    59,    38,    15,    23,    36,    50,    37,    39,    51,
      12,    24,    25,    26,    32,    33,    35,    61,    63,    64,
      65,    35,    38,    64,    65,    35,    43,    58,    38,    20,
      40,    23,    37,    51,    37,    36,     4,    10,    13,    52,
      53,    23,    37,    65,    64,    64,    64,    65,     5,    11,
      21,    22,    28,    29,    30,    31,    32,    33,    34,     3,
      14,    17,    64,    38,     6,    36,    64,    64,    64,    37,
      51,    52,    55,    37,    52,    37,    40,    54,    38,    51,
      53,    36,    36,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    58,    58,    36,    39,
      62,    38,    41,    55,    37,    40,    54,    38,    55,    52,
      24,    38,     7,    64,    36,    38,    55,    41,    50,    38,
      41,    58,    62,    50,    38,    54,    50,    54,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     1,     1,     1,
       6,     7,     5,     3,     6,     4,     6,     4,     7,     5,
       2,     3,     1,     1,     1,     2,     1,     4,     3,     4,
       3,     2,     1,     2,     6,     5,     1,     4,     1,     2,
       4,     6,     4,     2,     3,     3,     2,     1,     2,     3,
       5,     4,     2,     3,     1,     1,     4,     1,     1,     1,
       1,     3,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: func-def  */
#line 102 "parser.y"
          {
  (yyvsp[0].funcdef)->sem(); 
  //std::cout << "AST: " << *$1 << std::endl;
  }
#line 1258 "parser.cpp"
    break;

  case 3: /* func-def: header local-deff block  */
#line 109 "parser.y"
                          { (yyval.funcdef) = new Funcdef_default((yyvsp[-2].head),(yyvsp[0].blocks),(yyvsp[-1].localdeff));}
#line 1264 "parser.cpp"
    break;

  case 4: /* func-def: header block  */
#line 110 "parser.y"
               { (yyval.funcdef) = new Funcdef_default((yyvsp[-1].head),(yyvsp[0].blocks)); }
#line 1270 "parser.cpp"
    break;

  case 5: /* local-deff: local-def  */
#line 114 "parser.y"
            {(yyval.localdeff)=new Localdeff((yyvsp[0].localdef));}
#line 1276 "parser.cpp"
    break;

  case 6: /* local-deff: local-deff local-def  */
#line 115 "parser.y"
                       {(yyvsp[-1].localdeff)->append_blc((yyvsp[0].localdef)); (yyval.localdeff) = (yyvsp[-1].localdeff);}
#line 1282 "parser.cpp"
    break;

  case 7: /* local-def: func-def  */
#line 119 "parser.y"
           {(yyval.localdef)= new Localdef_1((yyvsp[0].funcdef));}
#line 1288 "parser.cpp"
    break;

  case 8: /* local-def: func-decl  */
#line 120 "parser.y"
            {(yyval.localdef)= new Localdef_2((yyvsp[0].funcdecl));}
#line 1294 "parser.cpp"
    break;

  case 9: /* local-def: var-def  */
#line 121 "parser.y"
          {(yyval.localdef)= new Localdef_3((yyvsp[0].vardef));}
#line 1300 "parser.cpp"
    break;

  case 10: /* header: "fun" T_id '(' ')' ':' data-type  */
#line 125 "parser.y"
                                   {(yyval.head)= new Head((yyvsp[-4].RepString),(yyvsp[0].type));}
#line 1306 "parser.cpp"
    break;

  case 11: /* header: "fun" T_id '(' fpar-def ')' ':' data-type  */
#line 126 "parser.y"
                                            {(yyval.head)=new Head((yyvsp[-5].RepString),(yyvsp[0].type),(yyvsp[-3].fpardef));}
#line 1312 "parser.cpp"
    break;

  case 12: /* fpar-def: T_id ':' fpar-type ';' fpar-def  */
#line 130 "parser.y"
                                  {(yyval.fpardef)= new Fpardef_1((yyvsp[-4].RepString), (yyvsp[-2].fpartype), (yyvsp[0].fpardef));}
#line 1318 "parser.cpp"
    break;

  case 13: /* fpar-def: T_id ':' fpar-type  */
#line 131 "parser.y"
                     { (yyval.fpardef)= new Fpardef_1((yyvsp[-2].RepString), (yyvsp[0].fpartype)); }
#line 1324 "parser.cpp"
    break;

  case 14: /* fpar-def: T_id new-def ':' fpar-type ';' fpar-def  */
#line 132 "parser.y"
                                          {(yyval.fpardef)= new Fpardef_2((yyvsp[-5].RepString), (yyvsp[-4].newdef),(yyvsp[-2].fpartype),(yyvsp[0].fpardef));}
#line 1330 "parser.cpp"
    break;

  case 15: /* fpar-def: T_id new-def ':' fpar-type  */
#line 133 "parser.y"
                             { (yyval.fpardef)= new Fpardef_2((yyvsp[-3].RepString), (yyvsp[-2].newdef),(yyvsp[0].fpartype)); }
#line 1336 "parser.cpp"
    break;

  case 16: /* fpar-def: "ref" T_id ':' fpar-type ';' fpar-def  */
#line 134 "parser.y"
                                        {(yyval.fpardef)= new Fpardef_3((yyvsp[-4].RepString), (yyvsp[-2].fpartype), (yyvsp[0].fpardef));}
#line 1342 "parser.cpp"
    break;

  case 17: /* fpar-def: "ref" T_id ':' fpar-type  */
#line 135 "parser.y"
                           { (yyval.fpardef)= new Fpardef_3((yyvsp[-2].RepString), (yyvsp[0].fpartype)); }
#line 1348 "parser.cpp"
    break;

  case 18: /* fpar-def: "ref" T_id new-def ':' fpar-type ';' fpar-def  */
#line 136 "parser.y"
                                                {(yyval.fpardef)= new Fpardef_4((yyvsp[-5].RepString), (yyvsp[-4].newdef),(yyvsp[-2].fpartype), (yyvsp[0].fpardef));}
#line 1354 "parser.cpp"
    break;

  case 19: /* fpar-def: "ref" T_id new-def ':' fpar-type  */
#line 137 "parser.y"
                                   { (yyval.fpardef)= new Fpardef_4((yyvsp[-3].RepString), (yyvsp[-2].newdef),(yyvsp[0].fpartype)); }
#line 1360 "parser.cpp"
    break;

  case 20: /* new-def: ',' T_id  */
#line 141 "parser.y"
           {(yyval.newdef)= new Newdef((yyvsp[0].RepString));}
#line 1366 "parser.cpp"
    break;

  case 21: /* new-def: ',' T_id new-def  */
#line 142 "parser.y"
                  {(yyval.newdef)=new Newdef((yyvsp[-1].RepString),(yyvsp[0].newdef));}
#line 1372 "parser.cpp"
    break;

  case 22: /* data-type: "int"  */
#line 146 "parser.y"
         {(yyval.type)=TYPE_int;}
#line 1378 "parser.cpp"
    break;

  case 23: /* data-type: "char"  */
#line 147 "parser.y"
         {(yyval.type)=TYPE_char;}
#line 1384 "parser.cpp"
    break;

  case 24: /* data-type: "nothing"  */
#line 148 "parser.y"
            {(yyval.type)=TYPE_nothing;}
#line 1390 "parser.cpp"
    break;

  case 25: /* declaration: data-type box  */
#line 152 "parser.y"
                {(yyval.decl)= new Declaration((yyvsp[-1].type),(yyvsp[0].vox));}
#line 1396 "parser.cpp"
    break;

  case 26: /* declaration: data-type  */
#line 153 "parser.y"
            {(yyval.decl)= new Declaration((yyvsp[0].type));}
#line 1402 "parser.cpp"
    break;

  case 27: /* box: '[' T_const ']' box  */
#line 157 "parser.y"
                      {(yyval.vox)= new Box((yyvsp[-2].num),(yyvsp[0].vox));}
#line 1408 "parser.cpp"
    break;

  case 28: /* box: '[' T_const ']'  */
#line 158 "parser.y"
                  {(yyval.vox)= new Box((yyvsp[-1].num));}
#line 1414 "parser.cpp"
    break;

  case 29: /* fpar-type: data-type '[' ']' box  */
#line 162 "parser.y"
                        {(yyval.fpartype)= new Fpartype_1((yyvsp[-3].type),(yyvsp[0].vox));}
#line 1420 "parser.cpp"
    break;

  case 30: /* fpar-type: data-type '[' ']'  */
#line 163 "parser.y"
                    {(yyval.fpartype)= new Fpartype_1((yyvsp[-2].type));}
#line 1426 "parser.cpp"
    break;

  case 31: /* fpar-type: data-type box  */
#line 164 "parser.y"
                {(yyval.fpartype)= new Fpartype_2((yyvsp[-1].type),(yyvsp[0].vox));}
#line 1432 "parser.cpp"
    break;

  case 32: /* fpar-type: data-type  */
#line 165 "parser.y"
             {(yyval.fpartype)= new Fpartype_2((yyvsp[0].type));}
#line 1438 "parser.cpp"
    break;

  case 33: /* func-decl: header ';'  */
#line 169 "parser.y"
             {(yyval.funcdecl)=new Funcdecl((yyvsp[-1].head));}
#line 1444 "parser.cpp"
    break;

  case 34: /* var-def: "var" T_id new-def ':' declaration ';'  */
#line 173 "parser.y"
                                         {(yyval.vardef)=new Vardef((yyvsp[-4].RepString),(yyvsp[-1].decl),(yyvsp[-3].newdef));}
#line 1450 "parser.cpp"
    break;

  case 35: /* var-def: "var" T_id ':' declaration ';'  */
#line 174 "parser.y"
                                 {(yyval.vardef)=new Vardef((yyvsp[-3].RepString),(yyvsp[-1].decl));}
#line 1456 "parser.cpp"
    break;

  case 36: /* stmt: ';'  */
#line 178 "parser.y"
      {(yyval.stmts)= new Finish_1();}
#line 1462 "parser.cpp"
    break;

  case 37: /* stmt: l-value "<-" expr ';'  */
#line 179 "parser.y"
                        {(yyval.stmts)= new Stmt_lvalue((yyvsp[-3].lvalue),(yyvsp[-1].exprs));}
#line 1468 "parser.cpp"
    break;

  case 38: /* stmt: block  */
#line 180 "parser.y"
        {(yyval.stmts)= new Stmt_block((yyvsp[0].blocks));}
#line 1474 "parser.cpp"
    break;

  case 39: /* stmt: func-call ';'  */
#line 181 "parser.y"
                {(yyval.stmts)=new Stmt_func((yyvsp[-1].funccall));}
#line 1480 "parser.cpp"
    break;

  case 40: /* stmt: "if" cond "then" stmt  */
#line 182 "parser.y"
                        {(yyval.stmts)= new If((yyvsp[-2].conds),(yyvsp[0].stmts));}
#line 1486 "parser.cpp"
    break;

  case 41: /* stmt: "if" cond "then" stmt "else" stmt  */
#line 183 "parser.y"
                                     {(yyval.stmts)= new If((yyvsp[-4].conds),(yyvsp[-2].stmts),(yyvsp[0].stmts));}
#line 1492 "parser.cpp"
    break;

  case 42: /* stmt: "while" cond "do" stmt  */
#line 184 "parser.y"
                         {(yyval.stmts)= new While((yyvsp[-2].conds),(yyvsp[0].stmts));}
#line 1498 "parser.cpp"
    break;

  case 43: /* stmt: "return" ';'  */
#line 185 "parser.y"
               {(yyval.stmts)= new Finish_2();}
#line 1504 "parser.cpp"
    break;

  case 44: /* stmt: "return" expr ';'  */
#line 186 "parser.y"
                   {(yyval.stmts)=new Finish_2((yyvsp[-1].exprs));}
#line 1510 "parser.cpp"
    break;

  case 45: /* block: '{' sol '}'  */
#line 190 "parser.y"
             {(yyval.blocks)= new Block_default((yyvsp[-1].soll));}
#line 1516 "parser.cpp"
    break;

  case 46: /* block: '{' '}'  */
#line 191 "parser.y"
          {(yyval.blocks)= new Block_default();}
#line 1522 "parser.cpp"
    break;

  case 47: /* sol: stmt  */
#line 195 "parser.y"
       {(yyval.soll)=new Sol((yyvsp[0].stmts));}
#line 1528 "parser.cpp"
    break;

  case 48: /* sol: sol stmt  */
#line 196 "parser.y"
           {(yyval.soll)= new Sol((yyvsp[0].stmts),(yyvsp[-1].soll));}
#line 1534 "parser.cpp"
    break;

  case 49: /* func-call: T_id '(' ')'  */
#line 200 "parser.y"
               {(yyval.funccall)=new Funccall_default((yyvsp[-2].RepString));}
#line 1540 "parser.cpp"
    break;

  case 50: /* func-call: T_id '(' expr komma ')'  */
#line 201 "parser.y"
                         {(yyval.funccall)=new Funccall_default((yyvsp[-4].RepString),(yyvsp[-2].exprs),(yyvsp[-1].comma));}
#line 1546 "parser.cpp"
    break;

  case 51: /* func-call: T_id '(' expr ')'  */
#line 202 "parser.y"
                    {(yyval.funccall)=new Funccall_default((yyvsp[-3].RepString),(yyvsp[-1].exprs));}
#line 1552 "parser.cpp"
    break;

  case 52: /* komma: ',' expr  */
#line 206 "parser.y"
          {(yyval.comma)= new Comma((yyvsp[0].exprs));}
#line 1558 "parser.cpp"
    break;

  case 53: /* komma: ',' expr komma  */
#line 207 "parser.y"
                {(yyval.comma)= new Comma((yyvsp[-1].exprs),(yyvsp[0].comma));}
#line 1564 "parser.cpp"
    break;

  case 54: /* l-value: T_id  */
#line 211 "parser.y"
       {(yyval.lvalue)= new Id((yyvsp[0].RepString));}
#line 1570 "parser.cpp"
    break;

  case 55: /* l-value: T_string  */
#line 212 "parser.y"
           {(yyval.lvalue)= new String((yyvsp[0].RepString));}
#line 1576 "parser.cpp"
    break;

  case 56: /* l-value: l-value '[' expr ']'  */
#line 213 "parser.y"
                       {(yyval.lvalue)=new Lval_expr((yyvsp[-3].lvalue),(yyvsp[-1].exprs));}
#line 1582 "parser.cpp"
    break;

  case 57: /* expr: T_charr  */
#line 217 "parser.y"
          {(yyval.exprs)= new Char((yyvsp[0].var));}
#line 1588 "parser.cpp"
    break;

  case 58: /* expr: T_charra  */
#line 218 "parser.y"
           {(yyval.exprs)= new Chara((yyvsp[0].varr));}
#line 1594 "parser.cpp"
    break;

  case 59: /* expr: T_const  */
#line 219 "parser.y"
          {(yyval.exprs)= new Const((yyvsp[0].num));}
#line 1600 "parser.cpp"
    break;

  case 60: /* expr: l-value  */
#line 220 "parser.y"
          {(yyval.exprs)= new Expr_lval((yyvsp[0].lvalue));}
#line 1606 "parser.cpp"
    break;

  case 61: /* expr: '(' expr ')'  */
#line 221 "parser.y"
               {(yyval.exprs)= (yyvsp[-1].exprs);}
#line 1612 "parser.cpp"
    break;

  case 62: /* expr: '+' expr  */
#line 222 "parser.y"
           {(yyval.exprs)= new Exprplas((yyvsp[0].exprs));}
#line 1618 "parser.cpp"
    break;

  case 63: /* expr: '-' expr  */
#line 223 "parser.y"
           {(yyval.exprs)= new Exprsub((yyvsp[0].exprs));}
#line 1624 "parser.cpp"
    break;

  case 64: /* expr: func-call  */
#line 224 "parser.y"
            {(yyval.exprs)= new Expr_func((yyvsp[0].funccall));}
#line 1630 "parser.cpp"
    break;

  case 65: /* expr: expr '+' expr  */
#line 225 "parser.y"
                {(yyval.exprs)= new BinOp((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1636 "parser.cpp"
    break;

  case 66: /* expr: expr '-' expr  */
#line 226 "parser.y"
                {(yyval.exprs)= new BinOp((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1642 "parser.cpp"
    break;

  case 67: /* expr: expr '*' expr  */
#line 227 "parser.y"
                {(yyval.exprs)= new BinOp((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1648 "parser.cpp"
    break;

  case 68: /* expr: expr "div" expr  */
#line 228 "parser.y"
                  {(yyval.exprs)= new BinOp((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1654 "parser.cpp"
    break;

  case 69: /* expr: expr "mod" expr  */
#line 229 "parser.y"
                  {(yyval.exprs)= new BinOp((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1660 "parser.cpp"
    break;

  case 70: /* cond: '(' cond ')'  */
#line 233 "parser.y"
              {(yyval.conds)=(yyvsp[-1].conds);}
#line 1666 "parser.cpp"
    break;

  case 71: /* cond: "not" cond  */
#line 234 "parser.y"
             {(yyval.conds)= new Cond_st1((yyvsp[0].conds));}
#line 1672 "parser.cpp"
    break;

  case 72: /* cond: cond "and" cond  */
#line 235 "parser.y"
                  {(yyval.conds)= new BinOp_cond((yyvsp[-2].conds),(yyvsp[-1].op),(yyvsp[0].conds));}
#line 1678 "parser.cpp"
    break;

  case 73: /* cond: cond "or" cond  */
#line 236 "parser.y"
                 {(yyval.conds)= new BinOp_cond((yyvsp[-2].conds),(yyvsp[-1].op),(yyvsp[0].conds));}
#line 1684 "parser.cpp"
    break;

  case 74: /* cond: expr '=' expr  */
#line 237 "parser.y"
                {(yyval.conds)= new BinOp_expr((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1690 "parser.cpp"
    break;

  case 75: /* cond: expr '#' expr  */
#line 238 "parser.y"
                {(yyval.conds)= new BinOp_expr((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1696 "parser.cpp"
    break;

  case 76: /* cond: expr '<' expr  */
#line 239 "parser.y"
                {(yyval.conds)= new BinOp_expr((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1702 "parser.cpp"
    break;

  case 77: /* cond: expr '>' expr  */
#line 240 "parser.y"
                {(yyval.conds)= new BinOp_expr((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1708 "parser.cpp"
    break;

  case 78: /* cond: expr "<=" expr  */
#line 241 "parser.y"
                 {(yyval.conds)= new BinOp_expr((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1714 "parser.cpp"
    break;

  case 79: /* cond: expr ">=" expr  */
#line 242 "parser.y"
                 {(yyval.conds)= new BinOp_expr((yyvsp[-2].exprs),(yyvsp[-1].op),(yyvsp[0].exprs));}
#line 1720 "parser.cpp"
    break;


#line 1724 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 244 "parser.y"


int main(){
	int result = yyparse();
	if (result == 0) printf("Success. \n");
	return result;
} 
