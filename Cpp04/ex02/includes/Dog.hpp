#ifndef __DOG_HPP__
# define __DOG_HPP__

#include <iostream>
#include <string>

class Dog : public Animal
{
    public:
        Dog();                              // Default constructor
        Dog(const std::string& type);       // Parametric constructor
        Dog(const Dog& other);              // Copy constructor
        Dog& operator=(const Dog& other);   // Copy assignment operator
        virtual ~Dog();                     // Destructor

        void makeSound() const;  			// Virtual function
};

#endif 