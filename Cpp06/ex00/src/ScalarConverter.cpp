#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    Utils::printMsg("ScalarConverter Default constructor called", "yellow");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    void other;
    Utils::printMsg("ScalarConverter copy constructor called", "yellow");
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    void other;
    Utils::printMsg("ScalarConverter assignment operator called", "yellow");
    return *this;
}

ScalarConverter::~ScalarConverter() {
    Utils::printMsg("ScalarConverter destructor called", "magenta");
}

void    ScalarConverter::convert(const std::string& str) {
    Utils::convertToChar(str);
}
