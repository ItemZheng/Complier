//
// Created by BossWang & ItemZheng on 2019-06-15.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

class Node {
virtual void visit() = 0;
virtual void codeGen() = 0;
};




#endif //COMPILER_NODE_H
