#ifndef __SCALAR_CONVERTER_HPP__
# define __SCALAR_CONVERTER_HPP__

#include <iostream>
#include <string>
#include <cstdlib> // For strtod
#include <limits>  // For numeric_limits

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& str);
};

#endif
