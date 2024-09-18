#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();									// Default constructor
		WrongCat(const std::string& type);			// Parametric constructor
		WrongCat(const WrongCat& other);			// Copy constructor
		WrongCat& operator=(const WrongCat& other);	// Copy assignment operator
		virtual ~WrongCat();						// Destructor

		void makeSound() const;  			
};

#endif 