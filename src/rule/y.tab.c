/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     LONG = 259,
     FLOAT = 260,
     SHORT = 261,
     VOID = 262,
     DOUBLE = 263,
     CHAR = 264,
     UNSIGNED = 265,
     CONST = 266,
     SIGNED = 267,
     STRUCT = 268,
     UNION = 269,
     ENUM = 270,
     VOLATILE = 271,
     IF = 272,
     ELSE = 273,
     SWITCH = 274,
     GOTO = 275,
     CASE = 276,
     DO = 277,
     WHILE = 278,
     FOR = 279,
     CONTINUE = 280,
     BREAK = 281,
     RETURN = 282,
     DEFAULT = 283,
     TYPEDEF = 284,
     AUTO = 285,
     REGISTER = 286,
     EXTERN = 287,
     STATIC = 288,
     SIZEOF = 289,
     IDENTIFIER = 290,
     INTEGER = 291,
     DOUBLE_NUMBER = 292,
     CHARACTER = 293,
     STRING = 294,
     SINGLE_COMMENT = 295,
     COMMENTS = 296,
     COLON = 297,
     LEFT_PAREN = 298,
     RIGHT_PAREN = 299,
     LEFT_BRACKET = 300,
     RIGHT_BRACKET = 301,
     LEFT_BRACE = 302,
     RIGHT_BRACE = 303,
     LESS = 304,
     LESS_EQUAL = 305,
     GREATER = 306,
     GREATER_EQUAL = 307,
     PLUS = 308,
     PLUS_PLUS = 309,
     MINUS = 310,
     MINUS_MINUS = 311,
     DIV = 312,
     MOD = 313,
     MUL = 314,
     AND_AND = 315,
     OR_OR = 316,
     EQUAL = 317,
     NOT_EQUAL = 318,
     NOT = 319,
     COMMA = 320,
     SEMI = 321,
     ASSIGN = 322,
     NEG = 323
   };
#endif
/* Tokens.  */
#define INT 258
#define LONG 259
#define FLOAT 260
#define SHORT 261
#define VOID 262
#define DOUBLE 263
#define CHAR 264
#define UNSIGNED 265
#define CONST 266
#define SIGNED 267
#define STRUCT 268
#define UNION 269
#define ENUM 270
#define VOLATILE 271
#define IF 272
#define ELSE 273
#define SWITCH 274
#define GOTO 275
#define CASE 276
#define DO 277
#define WHILE 278
#define FOR 279
#define CONTINUE 280
#define BREAK 281
#define RETURN 282
#define DEFAULT 283
#define TYPEDEF 284
#define AUTO 285
#define REGISTER 286
#define EXTERN 287
#define STATIC 288
#define SIZEOF 289
#define IDENTIFIER 290
#define INTEGER 291
#define DOUBLE_NUMBER 292
#define CHARACTER 293
#define STRING 294
#define SINGLE_COMMENT 295
#define COMMENTS 296
#define COLON 297
#define LEFT_PAREN 298
#define RIGHT_PAREN 299
#define LEFT_BRACKET 300
#define RIGHT_BRACKET 301
#define LEFT_BRACE 302
#define RIGHT_BRACE 303
#define LESS 304
#define LESS_EQUAL 305
#define GREATER 306
#define GREATER_EQUAL 307
#define PLUS 308
#define PLUS_PLUS 309
#define MINUS 310
#define MINUS_MINUS 311
#define DIV 312
#define MOD 313
#define MUL 314
#define AND_AND 315
#define OR_OR 316
#define EQUAL 317
#define NOT_EQUAL 318
#define NOT 319
#define COMMA 320
#define SEMI 321
#define ASSIGN 322
#define NEG 323




/* Copy the first part of user declarations.  */
#line 1 "parse.y"

#include <math.h>
#include <string>
#include <iostream>
#define YYDEBUG 1

using namespace std;
int yyerror(char const *str);
/* from .l file */
extern int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "parse.y"
{
    int          int_value;
    double       double_value;
    std::string  *str;
    // TODO
}
/* Line 193 of yacc.c.  */
#line 255 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 268 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    16,    18,    20,
      22,    24,    26,    28,    32,    34,    36,    40,    42,    47,
      51,    55,    59,    63,    67,    71,    75,    79,    83,    87,
      91,    95,    98,   102,   106,   109,   113,   116,   119,   122,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   146,
     148,   149,   153,   155,   157,   159,   161,   163,   166,   169,
     175,   177,   178,   180,   184,   187,   191,   194,   198,   199,
     202,   203,   205,   207,   209,   211,   214,   216,   222,   230,
     236,   238,   240,   242,   246,   252,   254,   255,   257,   258,
     262,   264,   265,   267,   269,   272,   275,   278,   280,   282,
     288,   296,   298,   300,   302,   304,   312,   315,   316,   321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    -1,    71,    83,    -1,    83,    -1,
      73,    74,    66,    -1,     3,    -1,     8,    -1,     5,    -1,
       7,    -1,     4,    -1,     6,    -1,     9,    -1,    74,    65,
      75,    -1,    75,    -1,    35,    -1,    35,    67,    77,    -1,
      76,    -1,    35,    45,    36,    46,    -1,    77,    53,    77,
      -1,    77,    55,    77,    -1,    77,    59,    77,    -1,    77,
      57,    77,    -1,    77,    58,    77,    -1,    43,    77,    44,
      -1,    77,    49,    77,    -1,    77,    50,    77,    -1,    77,
      51,    77,    -1,    77,    52,    77,    -1,    77,    60,    77,
      -1,    77,    61,    77,    -1,    64,    77,    -1,    77,    62,
      77,    -1,    77,    63,    77,    -1,    55,    77,    -1,    78,
      67,    77,    -1,    54,    78,    -1,    78,    54,    -1,    56,
      78,    -1,    78,    56,    -1,    78,    -1,    80,    -1,    79,
      -1,    35,    -1,    76,    -1,    36,    -1,    37,    -1,    38,
      -1,    35,    43,    81,    44,    -1,    82,    -1,    -1,    82,
      65,    77,    -1,    77,    -1,    84,    -1,    72,    -1,    85,
      -1,    86,    -1,    87,    66,    -1,    87,    91,    -1,    73,
      35,    43,    88,    44,    -1,    89,    -1,    -1,    90,    -1,
      90,    65,    89,    -1,    73,    35,    -1,    47,    92,    48,
      -1,    94,    93,    -1,    27,    35,    66,    -1,    -1,    95,
      94,    -1,    -1,    97,    -1,   107,    -1,    96,    -1,   106,
      -1,    77,    66,    -1,    66,    -1,    23,    43,    77,    44,
      98,    -1,    22,    99,    23,    43,    77,    44,    66,    -1,
      24,    43,   100,    44,    98,    -1,    95,    -1,    99,    -1,
      66,    -1,    47,    94,    48,    -1,   104,    66,   101,    66,
     102,    -1,    77,    -1,    -1,   103,    -1,    -1,    77,    65,
     103,    -1,    77,    -1,    -1,   105,    -1,   103,    -1,    73,
      74,    -1,    25,    66,    -1,    26,    66,    -1,   108,    -1,
     111,    -1,    17,    43,    77,    44,   109,    -1,    17,    43,
      77,    44,   109,    18,   110,    -1,    99,    -1,    95,    -1,
      99,    -1,    95,    -1,    19,    43,    77,    44,    47,   112,
      48,    -1,   113,   112,    -1,    -1,    21,    79,    42,    94,
      -1,    28,    42,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    43,    46,    53,    58,    61,    64,    67,
      70,    73,    76,    82,    85,    92,    95,    98,   107,   137,
     140,   143,   146,   149,   152,   155,   158,   161,   164,   167,
     170,   173,   176,   179,   182,   185,   188,   191,   194,   197,
     200,   203,   206,   212,   215,   221,   224,   227,   231,   236,
     238,   245,   247,   255,   258,   264,   267,   273,   279,   285,
     291,   294,   300,   303,   310,   316,   323,   329,   332,   338,
     341,   347,   350,   353,   356,   362,   365,   370,   373,   376,
     382,   385,   388,   392,   396,   401,   404,   410,   412,   418,
     421,   427,   430,   433,   437,   443,   446,   451,   454,   460,
     463,   470,   473,   479,   482,   488,   495,   498,   505,   508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "LONG", "FLOAT", "SHORT", "VOID",
  "DOUBLE", "CHAR", "UNSIGNED", "CONST", "SIGNED", "STRUCT", "UNION",
  "ENUM", "VOLATILE", "IF", "ELSE", "SWITCH", "GOTO", "CASE", "DO",
  "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN", "DEFAULT", "TYPEDEF",
  "AUTO", "REGISTER", "EXTERN", "STATIC", "SIZEOF", "IDENTIFIER",
  "INTEGER", "DOUBLE_NUMBER", "CHARACTER", "STRING", "SINGLE_COMMENT",
  "COMMENTS", "COLON", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "LESS", "LESS_EQUAL",
  "GREATER", "GREATER_EQUAL", "PLUS", "PLUS_PLUS", "MINUS", "MINUS_MINUS",
  "DIV", "MOD", "MUL", "AND_AND", "OR_OR", "EQUAL", "NOT_EQUAL", "NOT",
  "COMMA", "SEMI", "ASSIGN", "NEG", "$accept", "program",
  "declaration_list", "var_declaration", "type", "var_declaration_list",
  "var_decl", "array_identifier", "expression", "var", "constant", "call",
  "args", "args_list", "declaration", "function_declaration",
  "function_declaration_only", "function_definition", "function_decl",
  "function_args", "function_arg_list", "function_arg", "function_body",
  "function_statements", "return_statement", "statements", "statement",
  "expressionStatement", "iterationStatement", "loopBody",
  "compoundStatement", "forCondition", "forExpression",
  "incrementExpressionList", "expressions", "forInitList",
  "forDeclaration", "jumpStatement", "selectionStatement", "ifStatement",
  "ifBody", "elseBody", "switchStatement", "labeledStatementList",
  "labeledStatement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    75,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    79,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    87,
      88,    88,    89,    89,    90,    91,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      98,    98,    98,    99,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   112,   112,   113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     3,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       0,     3,     1,     1,     1,     1,     1,     2,     2,     5,
       1,     0,     1,     3,     2,     3,     2,     3,     0,     2,
       0,     1,     1,     1,     1,     2,     1,     5,     7,     5,
       1,     1,     1,     3,     5,     1,     0,     1,     0,     3,
       1,     0,     1,     1,     2,     2,     2,     1,     1,     5,
       7,     1,     1,     1,     1,     7,     2,     0,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,    10,     8,    11,     9,     7,    12,     0,     2,
      54,     0,     4,    53,    55,    56,     0,     1,     3,    15,
       0,    14,    17,    70,    57,    58,    61,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,    43,    45,
      46,    47,     0,     0,     0,     0,     0,    76,    44,     0,
      40,    42,    41,     0,    68,    70,    73,    71,    74,    72,
      97,    98,     0,     0,    60,    62,     0,    16,    15,    13,
       0,     0,    70,     0,     0,    91,    95,    96,    50,     0,
      43,    36,    34,    38,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    37,
      39,     0,    65,     0,    66,    69,    64,    59,     0,    18,
       0,     0,     0,     0,     0,     0,    90,     0,    93,     0,
      92,    52,     0,    49,    24,    25,    26,    27,    28,    19,
      20,    22,    23,    21,    29,    30,    32,    33,    35,     0,
      63,     0,     0,    83,     0,     0,    94,     0,     0,    86,
      48,     0,    67,   102,   101,    99,   107,     0,    76,    80,
      77,    81,    89,    79,    85,     0,    51,     0,     0,     0,
       0,   107,     0,    88,   104,   103,   100,     0,    70,   105,
     106,    78,    84,    87,    70,   109,   108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    20,    21,    48,    49,    50,
      51,    52,   122,   123,    12,    13,    14,    15,    16,    63,
      64,    65,    25,    53,   104,    54,    55,    56,    57,   160,
     161,   117,   165,   182,   118,   119,   120,    58,    59,    60,
     155,   176,    61,   170,   171
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -139
static const yytype_int16 yypact[] =
{
     143,  -139,  -139,  -139,  -139,  -139,  -139,  -139,    33,   143,
    -139,     1,  -139,  -139,  -139,  -139,   -18,  -139,  -139,   -23,
     -54,  -139,  -139,   183,  -139,  -139,   143,    15,   -30,     2,
    -139,    12,    13,    -2,    28,    31,    19,    21,     9,  -139,
    -139,  -139,   -30,    41,   -30,    41,   -30,  -139,  -139,   296,
     -39,  -139,  -139,    30,    52,   183,  -139,  -139,  -139,  -139,
    -139,  -139,    53,    45,  -139,    25,    46,   331,   -35,  -139,
     -30,   -30,   183,    68,   -30,   133,  -139,  -139,   -30,   201,
      54,  -139,   346,  -139,   331,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,  -139,  -139,
    -139,   -30,  -139,    62,  -139,  -139,  -139,  -139,   143,  -139,
     221,   241,    50,    57,   261,     2,   314,    59,  -139,    36,
    -139,   331,    60,    43,  -139,   331,   331,   331,   331,   331,
     346,   331,   331,   331,   331,   331,   331,   331,   331,    40,
    -139,    58,    63,  -139,   -30,   137,    55,   -30,   137,   -30,
    -139,   -30,  -139,  -139,  -139,    93,    10,   281,  -139,  -139,
    -139,  -139,  -139,  -139,   331,    49,   331,    58,     3,    75,
      70,    10,    61,   -30,  -139,  -139,  -139,    84,   183,  -139,
    -139,  -139,  -139,  -139,   183,  -139,  -139
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,   -22,    14,    99,    -8,   -28,    27,
     -38,  -139,  -139,  -139,   123,  -139,  -139,  -139,  -139,  -139,
      26,  -139,  -139,  -139,  -139,   -53,  -118,  -139,  -139,   -15,
     -32,  -139,  -139,  -139,  -138,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,   -27,  -139
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      67,    73,   105,    22,    62,    38,    39,    40,    41,   162,
      27,    29,    30,    42,    79,    99,    82,   100,    84,   112,
      26,    22,    27,   153,    43,    44,    45,   159,   101,    23,
     159,   168,    28,    17,    46,   183,    19,    68,   169,    39,
      40,    41,   110,   111,    28,    72,   114,   116,    24,   174,
     121,    66,    78,   115,    27,    70,    71,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      81,    74,    83,   138,    75,    31,    80,    32,   102,   103,
      33,    34,    35,    36,    37,    76,    62,    77,   106,   107,
     108,   113,   109,    38,    39,    40,    41,   139,   143,    27,
     144,    42,   149,   148,   150,    72,   152,    22,   151,   154,
     156,   167,    43,    44,    45,   173,   157,   178,   179,   116,
      29,   164,    46,   166,    47,   185,   184,   181,    69,   146,
     177,   186,    18,   163,   140,   175,     1,     2,     3,     4,
       5,     6,     7,     0,   180,   116,     1,     2,     3,     4,
       5,     6,     7,     0,    31,     0,    32,     0,     0,    33,
      34,    35,    36,    37,     0,     0,     0,     0,    38,    39,
      40,    41,    38,    39,    40,    41,    42,     0,     0,     0,
      42,     0,     0,     0,    72,     0,     0,    43,    44,    45,
       0,    43,    44,    45,     0,     0,     0,    46,     0,     0,
      31,    46,    32,   158,     0,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
       0,     0,     0,     0,     0,   124,     0,    46,     0,    47,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,   141,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,   142,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,   145,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,   172,     0,     0,     0,     0,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,    93,    94,    95,    96,    97,
       0,     0,    98,    85,    86,    87,    88,    89,     0,    90,
       0,    91,    92,    93,    94,    95,    96,    97,     0,   147,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,    94,    95,    96,    97,    85,    86,    87,    88,    89,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97
};

static const yytype_int16 yycheck[] =
{
      28,    33,    55,    11,    26,    35,    36,    37,    38,   147,
      45,    65,    66,    43,    42,    54,    44,    56,    46,    72,
      43,    29,    45,   141,    54,    55,    56,   145,    67,    47,
     148,    21,    67,     0,    64,   173,    35,    35,    28,    36,
      37,    38,    70,    71,    67,    47,    74,    75,    66,   167,
      78,    36,    43,    75,    45,    43,    43,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      43,    43,    45,   101,    43,    17,    35,    19,    48,    27,
      22,    23,    24,    25,    26,    66,   108,    66,    35,    44,
      65,    23,    46,    35,    36,    37,    38,    35,    48,    45,
      43,    43,    66,    44,    44,    47,    66,   115,    65,   141,
      47,    18,    54,    55,    56,    66,   144,    42,    48,   147,
      65,   149,    64,   151,    66,   178,    42,    66,    29,   115,
     168,   184,     9,   148,   108,   167,     3,     4,     5,     6,
       7,     8,     9,    -1,   171,   173,     3,     4,     5,     6,
       7,     8,     9,    -1,    17,    -1,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    35,    36,    37,    38,    43,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    54,    55,    56,
      -1,    54,    55,    56,    -1,    -1,    -1,    64,    -1,    -1,
      17,    64,    19,    66,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    64,    -1,    66,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    44,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    49,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    66,    49,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    70,    71,
      72,    73,    83,    84,    85,    86,    87,     0,    83,    35,
      74,    75,    76,    47,    66,    91,    43,    45,    67,    65,
      66,    17,    19,    22,    23,    24,    25,    26,    35,    36,
      37,    38,    43,    54,    55,    56,    64,    66,    76,    77,
      78,    79,    80,    92,    94,    95,    96,    97,   106,   107,
     108,   111,    73,    88,    89,    90,    36,    77,    35,    75,
      43,    43,    47,    99,    43,    43,    66,    66,    43,    77,
      35,    78,    77,    78,    77,    49,    50,    51,    52,    53,
      55,    57,    58,    59,    60,    61,    62,    63,    66,    54,
      56,    67,    48,    27,    93,    94,    35,    44,    65,    46,
      77,    77,    94,    23,    77,    73,    77,   100,   103,   104,
     105,    77,    81,    82,    44,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    35,
      89,    44,    44,    48,    43,    44,    74,    65,    44,    66,
      44,    65,    66,    95,    99,   109,    47,    77,    66,    95,
      98,    99,   103,    98,    77,   101,    77,    18,    21,    28,
     112,   113,    44,    66,    95,    99,   110,    79,    42,    48,
     112,    66,   102,   103,    42,    94,    94
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 38 "parse.y"
    {
		// create root
	}
    break;

  case 3:
#line 43 "parse.y"
    {

 	}
    break;

  case 4:
#line 46 "parse.y"
    {

 	}
    break;

  case 5:
#line 53 "parse.y"
    {

}
    break;

  case 6:
#line 58 "parse.y"
    {

	}
    break;

  case 7:
#line 61 "parse.y"
    {

	}
    break;

  case 8:
#line 64 "parse.y"
    {

	}
    break;

  case 9:
#line 67 "parse.y"
    {

	}
    break;

  case 10:
#line 70 "parse.y"
    {

	}
    break;

  case 11:
#line 73 "parse.y"
    {

	}
    break;

  case 12:
#line 76 "parse.y"
    {

	}
    break;

  case 13:
#line 82 "parse.y"
    {

	}
    break;

  case 14:
#line 85 "parse.y"
    {

	}
    break;

  case 15:
#line 92 "parse.y"
    {

	}
    break;

  case 16:
#line 95 "parse.y"
    {

	}
    break;

  case 17:
#line 98 "parse.y"
    {

	}
    break;

  case 18:
#line 107 "parse.y"
    {

	}
    break;

  case 19:
#line 137 "parse.y"
    {

	}
    break;

  case 20:
#line 140 "parse.y"
    {

	}
    break;

  case 21:
#line 143 "parse.y"
    {

	}
    break;

  case 22:
#line 146 "parse.y"
    {

	}
    break;

  case 23:
#line 149 "parse.y"
    {

	}
    break;

  case 24:
#line 152 "parse.y"
    {

	}
    break;

  case 25:
#line 155 "parse.y"
    {

	}
    break;

  case 26:
#line 158 "parse.y"
    {

	}
    break;

  case 27:
#line 161 "parse.y"
    {

	}
    break;

  case 28:
#line 164 "parse.y"
    {

	}
    break;

  case 29:
#line 167 "parse.y"
    {

	}
    break;

  case 30:
#line 170 "parse.y"
    {

	}
    break;

  case 31:
#line 173 "parse.y"
    {

	}
    break;

  case 32:
#line 176 "parse.y"
    {

	}
    break;

  case 33:
#line 179 "parse.y"
    {

	}
    break;

  case 34:
#line 182 "parse.y"
    {

	}
    break;

  case 35:
#line 185 "parse.y"
    {

	}
    break;

  case 36:
#line 188 "parse.y"
    {

	}
    break;

  case 37:
#line 191 "parse.y"
    {

	}
    break;

  case 38:
#line 194 "parse.y"
    {

	}
    break;

  case 39:
#line 197 "parse.y"
    {

	}
    break;

  case 40:
#line 200 "parse.y"
    {

	}
    break;

  case 41:
#line 203 "parse.y"
    {

	}
    break;

  case 42:
#line 206 "parse.y"
    {

	}
    break;

  case 43:
#line 212 "parse.y"
    {

	}
    break;

  case 44:
#line 215 "parse.y"
    {

	}
    break;

  case 45:
#line 221 "parse.y"
    {

	}
    break;

  case 46:
#line 224 "parse.y"
    {

	}
    break;

  case 47:
#line 227 "parse.y"
    {

	}
    break;

  case 48:
#line 231 "parse.y"
    {

}
    break;

  case 49:
#line 236 "parse.y"
    {

	}
    break;

  case 50:
#line 238 "parse.y"
    {

	}
    break;

  case 51:
#line 245 "parse.y"
    {

	}
    break;

  case 52:
#line 247 "parse.y"
    {

	}
    break;

  case 53:
#line 255 "parse.y"
    {

	}
    break;

  case 54:
#line 258 "parse.y"
    {

	}
    break;

  case 55:
#line 264 "parse.y"
    {

	}
    break;

  case 56:
#line 267 "parse.y"
    {

	}
    break;

  case 57:
#line 273 "parse.y"
    {

	}
    break;

  case 58:
#line 279 "parse.y"
    {

	}
    break;

  case 59:
#line 285 "parse.y"
    {

	}
    break;

  case 60:
#line 291 "parse.y"
    {

	}
    break;

  case 61:
#line 294 "parse.y"
    {

	}
    break;

  case 62:
#line 300 "parse.y"
    {

	}
    break;

  case 63:
#line 303 "parse.y"
    {

        }
    break;

  case 64:
#line 310 "parse.y"
    {

	}
    break;

  case 65:
#line 316 "parse.y"
    {

	}
    break;

  case 66:
#line 323 "parse.y"
    {

	}
    break;

  case 67:
#line 329 "parse.y"
    {

	}
    break;

  case 68:
#line 332 "parse.y"
    {

	}
    break;

  case 69:
#line 338 "parse.y"
    {

	}
    break;

  case 70:
#line 341 "parse.y"
    {

	}
    break;

  case 71:
#line 347 "parse.y"
    {

	}
    break;

  case 72:
#line 350 "parse.y"
    {

	}
    break;

  case 73:
#line 353 "parse.y"
    {

	}
    break;

  case 74:
#line 356 "parse.y"
    {

	}
    break;

  case 75:
#line 362 "parse.y"
    {

	}
    break;

  case 76:
#line 365 "parse.y"
    {

	}
    break;

  case 77:
#line 370 "parse.y"
    {

    }
    break;

  case 78:
#line 373 "parse.y"
    {

    }
    break;

  case 79:
#line 376 "parse.y"
    {

    }
    break;

  case 80:
#line 382 "parse.y"
    {

	}
    break;

  case 81:
#line 385 "parse.y"
    {

	}
    break;

  case 82:
#line 388 "parse.y"
    {

	}
    break;

  case 83:
#line 392 "parse.y"
    {

}
    break;

  case 84:
#line 396 "parse.y"
    {

}
    break;

  case 85:
#line 401 "parse.y"
    {

	}
    break;

  case 86:
#line 404 "parse.y"
    {

	}
    break;

  case 87:
#line 410 "parse.y"
    {

	}
    break;

  case 88:
#line 412 "parse.y"
    {

	}
    break;

  case 89:
#line 418 "parse.y"
    {

	}
    break;

  case 90:
#line 421 "parse.y"
    {

	}
    break;

  case 91:
#line 427 "parse.y"
    {

	}
    break;

  case 92:
#line 430 "parse.y"
    {

  	}
    break;

  case 93:
#line 433 "parse.y"
    {

  	}
    break;

  case 94:
#line 437 "parse.y"
    {

	}
    break;

  case 95:
#line 443 "parse.y"
    {

	}
    break;

  case 96:
#line 446 "parse.y"
    {

	}
    break;

  case 97:
#line 451 "parse.y"
    {

	}
    break;

  case 98:
#line 454 "parse.y"
    {

	}
    break;

  case 99:
#line 460 "parse.y"
    {

	}
    break;

  case 100:
#line 463 "parse.y"
    {

	}
    break;

  case 101:
#line 470 "parse.y"
    {

	}
    break;

  case 102:
#line 473 "parse.y"
    {

	}
    break;

  case 103:
#line 479 "parse.y"
    {

	}
    break;

  case 104:
#line 482 "parse.y"
    {

	}
    break;

  case 105:
#line 488 "parse.y"
    {

 	}
    break;

  case 106:
#line 495 "parse.y"
    {

	}
    break;

  case 107:
#line 498 "parse.y"
    {

	}
    break;

  case 108:
#line 505 "parse.y"
    {

	}
    break;

  case 109:
#line 508 "parse.y"
    {

	}
    break;


/* Line 1267 of yacc.c.  */
#line 2451 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 512 "parse.y"


int yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "Parser error near %s at line %d\n", yytext, yylineno);
    return 0;
}

int main(void)
{
    yyin = stdin;
    if (yyparse()) {
        exit(1);
    }
}
