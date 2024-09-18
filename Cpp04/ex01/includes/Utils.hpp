#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>

class Utils {
    public:
        static void printMsg(const std::string& msg, const std::string& color);
        static void createIdeas(std::string ideas[100]);
};

#endif
