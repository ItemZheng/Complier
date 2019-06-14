/*
    *FILE: lexer.l
    *AUTHORS: Bosswang & Itemzheng

    *PURPOSE: Flex file for lexical analysis
*/

%option noyywrap
%{
    #include <stdio.h>
    #include "parser.tab.h"
    #include <string>
%}

white [ \t\n\r]+
space [ \t]
letter [A-Za-z]
digit [0-9]
escapesequence \\[bfnrt"\\]
integer [1-9]([0-9])*|0
id ({letter}|_)({letter}|{digit}|_)*
float {integer}\.([0-9])*
character '([^\\\r\n]|{escapesequence})'
str \"([^"\\\r\n]|{escapesequence})*\"

%x MULTICOMMENT SINGLECOMMENT

%%

{white}

"int"           {return INT;}
"long"          {return LONG;}
"float"         {return FLOAT;}
"short"         {return SHORT;}
"void"          {return VOID;}
"double"        {return DOUBLE;}
"char"          {return CHAR;}
"unsigned"      {return UNSIGNED;}
"const"         {return CONST;}
"signed"        {return SIGNED;}
"struct"        {return STRUCT;}
"union"         {return UNION;}
"enum"          {return ENUM;}
"volatile"      {return VOLATILE;}
"if"            {return IF;}
"else"          {return ELSE;}
"switch"        {return SWITCH;}
"goto"          {return GOTO;}
"case"          {return CASE;}
"do"            {return DO;}
"while"         {return WHILE;}
"for"           {return FOR;}
"continue"      {return CONTINUE;}
"break"         {return BREAK;}
"return"        {return RETURN;}
"default"       {return DEFAULT;}
"typedef"       {return TYPEDEF;}
"auto"          {return AUTO;}
"register"      {return REGISTER;}
"extern"        {return EXTERN;}
"static"        {return STATIC;}
"sizeof"        {return SIZEOF;}

"("             {return LEFT_PAREN;}
")"             {return RIGHT_PAREN;}
"["             {return LEFT_BRACKET;}
"]"             {return RIGHT_BRACKET;}
"{"             {return LEFT_BRACE;}
"}"             {return RIGHT_BRACE;}
"<"             {return LESS;}
"<="            {return LESS_EQUAL;}
">"             {return GREATER;}
">="            {return GREATER_EQUAL;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return MUL;}
"/"             {return DIV;}
"%"             {return MOD;}
"++"            {return PLUS_PLUS;}
"--"            {return MINUS_MINUS;}
"&&"            {return AND_AND;}
"||"            {return OR_OR;}
"=="            {return EQUAL;}
"!="            {return NOT_EQUAL;}
"!"             {return NOT;}
","             {return COMMA;}
";"             {return SEMI;}
"="             {return ASSIGN;}
":"             {return COLON;}

"//"            {BEGIN(SINGLECOMMENT);}
<SINGLECOMMENT>[^\n]
<SINGLECOMMENT>\n {BEGIN(INITIAL);}
"/*"            {BEGIN(MULTICOMMENT);}
<MULTICOMMENT>[^*\n]+ 
<MULTICOMMENT>"*" 
<MULTICOMMENT>\n 
<MULTICOMMENT>"*/" {BEGIN(INITIAL);}

{id} {
    yylval.str = new std::string(yytext, yyleng);
    return IDENTIFIER;
}

{integer} {
    yylval.str = new std::string(yytext, yyleng);
    return INTEGER;
}

{float} {
    yylval.str = new std::string(yytext, yyleng);
    return DOUBLE_NUMBER;
}

{character} {
    yylval.str = new std::string(yytext, yyleng);
    return CHARACTER;
}

{str} {
    yylval.str = new std::string(yytext, yyleng);
    return STRING;
}

%%
