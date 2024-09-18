#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal* animal = new Animal();
    Dog* dog = new Dog();
    Cat* cat = new Cat();
    
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    cat->setBrain();
    dog->setBrain();

    // cat->setIdea("I wanna eat fish");
    // cat->setIdea("I wanna eat meat");

    // dog->setIdea("I wanna eat bones");
    // dog->setIdea("I wanna eat meat");

    cat->printIdeas();
    dog->printIdeas();

    delete animal;
    delete dog;
    delete cat;
    
    return 0;
}
