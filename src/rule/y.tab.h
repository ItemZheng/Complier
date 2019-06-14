/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "parse.y"
{
    int          int_value;
    double       double_value;
    std::string  *str;
    // TODO
}
/* Line 1529 of yacc.c.  */
#line 192 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

