//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#ifndef COMPILER_TYPE_H
#define COMPILER_TYPE_H

#include "stdlib.h"

typedef enum{
    TYPE_INT,
    TYPE_LONG,
    TYPE_FLOAT,
    TYPE_SHORT,
    TYPE_VOID,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_STRING
} type_var;

typedef enum{
    SINGLE,
    ARRAY,
    FUNCTION
} type_identifier;

typedef enum{
    EXP_PLUS,
    EXP_MINUS,
    EXP_MUL,
    EXP_DIV,
    EXP_MOD,
    EXP_LESS,
    EXP_LESS_EQUAL,
    EXP_GREATER,
    EXP_GREATER_EQUAL,
    EXP_AND_AND,
    EXP_OR_OR,
    EXP_NOT,
    EXP_EQUAL,
    EXP_NOT_EQUAL,
    EXP_MINUS_SIGN,
    EXP_PLUS_PLUS_L,
    EXP_PLUS_PLUS_R,
    EXP_MINUS_MINUS_L,
    EXP_MINUS_MINUS_R,
    EXP_VAR,
    EXP_CONST,
    EXP_CALL,
    EXP_EXPV
} type_expression;

#endif