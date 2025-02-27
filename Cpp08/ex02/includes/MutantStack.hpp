#ifndef __MUTANT_STACK_HPP__
# define __MUTANT_STACK_HPP__

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> 
{
    public:
        // here we create an alias for the type of the container
        typedef typename Container::iterator                iterator;
        typedef typename Container::const_iterator          const_iterator;
        typedef typename Container::reverse_iterator        reverse_iterator;
        typedef typename Container::const_reverse_iterator  const_reverse_iterator;

        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                std::stack<T, Container>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

        // The c member isn't defined directly in my class, actually accessible through the base class
        // the c represents the container of the stack

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
        
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
        
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif

/*
    * The line template <typename T, typename Container = std::deque<T>> means:

        - You're creating a class template that takes two type parameters
        - The first parameter T is the type of elements the stack will store (like int, string, etc.)
        - The second parameter Container specifies what container type to use internally
        - The = std::deque<T> part sets the default container to be std::deque if no container is specified
        - This makes the second template parameter optional - users can override it or accept the default

    *  This design gives flexibility - you can use the class as either:

        - MutantStack<int> (uses deque by default)
        - MutantStack<int, std::vector<int>> (uses vector instead)

    * Why std::deque is the Default Container for Stack
        - Fast at both ends: Provides push and pop operations at the back (what stack needs)
        - No reallocation: Doesn't need to copy all elements when growing (unlike vector)
        - Memory efficient: Allocates memory in chunks rather than one big block
        - Stable references: Adding elements doesn't invalidate existing iterators or references
        - Balance of features: Good trade-off between memory usage and performance for stack operations

    * Feature	                            std::deque	             std::vector	     std::list
        Random Access (O(1))	            ✅ Yes	                ✅ Yes	            ❌ No (O(n))
        Insertion/Deletion at Front (O(1))	✅ Yes (push_front())	❌ No (O(n))        	✅ Yes
        Insertion/Deletion at Back (O(1))	✅ Yes (push_back())	    ✅ Yes (push_back())	✅ Yes
        Insertion/Deletion in Middle (O(n))	❌ No	                ❌ No	            ✅ Yes (O(1))
        Contiguous Memory	                ❌ No (blocks)           ✅ Yes	            ❌ No (linked nodes)
        Cache-Friendly	                    Medium                   ✅ High 	         ❌ Poor

    * typedef:
        is a keyword used to create an alias (alternative name) for an existing data type, It doesn't create a new type, just another name for an existing type

    * typename:
        is a keyword used to tell the compiler that a dependent name is a type, not a variable or a static member

    * why we are creating these alias?
        - The aliases are created to make it easier to refer to the iterator types of the container
        - Instead of writing std::deque<T>::iterator, you can use iterator directly
        - This makes the code cleaner and more readable
        - It also makes the code more flexible - you can change the container type without changing the iterator type

    * what will happen if i removed typename from the typedef line?
        If you remove typename, the compiler won't know that Container::iterator refers to a type. It will assume it's a non-type entity (like a variable), causing compilation errors since you can't create a typedef of a non-type.

    * begin() and end()

        - begin() returns an iterator pointing to the first element in the container
        - end() returns an iterator pointing just past the last element (not to the last element)
        - These allow you to iterate from first to last element (forward direction)
        - Used like: for (auto it = container.begin(); it != container.end(); ++it)

    * rbegin() and rend()

        - rbegin() returns a reverse iterator pointing to the last element
        - rend() returns a reverse iterator pointing to the position before the first element
        - These allow you to iterate from last to first element (backward direction)
        - Used like: for (auto it = container.rbegin(); it != container.rend(); ++it)

    * push: Adds an element to the top of the stack ... calls container.push_back()
    * pop:  Removes the element from the top ... calls container.pop_back()
    * top:  Returns a reference to the top element without removing it ... returns container.back()
*/
