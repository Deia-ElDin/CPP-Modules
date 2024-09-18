#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();

    // Animal* animal = new Animal();
    // animal->makeSound();

    delete dog;
    delete cat;
    
    return 0;
}
