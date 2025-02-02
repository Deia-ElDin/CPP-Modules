#include "Base.hpp"
#include "Utils.hpp"

Base::Base() {
    Utils::printMsg("Base Default constructor called", "yellow");
}

Base::Base(const Base& other) {
    (void)other; 
    Utils::printMsg("Base copy constructor called", "yellow");
}

Base& Base::operator=(const Base& other) {
    (void)other; 
    Utils::printMsg("Base assignment operator called", "yellow");
    return *this;
}

Base::~Base() {
    Utils::printMsg("Base destructor called", "magenta");
}

Base* Base::generate(void) {
    int random = Utils::getRandomNumber();
    
    switch (random) {
        case 0:
            Utils::printMsg("Generated A", "green");
            return new A();
        case 1:
            Utils::printMsg("Generated B", "green");
            return new B();
        case 2:
            Utils::printMsg("Generated C", "green");
            return new C();
        default:
            return new A(); 
    }
}

void Base::identify(Base* p) {
    if (dynamic_cast<A*>(p))
        Utils::printMsg("A", "green");
    else if (dynamic_cast<B*>(p))
        Utils::printMsg("B", "green");
    else if (dynamic_cast<C*>(p))
        Utils::printMsg("C", "green");
}

void Base::identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        Utils::printMsg("A", "green");
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        Utils::printMsg("B", "green");
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        Utils::printMsg("C", "green");
        return;
    } catch (std::exception&) {}
}

/*
    void Base::identify(Base* p)
        If p actually points to an A object, this cast succeeds and returns a non-null pointer otherwise returns nullptr

    void Base::identify(Base& p) 
        If p is an A object, this cast succeeds.
*/