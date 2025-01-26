#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter() {
    Utils::printMsg("ScalarConverter Default constructor called", "yellow");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other; 
    Utils::printMsg("ScalarConverter copy constructor called", "yellow");
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other; 
    Utils::printMsg("ScalarConverter assignment operator called", "yellow");
    return *this;
}

ScalarConverter::~ScalarConverter() {
    Utils::printMsg("ScalarConverter destructor called", "magenta");
}

static void printChar(double value) {
    if (value < 0 || value > 127) 
        Utils::printErr("char: impossible");
    else if (value < 32 || value > 126) 
        Utils::printErr("char: Non displayable"); 
    else 
        Utils::printMsg("char: '" + Utils::toStr(static_cast<char>(value)) + "'", "green");
}

static void printInt(double value) {
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        Utils::printErr("int: impossible");
    else 
        Utils::printMsg("int: " + Utils::toStr(static_cast<int>(value)), "green");
}

static void printFloat(double value) {
   std::string  result = Utils::toStr(static_cast<float>(value));

   if (value == static_cast<int>(value)) 
    result += ".0";
   Utils::printMsg("float: " + result + "f", "green");
}

static void printDouble(double value) {
   std::string  result = Utils::toStr(value);

   if (value == static_cast<int>(value)) 
    result += ".0";
   Utils::printMsg("double: " + result, "green");
}

void ScalarConverter::convert(const std::string& str) {
    char    *end;
    double  value = strtod(str.c_str(), &end);
    
    if (str == "nan" || str == "nanf" || 
        str == "+inf" || str == "+inff" ||
        str == "-inf" || str == "-inff") {
        bool is_f = str[str.length() - 1] == 'f';
        Utils::printErr("char: impossible");
        Utils::printErr("int: impossible");
        Utils::printErr("float: " + str + (is_f ? "" : "f"));
        Utils::printErr("double: " + (is_f ? str.substr(0, str.length() - 1) : str));
        return;
    }
    
    if (str.length() == 1 && !std::isdigit(str[0])) 
        value = static_cast<double>(str[0]);
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

/*
    numeric_limits:
        The std::numeric_limits class template in C++ provides information about the properties of arithmetic types (e.g., char, int, float, etc.). When applied to char, it tells you the minimum and maximum values that a char can hold in the current system.

    type casting operators in C++:
        1. static_cast
        2. dynamic_cast
        3. reinterpret_cast

    1. static_cast:
        -   Purpose: Used for safe, compile-time conversions between related types or numeric conversions.
        -   Example Use Case: Converting int to float, void* to a specific pointer type, or casting between base and derived classes.
        -   Key Trait: Ensures the conversion is well-defined and checked at compile time.

    2. dynamic_cast
        -   Purpose: Used for runtime type-checking and downcasting in inheritance hierarchies.
        -   Example Use Case: Converting a base class pointer to a derived class pointer, ensuring the object is of the correct type.
        -   Key Trait: Requires polymorphism (i.e., at least one virtual function in the base class). If the cast fails, it returns nullptr (for pointers) or throws an exception (for references).

    3. reinterpret_cast
        -   Purpose: Used for low-level, unsafe conversions between unrelated types (e.g., converting a pointer to an integer or vice versa).
        -   Example Use Case: Casting raw memory data into a specific type for reinterpretation.
        -   Key Trait: It doesn't check or guarantee correctness of the conversion—use with extreme caution.
*/
