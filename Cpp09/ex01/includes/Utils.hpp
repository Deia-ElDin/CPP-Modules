#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream> 
#include <stdexcept> // std::runtime_error

namespace Utils 
{
    void        printMsg(const std::string& msg, const std::string& color);
    void        printErr(const std::string& msg);
    void        printSeparator(void);
    void        throwErr(const std::string& msg);
    
    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        
        ss << value;
        return ss.str();
    }
}

#endif
