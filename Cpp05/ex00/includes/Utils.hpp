#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <stdexcept>

class Utils 
{
    public:
        static void printMsg(const std::string& msg, const std::string& color);
        static void printErr(const std::string& msg);
};

#endif
