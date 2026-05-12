#include "parser.hpp"
#include <cstring>
#include <string>
#include <cctype>

//function definition of class "parser":
Parser::Parser() { this->total_terms = 0; }

void Parser::term_counter(std::string& function)
{
    unsigned int size = function.size(), parenthesis_cnt = 0;
    const char* ptr = &function[0];
    for( ; ptr != '\0'; ptr++)
    {
        if(*ptr == '(')
            parenthesis_cnt++;
        else if(*ptr == ')')
            parenthesis_cnt--;
        if(!parenthesis_cnt && (*ptr == '+' || *ptr == '-'))
            this->total_terms++;
    }
    if(parenthesis_cnt != 0) //In case a parenthesis never closed or never opened
    {
        std::cout << "Error: The syntax of the function is invalid!"; 
        exit(EXIT_FAILURE);
    }
    this->total_terms+=1; //(amount + 1) because no operator follows after the last term
}

void Parser::term_saving(std::string& function)
{
    term_counter(function); //calc of amount of terms
    std::cout << total_terms << std::endl; //test
    std::string *terms = new std::string[total_terms]; //allocating space (string) for each term 
    const char* ptr = &function[0];
    const char* ptr_temp = ptr;
    unsigned int index = -1, term_length = 0, parenthesis_cnt = 0;
    for(; *ptr!='\0'; ptr++)
    {
        term_length++;
        if(*ptr == '(')
            parenthesis_cnt++;
        else if(*ptr == ')')
            parenthesis_cnt--;
        if(!parenthesis_cnt && (*ptr == '+' || *ptr == '-'))
        {
            index++;
            size_t start_of_term = (unsigned)(ptr - function[0]);
            terms[index] = function.substr(start_of_term, term_length-1);
            term_length = 0;
        }
    }
    for(int i=0; i<total_terms; i++)
        std::cout << this->terms[i] << std::endl;
}

std::string* Parser::parser_controller(std::string& function)
{
    //extra
    // if(*ptr>= '0' && *ptr<= '9')
    // {
    //     continue;
    // }
    // else if(*ptr == 'x')
    // {
    //     int start = (ptr+1) - &function[0]; //calc of start
    //     int end = size; //calc of end
    //     if(after_x(function.substr(start,end))) //passing the rest string after (x)
    //     {
    //         cout << "the term has finished\n";
    //         if(isdigit(*(ptr-1))) 
    //         {
    //             cout << "certain function will be called\n";
    //         }
    //     }
    // }
}

Parser::~Parser() { delete[] this->terms; }

bool after_x(const std::string& rest_function)
{
    unsigned int size = rest_function.size();
    const char* ptr = &rest_function[0];
    for(; *ptr!='\0'; ptr++)
        if(*ptr == '+' || *ptr == '-') //this means the term has finished
            return true;
    return false;
}