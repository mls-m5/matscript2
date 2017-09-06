




#include <iostream>
#include <string>
#include "ast.h"

using namespace std;


int main() {
    auto operatorList = loadOperators();
    for (auto op: operatorList) {
        cout << op.name << endl;
    }
    cout << "hej!" << endl;
}


