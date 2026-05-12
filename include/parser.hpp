#ifndef PARSER_HPP 
#define PARSER_HPP
#include <iostream>
#include <string>

class Parser
{
private:
    unsigned int total_terms;
    std::string* terms; //this pointer is used to keep the terms of the (f(x)) (Dynamic Allocation)
public:
    Parser(); //definition of total_terms
    void term_counter(std::string& function); //this function counts the total terms of an (f(x)) //maybe needs fixing
    void term_saving(std::string& function); 
    std::string* parser_controller(std::string& function);
    ~Parser(); //deallocation
};

bool after_x(const std::string& rest_function);

#endif