#include "Serializer.hpp"
#include "Utils.hpp"

Serializer::Serializer() {
    Utils::printMsg("Serializer Default constructor called", "yellow");
}

Serializer::Serializer(const Serializer& other) {
    (void)other; 
    Utils::printMsg("Serializer copy constructor called", "yellow");
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other; 
    Utils::printMsg("Serializer assignment operator called", "yellow");
    return *this;
}

Serializer::~Serializer() {
    Utils::printMsg("Serializer destructor called", "magenta");
}
 
uintptr_t    Serializer::serialize(Data* ptr) {
    return reinterpret_cast<std::uintptr_t>(ptr);
}
 
Data*        Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}