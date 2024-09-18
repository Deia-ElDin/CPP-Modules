#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include "Utils.hpp"

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();                                      // Default constructor
        WrongAnimal(const std::string& type);               // Parametric constructor
        WrongAnimal(const WrongAnimal& other);              // Copy constructor
        WrongAnimal& operator=(const WrongAnimal& other);   // Copy assignment operator
        virtual ~WrongAnimal();                             // Destructor

        void            setType(const std::string& type);
        std::string     getType() const;
        
        void            makeSound() const;

        static void     printStatus(const WrongAnimal& wrongAnimal);
};

#endif 
