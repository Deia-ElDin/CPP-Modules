#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include "Utils.hpp"
#include <string>
#include <stdexcept>

template<typename T>
class Array 
{
    private:
        T*              _arr;
        unsigned int    _size;

    public:
        Array() : _arr(NULL), _size(0) {
            Utils::printMsg("Array default constructor called", "yellow");
        }

        Array(unsigned int n) : _arr(new T[n]()), _size(n) {
            Utils::printMsg("Array parameter constructor called", "yellow");
        }

        Array(const Array& other) : _arr(new T[other._size]), _size(other._size) {
            Utils::printMsg("Array copy constructor called", "yellow");
            for (unsigned int i = 0; i < _size; i++)
                _arr[i] = other._arr[i];
        }

        Array& operator=(const Array& other) {
            Utils::printMsg("Array assignment operator called", "yellow");
            if (this != &other) {
                delete[] _arr;
                _arr = new T[other._size];
                _size = other._size;
                for (unsigned int i = 0; i < _size; i++)
                    _arr[i] = other._arr[i];
            }
            return *this;
        }

        ~Array() {
            Utils::printMsg("Array destructor called", "magenta");
            delete[] _arr;
        }

        T& operator[](unsigned int index) {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _arr[index];
        }

        unsigned int size() const {
            return _size;
        }
};


#endif