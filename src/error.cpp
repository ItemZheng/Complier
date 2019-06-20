//
// Created by BossWang & ItemZheng on 2019-06-16.
//

#include "error.h"

string MyError::currentFile = "";

MyError::MyError(int type, int lineno, char *near) {
    this->type = type;
    this->lineno = lineno;
    this->near = string(near);
}

MyError::MyError(int type, int lineno, string near) {
    this->type = type;
    this->lineno = lineno;
    this->near = near;
}

void MyError::Print() {
    cout << currentFile << "\tLine: " << lineno << "\t";
    switch (type) {
        case ERROR_SYNTAX:
            cout << "MyError: Syntax MyError near '" << near << "'." << endl;
            break;
        case ERROR_REDEFINITION:
            cout << "MyError: Redefinition of '" << near << "'." << endl;
            break;
        case ERROR_UNDECLARED:
            cout << "MyError: Use of undeclared identifier '" << near << "'." << endl;
            break;
        case ERROR_UNDECLARED_FUNCTION:
            cout << "MyError: Use of undeclared function '" << near << "'." << endl;
            break;
        case ERROR_TYPE_NOT_MATCH:
            cout << "MyError: Type not match " << endl;
            break;
        case ERROR_UNKNOWN:
        default:
            cout << "MyError: Unknown MyError near '" << near << "'." << endl;
            break;
    }

}

void MyError::setCurrentFile(string file) {
    currentFile = file;
}