//
// Created by BossWang & ItemZheng on 2019-06-16.
//

#include "error.h"

Error::Error(int type, int lineno, char *near) {
    this->type = type;
    this->lineno = lineno;
    this->near = string(near);
}

Error::Error(int type, int lineno, string near) {
    this->type = type;
    this->lineno = lineno;
    this->near = near;
}

void Error::Print() {
    cout << "Line: " << lineno << "\t";
    switch (type) {
        case ERROR_SYNTAX:
            cout << "Error: Syntax Error near '" << near << "'." << endl;
            break;
        case ERROR_REDEFINITION:
            cout << "Error: Redefinition of '" << near << "'." << endl;
            break;
        case ERROR_UNDECLARED:
            cout << "Error: Use of undeclared identifier '" << near << "'." << endl;
            break;
        case ERROR_UNDECLARED_FUNCTION:
            cout << "Error: Use of undeclared function '" << near << "'." << endl;
            break;
        case ERROR_UNKNOWN:
        default:
            cout << "Error: Unknown Error near '" << near << "'." << endl;
            break;
    }

}