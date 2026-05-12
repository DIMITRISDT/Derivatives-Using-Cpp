#include "parser.hpp"
#include <cstring>
#include <string>

//function definition of class "parser":
int Parser::term_counter(std::string& function)
{
    unsigned int i, j, operator_cnt = 0, pos; //operator_cnt = crowd, pos = position
    unsigned int parenthesis_cnt = 0;
    term_positions = nullptr;
    unsigned int* temp = nullptr;
    for(i=0; i<function.size(); i++)
    {
        //the term counter does not catch terms inside parenthesis
        if(function[i] == '(')
            parenthesis_cnt++;
        else if(function[i] == ')')
            parenthesis_cnt--;
        
        if(!parenthesis_cnt && (function[i] == '+' || function[i] == '-'))
        {
            operator_cnt++; //new operator found
            pos = operator_cnt-1;
            if(term_positions == nullptr)
                term_positions = new unsigned int;
            else
            {
                temp = new unsigned int[operator_cnt];
                for(j=0; j<pos; j++)
                    temp[j] = term_positions[j];
                delete[] term_positions;
                term_positions = temp;
            }
            term_positions[pos] = i; //save of the operator
        }
    }
    if(parenthesis_cnt != 0) //In case a parenthesis never closed or never opened
    {
        std::cout << "Error: The syntax of the function is invalid!"; 
        exit(EXIT_FAILURE);
    }
    return operator_cnt;
}

std::string* Parser::parser_controller(std::string& function, int value_of_x)
{
    unsigned int i;
    static char const *ptr = &function[0];
    double result = 0;
    for(i=0; i<function.size(); i++)
    {
        //check what comes after
        if(*ptr>= '0' && *ptr <= '9')
        {
            //-> x, e^x, log, ln, sqrt(), parenthesis, or synthetic functions
            // if(comes_x(*(ptr+1)))
            // {
                
            // }
        }
        else if(*ptr == 'x')
        {
            //-> ^(power function), e^x, log, ln , sqrt(), parenthesis or synthetic functions
        }
        else if(*ptr == 'l')
        {
            //check if it refers to log or ln function
        }
        else if(*ptr == 's')
        {
            //check if it refers to sqrt()
        }
    }
}

//default functions
bool comes_x(const char portion_of_function)
{
    if(portion_of_function == 'x')
        return true;
    return false;
}