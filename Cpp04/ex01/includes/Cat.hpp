#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
		
	public:
		Cat();								// Default constructor
		Cat(const std::string& type);		// Parametric constructor
		Cat(const Cat& other);				// Copy constructor
		Cat& operator=(const Cat& other);	// Copy assignment operator
		virtual ~Cat();						// Destructor

		void 	makeSound() const;  			// Virtual function
		void    setIdea(const std::string& idea);
        void    setBrain();
        void    printIdeas() const;
};

#endif 