//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#ifndef __CODEGEN_H__
#define __CODEGEN_H__

#include"node.h"


using namespace llvm;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

class CodeGenBlock{
public:
    BasicBlock * block;
    Value * returnValue;
    std::map<string, Value*> locals;
    std::map<string, shared_ptr<VarDeclNode>> types;
};

class CodeGenContext{
private:
    std::vector<CodeGenBlock*> blockStack;

public:
    IRBuilder<> builder;
    unique_ptr<Module> theModule;
    std::map<string, Value*> globals;

    CodeGenContext(): builder(llvmContext){
        theModule = unique_ptr<Module>(new Module("main", llvmContext));
    }

    Value* getSymbolValue(string name) const{
        for(auto it=blockStack.rbegin(); it!=blockStack.rend(); it++){
            if( (*it)->locals.find(name) != (*it)->locals.end() ){
                return (*it)->locals[name];
            }
        }
        return NULL;
    }

    shared_ptr<VarDeclNode> getSymbolType(string name) const{
        for(auto it=blockStack.rbegin(); it!=blockStack.rend(); it++){
            if( (*it)->types.find(name) != (*it)->types.end() ){
                return (*it)->types[name];
            }
        }
        return NULL
    }


    void setSymbolValue(string name, Value* value){
        blockStack.back()->locals[name] = value;
    }

    void setSymbolType(string name, shared_ptr<VarDeclNode> value){
        blockStack.back()->types[name] = value;
    }

    BasicBlock* currentBlock() const{
        return blockStack.back()->block;
    }

    void pushBlock(BasicBlock * block){
        CodeGenBlock * codeGenBlock = new CodeGenBlock();
        codeGenBlock->block = block;
        codeGenBlock->returnValue = NULL;
        blockStack.push_back(codeGenBlock);
    }

    void popBlock(){
        CodeGenBlock * codeGenBlock = blockStack.back();
        blockStack.pop_back();
        delete codeGenBlock;
    }

    void setCurrentReturnValue(Value* value){
        blockStack.back()->returnValue = value;
    }

    Value* getCurrentReturnValue(){
        return blockStack.back()->returnValue;
    }

};

Value* LogErrorV(const char* str);
Value* LogErrorV(string str);

#endif