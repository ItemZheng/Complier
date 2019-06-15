/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./rule/parse.y" /* yacc.c:339  */

#include "node.h"
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


#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    SINGLE_COMMENT = 290,
    COMMENTS = 291,
    COLON = 292,
    LEFT_PAREN = 293,
    RIGHT_PAREN = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    LEFT_BRACE = 297,
    RIGHT_BRACE = 298,
    LESS = 299,
    LESS_EQUAL = 300,
    GREATER = 301,
    GREATER_EQUAL = 302,
    PLUS = 303,
    PLUS_PLUS = 304,
    MINUS = 305,
    MINUS_MINUS = 306,
    DIV = 307,
    MOD = 308,
    MUL = 309,
    AND_AND = 310,
    OR_OR = 311,
    EQUAL = 312,
    NOT_EQUAL = 313,
    NOT = 314,
    COMMA = 315,
    SEMI = 316,
    ASSIGN = 317,
    IDENTIFIER = 318,
    INTEGER = 319,
    DOUBLE_NUMBER = 320,
    CHARACTER = 321,
    STRING = 322,
    IFX = 323,
    NEG = 324
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
#define SINGLE_COMMENT 290
#define COMMENTS 291
#define COLON 292
#define LEFT_PAREN 293
#define RIGHT_PAREN 294
#define LEFT_BRACKET 295
#define RIGHT_BRACKET 296
#define LEFT_BRACE 297
#define RIGHT_BRACE 298
#define LESS 299
#define LESS_EQUAL 300
#define GREATER 301
#define GREATER_EQUAL 302
#define PLUS 303
#define PLUS_PLUS 304
#define MINUS 305
#define MINUS_MINUS 306
#define DIV 307
#define MOD 308
#define MUL 309
#define AND_AND 310
#define OR_OR 311
#define EQUAL 312
#define NOT_EQUAL 313
#define NOT 314
#define COMMA 315
#define SEMI 316
#define ASSIGN 317
#define IDENTIFIER 318
#define INTEGER 319
#define DOUBLE_NUMBER 320
#define CHARACTER 321
#define STRING 322
#define IFX 323
#define NEG 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "./rule/parse.y" /* yacc.c:355  */

    std::string  *str;
    Node  *node;
	type_var type;
    vector<DeclarationNode *> *declaration_list;
    vector<FunctionArgNode *> *function_args;
    vector<StatementNode *> *statements;
    vector<ExpressionVNode *> *incrementExpressionList;
    vector<VarDeclNode *> *varDeclarationList;
    vector<ArrayInitNode *> *array_init;
    vector<VarNode *> *var_list;
    vector<LabeledStatementNode *> *labeledStatementList;

#line 275 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 292 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   317

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    71,    74,    81,    87,    90,    93,    96,
      99,   102,   105,   111,   115,   123,   126,   129,   132,   138,
     145,   152,   155,   162,   166,   172,   176,   181,   185,   191,
     194,   197,   200,   203,   206,   209,   212,   215,   218,   221,
     224,   227,   230,   233,   236,   239,   242,   245,   248,   251,
     254,   257,   263,   266,   272,   276,   280,   285,   290,   292,
     299,   302,   311,   314,   320,   323,   329,   335,   341,   344,
     350,   353,   360,   366,   373,   379,   382,   388,   391,   397,
     401,   404,   407,   410,   416,   419,   424,   427,   430,   436,
     439,   444,   448,   453,   456,   462,   464,   471,   474,   477,
     481,   487,   490,   495,   498,   504,   507,   514,   517,   523,
     526,   532,   539,   542,   549,   552
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "LONG", "FLOAT", "SHORT", "VOID",
  "DOUBLE", "CHAR", "UNSIGNED", "CONST", "SIGNED", "STRUCT", "UNION",
  "ENUM", "VOLATILE", "IF", "ELSE", "SWITCH", "GOTO", "CASE", "DO",
  "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN", "DEFAULT", "TYPEDEF",
  "AUTO", "REGISTER", "EXTERN", "STATIC", "SIZEOF", "SINGLE_COMMENT",
  "COMMENTS", "COLON", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "LESS", "LESS_EQUAL",
  "GREATER", "GREATER_EQUAL", "PLUS", "PLUS_PLUS", "MINUS", "MINUS_MINUS",
  "DIV", "MOD", "MUL", "AND_AND", "OR_OR", "EQUAL", "NOT_EQUAL", "NOT",
  "COMMA", "SEMI", "ASSIGN", "IDENTIFIER", "INTEGER", "DOUBLE_NUMBER",
  "CHARACTER", "STRING", "IFX", "NEG", "$accept", "program",
  "declaration_list", "var_declaration", "type", "var_declaration_list",
  "var_decl", "array_identifier", "array_access", "array_init",
  "array_init_list", "expression_list", "expressionv", "expression", "var",
  "constant", "call", "args", "args_list", "declaration",
  "function_declaration", "function_definition", "function_decl",
  "function_args", "function_arg_list", "function_arg", "function_body",
  "function_statements", "return_statement", "statements", "statement",
  "expressionStatement", "iterationStatement", "loopBody",
  "compoundStatement", "forCondition", "forExpression",
  "incrementExpressionList", "forInitList", "forDeclaration",
  "jumpStatement", "selectionStatement", "ifStatement", "ifBody",
  "elseBody", "switchStatement", "labeledStatementList",
  "labeledStatement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     197,  -151,  -151,  -151,  -151,  -151,  -151,  -151,    25,   197,
    -151,   -13,  -151,  -151,  -151,   -34,  -151,  -151,   -31,   -16,
    -151,    -3,   212,  -151,  -151,   197,     3,    76,    19,  -151,
      62,     1,    68,    81,    92,    93,    72,    73,    76,    82,
      76,    82,    76,  -151,   -12,  -151,  -151,  -151,  -151,    19,
    -151,    83,   259,    67,  -151,  -151,   103,   120,   212,  -151,
    -151,  -151,  -151,  -151,  -151,    85,   110,  -151,    98,   118,
    -151,   -22,  -151,    -8,  -151,    76,    76,   212,   137,    76,
     236,  -151,  -151,   123,   124,  -151,  -151,    66,  -151,  -151,
      76,    99,  -151,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,  -151,  -151,    76,  -151,
      76,  -151,  -151,  -151,  -151,   197,  -151,  -151,   -24,   -23,
    -151,   127,   129,   126,   142,   143,    19,   132,   152,   133,
    -151,  -151,  -151,   154,   135,   146,    12,    12,    12,    12,
     -30,   -30,  -151,  -151,  -151,   131,    55,   244,   244,  -151,
     147,  -151,  -151,    62,  -151,    76,   148,   168,  -151,    76,
     148,   136,   148,    76,  -151,    76,  -151,  -151,  -151,  -151,
    -151,  -151,   204,    33,   184,  -151,  -151,  -151,  -151,  -151,
     163,  -151,   148,    56,   188,   183,    33,   166,    76,  -151,
    -151,  -151,   191,   212,  -151,  -151,  -151,   132,  -151,   212,
    -151,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,    10,     8,    11,     9,     7,    12,     0,     2,
      63,     0,     4,    62,    65,     0,     1,     3,    15,     0,
      14,    17,    78,    64,    66,    69,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    52,    54,    55,    56,    79,     0,
      53,     0,    28,    49,    51,    50,     0,    76,    78,    82,
      80,    83,    81,   103,   104,     0,     0,    68,    70,     0,
      16,    15,    13,     0,    18,     0,     0,    78,     0,     0,
      97,   101,   102,     0,    52,    45,    44,    49,    47,    41,
      59,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    48,     0,    73,
       0,    74,    77,    72,    67,     0,    19,    24,     0,     0,
      26,     0,     0,     0,     0,     0,     0,    99,     0,     0,
      98,    34,    61,     0,    58,     0,    35,    36,    37,    38,
      29,    30,    32,    33,    31,    39,    40,    42,    43,    27,
       0,    71,    21,     0,    22,     0,     0,     0,    91,     0,
       0,   100,     0,    94,    57,     0,    20,    75,    23,    25,
     108,   107,   105,   113,     0,    89,    86,    90,    88,    93,
       0,    60,     0,     0,     0,     0,   113,     0,    96,   110,
     109,   106,     0,    78,   111,   112,    87,    95,    92,    78,
     115,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,    38,     4,   104,   205,  -151,  -151,   -68,
    -151,   -77,   -27,    -7,   -25,    49,  -151,  -151,  -151,   237,
    -151,  -151,  -151,  -151,   134,  -151,  -151,  -151,  -151,   -56,
    -150,  -151,  -151,    86,   -32,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,    61,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    48,    49,    19,    20,    21,    50,    74,
     118,   119,    51,    52,    53,    54,    55,   133,   134,    12,
      13,    14,    15,    66,    67,    68,    24,    56,   111,    57,
      58,    59,    60,   176,   177,   128,   180,   198,   129,   130,
      61,    62,    63,   172,   191,    64,   185,   186
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    78,   112,   127,    11,   117,   170,    25,    22,    26,
     175,    83,   175,    11,    85,    87,    88,    87,    26,   152,
     154,   123,    99,   100,   101,    16,    90,    23,    91,    65,
      38,    27,   189,    86,    73,    89,   153,   155,    10,    75,
      27,    39,    40,    41,    28,    29,   120,    10,   121,   122,
      18,    42,   125,   120,   183,    44,    45,    46,    47,    30,
      97,   184,    98,   132,    99,   100,   101,    69,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,   149,    71,   150,   126,   168,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    93,
      94,    95,    96,    97,    73,    98,    76,    99,   100,   101,
     102,   197,   104,   105,    38,   106,   106,   107,   107,    65,
      45,    46,    47,    77,   171,    39,    40,    41,   169,   108,
      79,    80,   174,    81,    82,    42,   179,   200,   181,    44,
      45,    46,    47,   201,    92,    84,   109,   110,   113,   114,
     190,     1,     2,     3,     4,     5,     6,     7,   115,   116,
     124,   120,   131,   135,    91,    31,   156,    32,   157,   158,
      33,    34,    35,    36,    37,    93,    94,    95,    96,    97,
     159,    98,   160,    99,   100,   101,    38,   166,   104,   105,
      77,   162,   155,   164,   163,   165,    28,    39,    40,    41,
       1,     2,     3,     4,     5,     6,     7,    42,   167,    43,
     173,    44,    45,    46,    47,     1,     2,     3,     4,     5,
       6,     7,   182,   187,   188,   193,   194,   196,   199,    31,
     161,    32,   192,    72,    33,    34,    35,    36,    37,     1,
       2,     3,     4,     5,     6,     7,    17,   195,   178,   151,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    43,    38,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    93,    94,
      95,    96,    97,     0,    98,    42,    99,   100,   101,    44,
      45,    46,    47,    93,    94,    95,    96,    97,     0,    98,
       0,    99,   100,   101,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      27,    33,    58,    80,     0,    73,   156,    38,    42,    40,
     160,    38,   162,     9,    39,    40,    41,    42,    40,    43,
      43,    77,    52,    53,    54,     0,    38,    61,    40,    25,
      38,    62,   182,    40,    42,    42,    60,    60,     0,    38,
      62,    49,    50,    51,    60,    61,    73,     9,    75,    76,
      63,    59,    79,    80,    21,    63,    64,    65,    66,    62,
      48,    28,    50,    90,    52,    53,    54,    64,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   108,    63,   110,    80,   153,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    44,
      45,    46,    47,    48,    42,    50,    38,    52,    53,    54,
      55,   188,    57,    58,    38,    49,    49,    51,    51,   115,
      64,    65,    66,    42,   156,    49,    50,    51,   155,    62,
      38,    38,   159,    61,    61,    59,   163,   193,   165,    63,
      64,    65,    66,   199,    61,    63,    43,    27,    63,    39,
     182,     3,     4,     5,     6,     7,     8,     9,    60,    41,
      23,   188,    39,    64,    40,    17,    39,    19,    39,    43,
      22,    23,    24,    25,    26,    44,    45,    46,    47,    48,
      38,    50,    39,    52,    53,    54,    38,    41,    57,    58,
      42,    39,    60,    39,    61,    60,    60,    49,    50,    51,
       3,     4,     5,     6,     7,     8,     9,    59,    61,    61,
      42,    63,    64,    65,    66,     3,     4,     5,     6,     7,
       8,     9,    18,    39,    61,    37,    43,    61,    37,    17,
     126,    19,   183,    28,    22,    23,    24,    25,    26,     3,
       4,     5,     6,     7,     8,     9,     9,   186,   162,   115,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    38,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    44,    45,
      46,    47,    48,    -1,    50,    59,    52,    53,    54,    63,
      64,    65,    66,    44,    45,    46,    47,    48,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    71,    72,
      73,    74,    89,    90,    91,    92,     0,    89,    63,    75,
      76,    77,    42,    61,    96,    38,    40,    62,    60,    61,
      62,    17,    19,    22,    23,    24,    25,    26,    38,    49,
      50,    51,    59,    61,    63,    64,    65,    66,    73,    74,
      78,    82,    83,    84,    85,    86,    97,    99,   100,   101,
     102,   110,   111,   112,   115,    74,    93,    94,    95,    64,
      82,    63,    76,    42,    79,    38,    38,    42,   104,    38,
      38,    61,    61,    82,    63,    84,    83,    84,    84,    83,
      38,    40,    61,    44,    45,    46,    47,    48,    50,    52,
      53,    54,    55,    56,    57,    58,    49,    51,    62,    43,
      27,    98,    99,    63,    39,    60,    41,    79,    80,    81,
      82,    82,    82,    99,    23,    82,    74,    81,   105,   108,
     109,    39,    82,    87,    88,    64,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    82,
      82,    94,    43,    60,    43,    60,    39,    39,    43,    38,
      39,    75,    39,    61,    39,    60,    41,    61,    79,    82,
     100,   104,   113,    42,    82,   100,   103,   104,   103,    82,
     106,    82,    18,    21,    28,   116,   117,    39,    61,   100,
     104,   114,    85,    37,    43,   116,    61,    81,   107,    37,
      99,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    77,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    85,    85,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    92,    93,    93,
      94,    94,    95,    96,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   105,   106,   106,   107,   107,   108,   108,   108,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   116,   116,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     3,     4,
       4,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     0,
       3,     1,     1,     1,     2,     1,     2,     5,     1,     0,
       1,     3,     2,     3,     2,     3,     0,     2,     0,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     1,
       1,     3,     5,     1,     0,     1,     0,     0,     1,     1,
       2,     2,     2,     1,     1,     5,     7,     1,     1,     1,
       1,     7,     2,     0,     4,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 65 "./rule/parse.y" /* yacc.c:1646  */
    {
		// create root
	}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 71 "./rule/parse.y" /* yacc.c:1646  */
    {

 	}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "./rule/parse.y" /* yacc.c:1646  */
    {

 	}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "./rule/parse.y" /* yacc.c:1646  */
    {
	(yyval.node) = new VarDeclarationNode((yyvsp[-2].type), (yyvsp[-1].varDeclarationList));

}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_INT;
	}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_DOUBLE;
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_FLOAT;
	}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_VOID;
	}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_LONG;
	}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_SHORT;
	}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.type) = TYPE_CHAR;
	}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 111 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].varDeclarationList)->push_back((VarDeclNode *)(yyvsp[0].node));
		(yyval.varDeclarationList) = (yyvsp[-2].varDeclarationList);
	}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.varDeclarationList) = new vector<VarDeclNode *>;
		(yyval.varDeclarationList)->push_back((VarDeclNode *)(yyvsp[0].node));
	}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new VarDeclNode(SINGLE, (yyvsp[0].str), NULL, 0, NULL, NULL);
	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new VarDeclNode(SINGLE, (yyvsp[-2].str), NULL, 1, (ExpressionVNode *)(yyvsp[0].node), NULL);
	}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new VarDeclNode(ARRAY, NULL, (ArrayIdentifierNode *)(yyvsp[0].node), 0, NULL, NULL);
	}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new VarDeclNode(ARRAY, NULL, (ArrayIdentifierNode *)(yyvsp[-2].node), 1, NULL, (ArrayInitNode *)(yyvsp[0].node));
	}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 138 "./rule/parse.y" /* yacc.c:1646  */
    {
		int temp = atoi((yyvsp[-1].str)->c_str());
		(yyval.node) = new ArrayIdentifierNode((yyvsp[-3].str), temp);
	}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "./rule/parse.y" /* yacc.c:1646  */
    {
		int temp = atoi((yyvsp[-1].str)->c_str());
		(yyval.node) = new ArrayAccessNode((yyvsp[-3].str), temp);
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 152 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ArrayInitNode((yyvsp[-1].array_init), NULL);
	}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 155 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ArrayInitNode(NULL, (yyvsp[-1].incrementExpressionList));
	}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 162 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].array_init)->push_back((ArrayInitNode *)(yyvsp[-2].array_init));
		(yyval.array_init) = (yyvsp[-2].array_init);
	}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.array_init) = new vector<ArrayInitNode *>;
		(yyval.array_init)->push_back((ArrayInitNode *)(yyvsp[0].node));
	}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 172 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].incrementExpressionList)->push_back((ExpressionVNode *)(yyvsp[0].node));
		(yyval.incrementExpressionList) = (yyvsp[-2].incrementExpressionList);
}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.incrementExpressionList) = new vector<ExpressionVNode *>;
		(yyval.incrementExpressionList)->push_back((ExpressionVNode *)(yyvsp[0].node));
	}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 181 "./rule/parse.y" /* yacc.c:1646  */
    {
		((ExpressionVNode *)(yyvsp[0].node))->var_list->push_back((VarNode *)(yyvsp[-2].node));
		(yyval.node) = (yyvsp[0].node);
	}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 185 "./rule/parse.y" /* yacc.c:1646  */
    {
		vector<VarNode *> *temp = new vector<VarNode *>;
		(yyval.node) = new ExpressionVNode(temp, (ExpressionNode *)(yyvsp[0].node));
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_PLUS, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 194 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_MINUS, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 197 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_MUL, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 200 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_DIV, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 203 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_MOD, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 206 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 209 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_LESS, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_LESS_EQUAL, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 215 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_GREATER, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 218 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_GREATER_EQUAL, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 221 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_AND_AND, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 224 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_OR_OR, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 227 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_NOT, (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL, NULL);
	}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 230 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_EQUAL, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 233 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_NOT_EQUAL, (ExpressionNode *)(yyvsp[-2].node), (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL);
	}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 236 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_MINUS_SIGN, (ExpressionNode *)(yyvsp[0].node), NULL, NULL, NULL, NULL);
	}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 239 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_PLUS_PLUS_L, NULL, NULL, (VarNode *)(yyvsp[0].node), NULL, NULL);
	}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 242 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_PLUS_PLUS_R, NULL, NULL, (VarNode *)(yyvsp[-1].node), NULL, NULL);
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 245 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_MINUS_MINUS_L, NULL, NULL, (VarNode *)(yyvsp[0].node), NULL, NULL);
	}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_MINUS_MINUS_R, NULL, NULL, (VarNode *)(yyvsp[-1].node), NULL, NULL);
	}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 251 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_VAR, NULL, NULL, (VarNode *)(yyvsp[0].node), NULL, NULL);
	}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 254 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_CALL, NULL, NULL, NULL, NULL, (CallNode *)(yyvsp[0].node));
	}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 257 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new ExpressionNode(EXP_CONST, NULL, NULL, NULL,(ConstantNode *)(yyvsp[0].node), NULL);
	}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 263 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new VarNode(SINGLE, (yyvsp[0].str), NULL);
	}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 266 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.node) = new VarNode(SINGLE, NULL, (ArrayAccessNode *)(yyvsp[0].node));
	}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 272 "./rule/parse.y" /* yacc.c:1646  */
    {
		int temp = atoi((yyvsp[0].str)->c_str());
		(yyval.node) = new ConstantNode(TYPE_INT, temp, 0, '0');
	}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 276 "./rule/parse.y" /* yacc.c:1646  */
    {
		double temp = atof((yyvsp[0].str)->c_str());
		(yyval.node) = new ConstantNode(TYPE_DOUBLE, 0, temp, '0');
	}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 280 "./rule/parse.y" /* yacc.c:1646  */
    {
		char temp = (*((yyvsp[0].str)))[1];
		(yyval.node) = new ConstantNode(TYPE_CHAR, 0, 0, temp);
	}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 285 "./rule/parse.y" /* yacc.c:1646  */
    {
	(yyval.node) = new CallNode((yyvsp[-3].str), (yyvsp[-1].incrementExpressionList));
}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 290 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.incrementExpressionList) = (yyvsp[0].incrementExpressionList);
	}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 292 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.incrementExpressionList) = NULL;
	}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 299 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].incrementExpressionList)->push_back((ExpressionVNode *)(yyvsp[0].node));
		(yyval.incrementExpressionList) = (yyvsp[-2].incrementExpressionList);
	}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 302 "./rule/parse.y" /* yacc.c:1646  */
    {
		(yyval.incrementExpressionList) = new vector<ExpressionVNode *>;
		(yyval.incrementExpressionList)->push_back((ExpressionVNode *)(yyvsp[0].node));
	}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 311 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 314 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 320 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 323 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 329 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 335 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 341 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 344 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 350 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 353 "./rule/parse.y" /* yacc.c:1646  */
    {

        }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 360 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 366 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 373 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 379 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 382 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 388 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 391 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 397 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 401 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 404 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 407 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 410 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 416 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 419 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 424 "./rule/parse.y" /* yacc.c:1646  */
    {

    }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 427 "./rule/parse.y" /* yacc.c:1646  */
    {

    }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 430 "./rule/parse.y" /* yacc.c:1646  */
    {

    }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 436 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 439 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 444 "./rule/parse.y" /* yacc.c:1646  */
    {

}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 448 "./rule/parse.y" /* yacc.c:1646  */
    {

}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 453 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 456 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 462 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 464 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 471 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 474 "./rule/parse.y" /* yacc.c:1646  */
    {

  	}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 477 "./rule/parse.y" /* yacc.c:1646  */
    {

  	}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 481 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 487 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 490 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 495 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 498 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 504 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 507 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 514 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 517 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 523 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 526 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 532 "./rule/parse.y" /* yacc.c:1646  */
    {

 	}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 539 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 542 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 549 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 552 "./rule/parse.y" /* yacc.c:1646  */
    {

	}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2481 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 556 "./rule/parse.y" /* yacc.c:1906  */


int yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "Parser error near %s at line %d\n", yytext, yylineno);
    return 0;
}

int main(void)
{
//	# define YYDEBUG 1
//	yydebug = 1;
    yyin = stdin;
    if (yyparse()) {
        exit(1);
    }
}
