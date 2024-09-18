#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
    private:
		Brain* brain;

    public:
        Dog();                              // Default constructor
        Dog(const std::string& type);       // Parametric constructor
        Dog(const Dog& other);              // Copy constructor
        Dog& operator=(const Dog& other);   // Copy assignment operator
        virtual ~Dog();                     // Destructor

        void    makeSound() const;  			// Virtual function
        void    setIdea(const std::string& idea);
        void    setBrain();
        void    printIdeas() const;
};

#endif 