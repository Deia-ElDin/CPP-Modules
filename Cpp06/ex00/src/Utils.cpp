#include "Utils.hpp"

void		Utils::printMsg(const std::string& msg, const std::string& color) {
	std::string textBold = "\033[1m";
	std::string textColor = "\033[37m"; // Default white
	std::string textReset = "\033[0m";

	if (color == "green") textColor = "\033[32m";
	else if (color == "red") textColor = "\033[31m";
	else if (color == "yellow") textColor = "\033[33m";
	else if (color == "blue") textColor = "\033[34m";
	else if (color == "magenta") textColor = "\033[35m";
	else if (color == "cyan") textColor = "\033[36m";

	std::string fullMsg = textBold + textColor + msg + textReset;
	std::cout << fullMsg << std::endl;
}

void		Utils::printErr(const std::string& msg) {
	std::string textBold = "\033[1m";
	std::string textRed = "\033[31m";
	std::string textReset = "\033[0m";

	std::string fullMsg = textBold + textRed + msg + textReset;
	std::cerr << fullMsg << std::endl;
}


void Utils::convertToChar(const std::string& str) {
    std::string baseStr = "char: ";

    if (str.length() == 1) {
        char charValue = str[0];
        if (charValue >= 32 && charValue <= 126)
            Utils::printMsg(baseStr + "'" + str + "'", "green");
		else 
            Utils::printMsg(baseStr + "Non displayable", "red");
        
    } else {
        int intValue = std::atoi(str.c_str());
        if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()) {
            char charValue = static_cast<char>(intValue);
            if (charValue >= 32 && charValue <= 126) {
                Utils::printMsg(baseStr + "'" + std::string(1, charValue) + "'", "green");
            } else {
                Utils::printMsg(baseStr + "Non displayable", "red");
            }
        } else {
            Utils::printMsg(baseStr + "impossible", "red");
        }
    }
}

// void   		Utils::convertToInt(const std::string& str);

// void   		Utils::convertToFloat(const std::string& str);

// void   		Utils::convertToDouble(const std::string& str);
