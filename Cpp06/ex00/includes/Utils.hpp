#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream> 
#include <limits>	// For std::numeric_limits<char>
#include <cstdlib>	// For std::atoi

class Utils 
{
	public:
		static void printMsg(const std::string& msg, const std::string& color);
		static void printErr(const std::string& msg);
		static void	convertToChar(const std::string& str);
		// static void	convertToInt(const std::string& str);
		// static void	convertToFloat(const std::string& str);
		// static void	convertToDouble(const std::string& str);
		template <typename T>
		static std::string  toStr(T value);
};

template <typename T>
std::string	Utils::toStr(T value) {
	std::stringstream ss;

	ss << value;
	return ss.str();
}

#endif
