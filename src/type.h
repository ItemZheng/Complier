//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#ifndef COMPILER_TYPE_H
#define COMPILER_TYPE_H

#include "stdlib.h"

typedef enum{
    INT,
    LONG,
    FLOAT,
    SHORT,
    VOID,
    DOUBLE,
    CHAR
} type_var;

typedef enum{
    SINGLE,
    ARRAY
} type_identifier;

typedef enum{
    PLUS,
    MINUS,
    MUL,
    DIV,
    MOD,
    LESS,
    LESS_EQUAL,
    GREATER,
    GREATER_EQUAL,
    AND_AND,
    OR_OR,
    NOT,
    EQUAL,
    NOT_EQUAL,
    MINUS_SIGN,
    PLUS_PLUS_L,
    PLUS_PLUS_R,
    MINUS_MINUS_L,
    MINUS_MINUS_R
} type_expression;

#endif