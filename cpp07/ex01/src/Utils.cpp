#include "Utils.hpp"

static	std::string constructMsg(const std::string& msg, const std::string& color) {
	std::string textBold = "\033[1m";
	std::string textColor = "\033[37m";
	std::string textReset = "\033[0m";

	if (color == "green") textColor = "\033[32m";
	else if (color == "red") textColor = "\033[31m";
	else if (color == "yellow") textColor = "\033[33m";
	else if (color == "blue") textColor = "\033[34m";
	else if (color == "magenta") textColor = "\033[35m";
	else if (color == "cyan") textColor = "\033[36m";

	return textBold + textColor + msg + textReset;
}

void    Utils::printMsg(const std::string& msg, const std::string& color) {
	std::string fullMsg = constructMsg(msg, color);
	std::cout << fullMsg << std::endl;
}

void    Utils::printErr(const std::string& msg) {
	std::string fullMsg = constructMsg(msg, "red");
	std::cerr << fullMsg << std::endl;
}

