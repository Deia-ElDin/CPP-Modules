#include "Utils.hpp"

void    Utils::printMsg(const std::string& msg, const std::string& color) {
    std::string textBold = "\033[1m";
    std::string textColor = "\033[37m"; // Default white
    std::string textReset = "\033[0m";

    if (color == "green") textColor = "\033[32m";
    else if (color == "red") textColor = "\033[31m";
    else if (color == "yellow") textColor = "\033[33m";
    else if (color == "blue") textColor = "\033[34m";
    else if (color == "magenta") textColor = "\033[35m";
    else if (color == "cyan") textColor = "\033[36m";
    else if (color == "purple") textColor = "\033[35m"; 

    std::string fullMsg = textBold + textColor + msg + textReset;
    std::cout << fullMsg << std::endl;
}

void    Utils::printErr(const std::string& msg) {
    std::string textBold = "\033[1m";
    std::string textRed = "\033[31m";
    std::string textReset = "\033[0m";

    std::string fullMsg = textBold + textRed + msg + textReset;
    std::cerr << fullMsg << std::endl;
}

int     Utils::getRandomNumber(int min, int max) {
    std::srand(std::time(0));  // Seed the random number generator

    return min + (std::rand() % (max - min + 1));
}

/*
    How std::rand() Works Internally
        Deterministic Algorithm:
        std::rand() uses a mathematical formula called a pseudo-random number generator (PRNG). It’s called pseudo-random because the numbers only appear random but are actually determined by an initial value (the seed) and an internal formula.

        Same Seed, Same Sequence:
        If the seed value is the same every time the program starts, the PRNG will produce the same sequence of numbers.
*/
