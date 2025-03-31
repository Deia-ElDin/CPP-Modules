#include "RPN.hpp"
#include "Utils.hpp"

RPN::RPN() {
    Utils::printMsg("RPN constructor called", "yellow");
}

RPN::RPN(const RPN& other) : _operands(other._operands) {
    Utils::printMsg("RPN copy constructor called", "yellow");
}

RPN& RPN::operator=(const RPN& other) {
    Utils::printMsg("RPN assignment operator called", "yellow");
    if (this != &other) {
        _operands = other._operands;
    }
    return *this;
}

RPN::~RPN() {
    Utils::printMsg("RPN destructor called", "magenta");
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::executeOperation(char op) {
    if (_operands.size() < 2)
        throw std::runtime_error("Error: not enough operands");

    int b = _operands.top();
    _operands.pop();
    int a = _operands.top();
    _operands.pop();

    switch (op) {
        case '+':
            _operands.push(a + b);
            break;
        case '-':
            _operands.push(a - b);
            break;
        case '*':
            _operands.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            _operands.push(a / b);
            break;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream  iss(expression);
    std::string         token;

    while (iss >> token) {
        if (token.length() == 1) {
            if (isOperator(token[0])) 
                executeOperation(token[0]);
            else if (isdigit(token[0])) 
                _operands.push(token[0] - '0');
            else 
                throw std::runtime_error("Error: invalid token '" + token + "'");
        } else {
            bool valid = true;

            for (size_t i = 0; i < token.length(); i++) {
                if (!isdigit(token[i])) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                int num = std::atoi(token.c_str());
                
                if (num >= 10)
                    throw std::runtime_error("Error: numbers must be less than 10");
                _operands.push(num);
            } else 
                throw std::runtime_error("Error: invalid token '" + token + "'");
        }
    }

    if (_operands.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    return _operands.top();
}
