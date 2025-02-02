#include "Base.hpp"
#include "Utils.hpp"

int main() {
    Base* ptr = Base::generate();
    
    Base::identify(ptr);
    Base::identify(*ptr);
    
    delete ptr;
    return 0;
}

/*
    Objectives:
        - Learn about runtime polymorphism
        - Understand type identification without using RTTI (Runtime Type Information)
        - Practice dynamic_cast usage
*/