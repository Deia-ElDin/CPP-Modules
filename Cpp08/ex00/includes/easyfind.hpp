#ifndef __EASY_FIND_HPP__
# define __EASY_FIND_HPP__

#include <algorithm> // std::find
#include "Utils.hpp"

template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) 
        Utils::throwErr("Value not found in the container");
    
    return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) 
        Utils::throwErr("Value not found in the container");
    
    return it;
}

#endif

/*
    * What's STL (Standard Template Library)?
        It is a collection of C++ template classes for common data structures and algorithms such as lists, stacks, arrays, etc.

    * What are the Containers?
        Containers are objects that store data. They provide a way to access the stored objects and iterate over them.

    * What are the Iterators?
        Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc.

    * Iterator types are generally used to:
        -   Point to elements in a container
        -   Move through elements (forward/backward)
        -   Read or modify the elements they point to

    * What is the difference between array and vectors?
        -   Array is a fixed size data structure while vector is a dynamic size data structure.

    * What is the difference between vector and list?
        -   Vector is a sequence container that supports random access to elements, while list is a sequence container that supports only sequential access to elements.
*/

