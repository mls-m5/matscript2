
#include "ast.h"
#include <fstream>

using namespace std;

void Ast::group() {
    //Workflow
    //Pass through and set the order of each operator
    //Do a second pass in order and group the highest ordered operators first and then to the last
    //Done
}

void Ast::split() {
    using std::string;
    auto isspace = [](int c) {
        switch (c) {
            case '\n':
            case '\t':
            case ' ':
                return true;
            default:
                return false;
        }
    };
    auto row = this->row;
    auto col = this->col;
    string word;
    string before;
    for (auto c: content) {
        if (c == '\n') {
            ++row;
        }
        else {
            ++col;
        }

        //Really simple tokenizer
        
        if (isspace(c)) {
            if (!word.empty()) {
                push_back(AstUnit(word));
                back().row = row;
                back().col = col;
                back().before = before;
                before = "";
                word = "";
            }
            else {
                before.push_back(c);
            }
            continue;
        }
        else {
            word.push_back(c);
        }
    }
    if (!word.empty()) {
        push_back(AstUnit(word));
        back().row = row;
        back().col = col;
        back().before = before;
    }
}


OperatorListType loadOperators(std::string filename) {
    fstream file(filename);
    OperatorListType ret;

    string word;
    Operator::Type type;

    while (file) {
        file >> word;

        if (word == "prefix:") {
            type = Operator::Prefix;
            continue;
        }
        else if (word == "infix:") {
            type = Operator::Infix;
            continue;
        }
        else if (word == "postfix:") {
            type = Operator::Postfix;
            continue;
        }

        Operator op;
        op.name = word;
        op.type = type;
        ret.push_back(op);
    }

    return ret;
}

