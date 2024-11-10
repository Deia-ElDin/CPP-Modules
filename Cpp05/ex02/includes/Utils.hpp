#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <ctime>    // For time()
#include <string>
#include <sstream> 
#include <cstdlib>  // For rand() and srand()
#include <iostream>

namespace Utils 
{
    void printMsg(const std::string& msg, const std::string& color);
    void printErr(const std::string& msg);
    int	getRandomNumber(int min, int max);

    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
}

#endif // __UTILS_HPP__
