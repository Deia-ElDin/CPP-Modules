#include "Utils.hpp"

std::string	Utils::parseString(const std::string& str) {
	return (str != nullptr) ? str : "";
}

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

void   		Utils::convertToChar(const std::string& str) {
	std::string	baseStr = "char: ";

	if (str[0] < 31 || str[0] > 126 || str.length() > 1)
		return (Utils::printMsg(baseStr + "Non displayable", "red"));
}

// void   		Utils::convertToInt(const std::string& str);

// void   		Utils::convertToFloat(const std::string& str);

// void   		Utils::convertToDouble(const std::string& str);
