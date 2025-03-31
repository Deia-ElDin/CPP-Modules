#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>  // For std::atoi

class RPN {
    private:
        std::stack<int> _operands;

        // Helper functions
        bool isOperator(char c) const;
        void executeOperation(char op);

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        // Main evaluation function
        int evaluate(const std::string& expression);
};

#endif
