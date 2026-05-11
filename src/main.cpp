#include <iostream>
#include "derivatives.hpp"
using namespace std;

int main() {
    cout << "Hello!" << endl;
    Random r(5);
    cout << r.get() << endl;
    r.set(2);
    cout << r.get() << endl;
    return 0;
}
