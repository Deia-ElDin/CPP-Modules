#include "ScalarConverter.hpp"
#include "Utils.hpp"

int main(int ac, char **av) {
    if (ac != 2) 
        return (Utils::printErr("you can't pass more than 1 argument"), 1);
    
    ScalarConverter::convert(av[1]);
    return 0;
}