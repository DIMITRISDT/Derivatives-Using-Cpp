#include <iostream>
#include "parser.hpp"
using namespace std;

int main() {
    Parser p1;
    string function;
    cout << "Type your function {f(x)}: ";
    getline(cin, function);
    p1.term_saving(function);
    return 0;
}
