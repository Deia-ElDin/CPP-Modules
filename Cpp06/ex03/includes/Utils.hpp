#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream> 
#include <ctime>    // For time()
#include <cstdlib>  // For rand() and srand()

namespace Utils 
{
    void    printMsg(const std::string& msg, const std::string& color);
    void    printErr(const std::string& msg);
    int     getRandomNumber(void);

    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
}

#endif
