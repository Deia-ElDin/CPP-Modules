#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
        Brain*	brain;

    public:
        Animal();                               // Default constructor
        Animal(const std::string& type);        // Parametric constructor
        Animal(const Animal& other);            // Copy constructor
        Animal& operator=(const Animal& other); // Copy assignment operator
        virtual ~Animal();                      // Destructor

        void            setType(const std::string& type);
        std::string     getType() const;
        virtual void    makeSound() const;
        static void     printStatus(const Animal& animal);
};

#endif
