#include "string"
#include <iostream>

int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address of the stringPTR variable: " << stringPTR << std::endl;
    std::cout << "The memory address of the stringREF variable: " << &stringREF << std::endl;

    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}

/*
    std::string *stringPTR = &str;
        Pointer to a String
        stringPTR is a pointer to a string, and it is initialized with the address of the str variable.

    std::string &stringREF = str;
        Reference to a String
        A reference is like an alias; 
        it does not store the address itself 
        but refers directly to the object str.
*/
