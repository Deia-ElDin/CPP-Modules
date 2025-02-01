#include "Serializer.hpp"
#include "Utils.hpp"

int main() {
    Data*       original = new Data;

    original->intValue = 42;
    original->strValue = "AD";
    
    uintptr_t   raw = Serializer::serialize(original);
    Data*       recovered = Serializer::deserialize(raw);
    
    std::cout << "Original: " << original << std::endl;
    std::cout << "Recovered: " << recovered << std::endl;
    std::cout << "Are equal: " << (original == recovered ? "true" : "false") << std::endl;
    std::cout << recovered->intValue << std::endl;
    std::cout << recovered->strValue << std::endl;

    delete original;
    return 0;
}

/*
    Objectives:
        - To understand pointer-to-integer conversions
        - To learn about reinterpret_cast (one of C++'s casting operators)
        - To understand data serialization concepts

*/