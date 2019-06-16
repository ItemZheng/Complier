//
// Created by BossWang and ItemZheng on 2019-06-16.
//
#include "type.h"
#include "error.h"
#include <iostream>
#include <vector>

using namespace std;

#ifndef COMPILER_SYMTAB_H
#define COMPILER_SYMTAB_H


class SymbolNode {
public:
    const static int FUNC_DEC = 1;
    const static int FUNC_DEFINE = 2;
public:
    int lineno;
    string name;
    type_identifier typeIdentifier;
    type_var typeVar;
    SymbolNode *next;
    int level;

    int func_type;
public:
    SymbolNode(int lineno, string name, type_identifier typeIdentifier, type_var typeVar, int level);
};

class SymbolTable {
private:
    static const int HASH_SIZE = 10007;
    SymbolNode *table[HASH_SIZE];
    int level;
public:
    SymbolTable();

    SymbolNode *sym_look_up(string name);

    Error *sym_insert(SymbolNode *sym);

    int hashOf(string name);

    void enterScope();

    void quitScope();

    int getLevel();

private:
    void insert(SymbolNode *sym);
};


#endif //COMPILER_SYMTAB_H
