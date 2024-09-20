#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const   Animal* animals[10];

    for (int i = 0; i < 5; ++i)
    {
        animals[i] = new Dog();
        animals[i]->makeSound();

        const Dog* dog = dynamic_cast<const Dog*>(animals[i]);
        if (dog) {
            dog->setBrain();
            dog->printIdeas();
        }
    }
    
    for (int i = 5; i < 10; ++i)
    {
        animals[i] = new Cat();
        animals[i]->makeSound();

        const Cat* cat = dynamic_cast<const Cat*>(animals[i]);
        if (cat) {
            // cat->setBrain();
            cat->setIdea("I wanna eat Fish");
            cat->setIdea("I wanna eat Meat");
            cat->printIdeas();
        }
    }

    for (int i = 0; i < 10; ++i)
        delete animals[i];
    return 0;
}

/*
    const Animal* ptr;
        Interpretation:
        ptr is a pointer to a const Animal.
        The const applies to the Animal object that ptr points to, not to the pointer itself.

        Meaning:
        You cannot modify the Animal object through the ptr pointer.
        You can change ptr itself to point to a different Animal object.
     
    Animal* const ptr || Animal const * ptr;
        Interpretation:
        ptr is a constant pointer to an Animal.
        The const applies to the ptr pointer itself, not to the Animal object it points to.
        
        Meaning:
        You can modify the Animal object through ptr.
        You cannot change ptr to point to a different Animal object.

    const Animal* animals[10];
        -   const Animal* indicates that the Animal object pointed to by each pointer in the array cannot be modified through that pointer.
        -   You cannot modify the Animal object's attributes or call any non-const member functions through these pointers.
        -   You can still change the pointer itself to point to another Animal object if you want.

    const Dog* dog = dynamic_cast<const Dog*>(animals[i]);
        dynamic_cast<const Dog*>(...):
            -   dynamic_cast<const Dog*> is used to attempt to cast the pointer animals[i] from type const Animal* to type const Dog*.
            -   This cast checks at runtime whether animals[i] actually points to a Dog object. If it does, the cast succeeds, and dog will point to that Dog object. If animals[i] does not point to a Dog, the cast fails, and dog will be set to nullptr.

        animals[i]:
            This is the const Animal* pointer from your array of Animal* pointers. Each element in this array points to either a Dog or a Cat object (both derived from Animal).

*/
