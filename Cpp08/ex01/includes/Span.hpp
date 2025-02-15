#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int        _N;
        std::vector<int>    _storage;

    public:
        Span();
        Span(unsigned int number);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    getDefaultSize() const;
        void    getActualSize() const;
        void    getStorage() const;
        void    addNumber(int number);
        int     shortestSpan() const;
        int     longestSpan() const;
};

#endif