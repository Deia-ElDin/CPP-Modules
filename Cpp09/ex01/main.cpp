#include "RPN.hpp"
#include "Utils.hpp"
#include <iostream>

int main(int ac, char** av) {
    if (ac != 2) {
        Utils::printErr("Program requires one argument (RPN expression)");
        return 1;
    }

    RPN calculator;
    
    try {
        int result = calculator.evaluate(av[1]);
        Utils::printMsg("Result: " + Utils::toStr(result), "green");
    } catch (const std::exception& e) {
         Utils::printErr(Utils::toStr(e.what()));
        return 1;
    }

    return 0;
}
