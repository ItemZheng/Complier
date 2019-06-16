//
// Created by BossWang & ItemZheng on 2019-06-16.
//

#include "symtab.h"

SymbolNode::SymbolNode(int lineno, string name, type_identifier typeIdentifier, type_var typeVar, int level) {
    this->lineno = lineno;
    this->name = name;
    this->typeIdentifier = typeIdentifier;
    this->typeVar = typeVar;
    this->level = level;
    this->next = NULL;
    this->func_type = FUNC_DEC;
}

SymbolTable::SymbolTable() {
    // init
    for(int i = 0; i < HASH_SIZE; i++){
        table[i] = NULL;
    }
    level = 0;
}

SymbolNode* SymbolTable::sym_look_up(string name) {
    return table[hashOf(name)];
}

Error* SymbolTable::sym_insert(SymbolNode *sym) {
    SymbolNode * node = sym_look_up(sym->name);
    // Variable
    if(sym->typeVar != TYPE_FUNC){
        if(node != NULL && node->level == sym->level){
            return new Error(Error::ERROR_REDEFINITION, sym->lineno, sym->name);
        }
        // insert
        insert(sym);
    } else {
        // if sym is function
        if(sym->func_type == SymbolNode::FUNC_DEC){
            // 声明
            if(node == NULL || node->level < sym->level){
                // insert
                insert(sym);
            }
        } else {
            // 定义
            if(node != NULL){
                if(node->typeVar == TYPE_FUNC && node->func_type == SymbolNode::FUNC_DEFINE){
                    return new Error(Error::ERROR_REDEFINITION, sym->lineno, sym->name);
                } else if(node->typeVar != TYPE_FUNC){
                    return new Error(Error::ERROR_REDEFINITION, sym->lineno, sym->name);
                }
            }
            if(node == NULL){
                return new Error(Error::ERROR_UNKNOWN, sym->lineno, sym->name);
            } else{
                node->func_type = SymbolNode::FUNC_DEFINE;
            }
        }
    }
    return NULL;
}

void SymbolTable::insert(SymbolNode *sym) {
    int hash = hashOf(sym->name);
    if(table[hash] == NULL){
        table[hash] = sym;
    } else {
        sym->next = table[hash];
        table[hash] = sym;
    }
}

int SymbolTable::hashOf(string name) {
    int hash = 0;
    for(int i = 0; i < name.length(); i++){
        hash = (hash * 128 + (name[i] - '\0')) % HASH_SIZE;
    }
    return hash;
}

void SymbolTable::enterScope() {
    level++;
}

void SymbolTable::quitScope() {
    for(int i = 0; i < HASH_SIZE; i++){
        SymbolNode * node = table[i];
        while (node != NULL && node->level == level){
            node = node->next;
        }
        table[i] = node;
    }
    level--;
}

int SymbolTable::getLevel() {
    return level;
}