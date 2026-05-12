#ifndef PARSER_HPP 
#define PARSER_HPP
#include <iostream>
#include <string>

class Parser
{
private:
    unsigned int* term_positions;

public:
    int term_counter(std::string& function);
    std::string* parser_controller(std::string& function, int value_of_x);
};

bool comes_x(const char portion_of_function); //this functinon check is the variable x comes after an element

#endif