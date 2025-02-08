#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream> 

namespace Utils 
{
    void    printMsg(const std::string& msg, const std::string& color);
    void    printErr(const std::string& msg);
    void    printTest(const std::string& msg);

    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
}

#endif
