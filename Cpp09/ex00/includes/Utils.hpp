#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream> 
#include <stdexcept> // std::runtime_error

namespace Utils 
{
    void    printMsg(const std::string& msg, const std::string& color);
    void    printErr(const std::string& msg);
    void    printTestTitle(const std::string& test);
    void    printSeparator(void);
    void	throwErr(const std::string& msg);
    
    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    template <typename T>
    void printContainer(const std::string& name, const T& container) {
        std::stringstream ss;
        ss << name << ": [";
        
        typename T::const_iterator it = container.begin();
        if (it != container.end()) {
            ss << *it;
            ++it;
        }
        while (it != container.end()) {
            ss << ", " << *it;
            ++it;
        }
        ss << "]";
        printMsg(ss.str(), "cyan");
    }
}

#endif
