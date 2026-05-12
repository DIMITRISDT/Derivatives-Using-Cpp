#include <iostream>
#include "derivatives.hpp"
#include "parser.hpp"
using namespace std;

int main() {
    Parser p1;
    string function;
    cout << "Type your function {f(x)}: ";
    getline(cin, function);
    cout << p1.term_counter(function) << endl;
    return 0;
}
