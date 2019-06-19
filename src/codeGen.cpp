//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#include "codeGen.h"
#include "node.h"
#include "type.h"

static Type *typeOf(const VarDeclNode& vardecl) 
{
    if(vardecl.type == ARRAY){
        return PointerType::get(typeOf(vardecl.type_var), 0);
    }
    return typeOf(vardecl.type_var);
}

static Type*typeOf(type_var type){
    if(type == TYPE_INT){
        return Type::getInt32Ty(llvmContext);
    }
    if(type == TYPE_LONG){
        return Type::getInt64Ty(llvmContext);
    }
    if(type == TYPE_SHORT){
        return Type::getInt16Ty(llvmContext);
    }
    if(type == TYPE_DOUBLE){
        return Type::getDoubleTy(llvmContext);
    }
    if(type == TYPE_FLOAT){
        return Type::getFloatTy(llvmContext);
    }
    if(type == TYPE_CHAR){
        return Type::getInt8Ty(llvmContext);
    }
    if(type == TYPE_VOID){
        return Type::getVoidTy(llvmContext);
    }
    return NULL;
}

