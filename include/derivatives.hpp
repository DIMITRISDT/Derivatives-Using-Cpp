#ifndef DERIVATIVES_HPP
#define DERIVATIVES_HPP
#include <iostream>
#include <string>

class DerivativeStringSolver {
    
public:
    std::string constant(std::string c);
    int constant(int c);

    std::string linear(std::string c);
    int linear(int c);

    std::string numberPower(char base, std::string power);
    std::string numberPower(char base, int power);

    std::string eBasePower(std::string power);
    std::string eBasePower(std::string power, std::string multi); // continue from here

    std::string exponential(std::string input);
    std::string naturalLog(std::string input);
    std::string logarithm(std::string input);
};


#endif
