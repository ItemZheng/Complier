//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#ifndef __CODEGEN_H__
#define __CODEGEN_H__
#define ISTYPE(value, id) (value->getType()->getTypeID() == id)
#include"node.h"


using namespace llvm;
using std::unique_ptr;
using std::shared_ptr;
using std::string;
using legacy::PassManager;

class CodeGenBlock{
public:
    BasicBlock * block;
    Value * returnValue;
    std::map<string, Value*> locals;
    std::map<string, VarDeclNode*> types;
    std::map<string, uint64_t> arraySize;

    BasicBlock * continueBlock = NULL;
    BasicBlock * breakBlock = NULL;
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

    VarDeclNode* getSymbolType(string name) const{
        for(auto it=blockStack.rbegin(); it!=blockStack.rend(); it++){
            if( (*it)->types.find(name) != (*it)->types.end() ){
                return (*it)->types[name];
            }
        }
        return NULL;
    }

    void setBreakBlock(BasicBlock * block){
        blockStack.back()-> breakBlock = block;
    }

    void setContinueBlock(BasicBlock * block){
        blockStack.back()-> continueBlock = block;
    }

    BasicBlock* breakBlock(){
        for(auto it=blockStack.rbegin(); it!=blockStack.rend(); it++){
            if( (*it)->breakBlock != NULL){
                return (*it)->breakBlock;
            }
        }
        return NULL;
    }

    BasicBlock* continueBlock(){
        for(auto it=blockStack.rbegin(); it!=blockStack.rend(); it++){
            if( (*it)->continueBlock != NULL){
                return (*it)->continueBlock;
            }
        }
        return NULL;
    }

    void setSymbolValue(string name, Value* value){
        blockStack.back()->locals[name] = value;
    }

    void setSymbolType(string name, VarDeclNode *value){
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

    void setArraySize(string name, uint64_t value){
        blockStack.back()->arraySize[name] = value;
   }

    uint64_t getArraySize(string name){
        for(auto it=blockStack.rbegin(); it!=blockStack.rend(); it++){
            if( (*it)->arraySize.find(name) != (*it)->arraySize.end() ){
                return (*it)->arraySize[name];
            }
        }
        return blockStack.back()->arraySize[name];
    }

    void generateCode(ProgramNode& root);

};

static Value* CastToBoolean(CodeGenContext& context, Value* condValue){
    if( ISTYPE(condValue, Type::IntegerTyID) ){
        condValue = context.builder.CreateIntCast(condValue, Type::getInt1Ty(llvmContext), true);
        return context.builder.CreateICmpNE(condValue, ConstantInt::get(Type::getInt1Ty(llvmContext), 0, true));
    }else if( ISTYPE(condValue, Type::DoubleTyID) ){
        return context.builder.CreateFCmpONE(condValue, ConstantFP::get(llvmContext, APFloat(0.0)));
    }else{
        return condValue;
    }
}

Value* LogErrorV(const char* str);
Value* LogErrorV(string str);

#endif