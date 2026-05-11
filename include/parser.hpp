#ifndef PARSER_HPP 
#define PARSER_HPP
#include <iostream>
#include <string>

class Parser
{
private:
    std::string function;
    int* term_positions;
public:
    int term_counter(std::string& function);
    std::string* parser_controller(std::string& function);
};

#endif