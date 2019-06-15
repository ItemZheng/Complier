/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 17 "./rule/parse.y" /* yacc.c:1909  */

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

#line 206 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
