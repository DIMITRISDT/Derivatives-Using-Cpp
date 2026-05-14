#include "derivatives.hpp"

using std::string;

string DerivativeStringSolver::constant(string c)
{
    string tmp("0");
    return tmp;
}

int DerivativeStringSolver::constant(int c)
{
    return 0;
}

string DerivativeStringSolver::linear(string c)
{
    string tmp("1");
    return tmp;
}

int DerivativeStringSolver::linear(int c)
{
    return 1;
}

string DerivativeStringSolver::numberPower(char base, string power)
{
    int powerNum = stoi(power);
    string newPower = to_string(--powerNum);
    string result;
    result = power + base + "^" + newPower;
    return result;
}

string DerivativeStringSolver::numberPower(char base, int power)
{
    string result;
    result = to_string(power) + base + "^" + to_string(--power);
    return result;
}

string DerivativeStringSolver::eBasePower(string power)
{
    string result;
    result = "e^x";
    return result;
}
