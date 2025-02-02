#ifndef __Serializer_HPP__
# define __Serializer_HPP__

#include <iostream>
#include <string>
#include <inttypes.h>  // Add this for uintptr_t

struct Data {
    int         intValue;
    std::string strValue;
};

class Serializer 
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
        ~Serializer();

    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif