#pragma once


#include <vector>
#include <string>

class Operator {
public:
    enum Type {
        Prefix,
        Infix,
        Postfix
    };
    std::string name;
    Type type;
};

typedef std::vector<Operator> OperatorListType;

OperatorListType loadOperators(std::string filename = "operators.txt");




class AstUnit: public std::vector<AstUnit> {
public:
    AstUnit(std::string content):
    content(content) {
    }

    void split();
    void group();

    std::string before;
    std::string content;
    std::string after;

    size_t col;
    union {
    size_t line = 0;
    size_t row;
    };
};
