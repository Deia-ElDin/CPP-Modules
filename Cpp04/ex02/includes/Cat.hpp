#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		mutable	Brain*	brain;
		// mutable: allows the modification of the Brain pointer even in const member functions of Cat.
		
	public:
		Cat();								// Default constructor
		Cat(const std::string& type);		// Parametric constructor
		Cat(const Cat& other);				// Copy constructor
		Cat& operator=(const Cat& other);	// Copy assignment operator
		virtual ~Cat();						// Destructor

		void 	makeSound() const;  		// Virtual function
		void    setIdea(const std::string& idea) const;
		void    setBrain() const;
		void    printIdeas() const;
};

#endif

/*
	What Does mutable Do?
		Without mutable: 
			If you declare a member function as const, you cannot modify any member variables of the class within that function. This is because the function promises not to change the object’s state.

		With mutable: 
			You can modify a member variable marked with mutable even within a const member function. This is useful for variables that represent internal, logical state but not the external state that affects how an object is perceived or behaves.
*/