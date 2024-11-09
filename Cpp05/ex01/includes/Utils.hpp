#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream> 

class Utils 
{
	private:
		Utils();
		Utils(const Utils&); // unnamed parameter because we won't define the function
		Utils& operator=(const Utils&);
		~Utils();
		
	public:
		static void printMsg(const std::string& msg, const std::string& color);
		static void printErr(const std::string& msg);

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
