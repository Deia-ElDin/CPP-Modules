#ifndef __CAT_HPP__
# define __CAT_HPP__

#include <iostream>
#include <string>

class Cat : public Animal
{
	public:
		Cat();								// Default constructor
		Cat(const std::string& type);		// Parametric constructor
		Cat(const Cat& other);				// Copy constructor
		Cat& operator=(const Cat& other);	// Copy assignment operator
		virtual ~Cat();						// Destructor

		void makeSound() const;  			// Virtual function
};

#endif 