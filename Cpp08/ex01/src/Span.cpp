#include "Span.hpp"
#include "Utils.hpp"

Span::Span() : _N(0) {
    Utils::printMsg("Span Default constructor called", "yellow");
}

Span::Span(unsigned int n) : _N(n) {
    Utils::printMsg("Span Parameter constructor called with N = " + Utils::toStr(n), "yellow");
}

Span::Span(const Span& other): _N(other._N), _storage(other._storage) {
    Utils::printMsg("Span copy constructor called", "yellow");
}

Span& Span::operator=(const Span& other) {
    Utils::printMsg("Span assignment operator called", "yellow");

    if (this != &other) {
        _N = other._N; 
        _storage = other._storage;
    }
    return *this; 
}

Span::~Span() {
    Utils::printMsg("Span destructor called", "magenta");
}

void    Span::getDefaultSize() const {
    Utils::printMsg("Default Size: " + Utils::toStr(_N), "blue");
}

void    Span::getActualSize() const {
    Utils::printMsg("Actual Size: " + Utils::toStr(_storage.size()), "cyan");
}

void    Span::getStorage() const {
    Utils::printMsg("Printing The Storage: ", "green");

    for (std::vector<int>::const_iterator it = _storage.begin(); it != _storage.end(); it++) {
        Utils::printMsg(Utils::toStr(*it), "green");
    }
}

void    Span::addNumber(int number) {
    if (_storage.size() >= _N) 
        Utils::throwErr("Storage is full!");

    _storage.push_back(number);
}

int     Span::shortestSpan() const {
    if (_storage.size() <= 1) 
        Utils::throwErr("Not enough elements to calculate span!");

    std::vector<int> sorted = _storage;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (unsigned int i = 0; i < sorted.size() - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan) minSpan = diff;
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_storage.size() < 2) 
        Utils::throwErr("Not enough elements to calculate span!");

    int minVal = *std::min_element(_storage.begin(), _storage.end());
    int maxVal = *std::max_element(_storage.begin(), _storage.end());

    return maxVal - minVal;
}

// The reason for using *std::min_element(...) and *std::max_element(...) is because std::min_element and std::max_element return iterators, not actual values.
