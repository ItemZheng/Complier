//
// Created by BossWang & ItemZheng on 2019-06-16.
//

#include <string>
#include <iostream>
#include <map>

using namespace std;

#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H

class Error {
public:
    static const int ERROR_SYNTAX = 0;
    static const int ERROR_REDEFINITION = 1;
    static const int ERROR_UNKNOWN = 2;
    static const int ERROR_UNDECLARED = 3;
    static const int ERROR_UNDECLARED_FUNCTION = 4;
    static const int ERROR_TYPE_NOT_MATCH = 5;
    static string currentFile;
public:
    int type;
    int lineno;
    string near;
public:
    Error(int type, int lineno, char *near);

    Error(int type, int lineno, string near);

    void Print();

    static void setCurrentFile(string file);
};

#endif //COMPILER_ERROR_H
