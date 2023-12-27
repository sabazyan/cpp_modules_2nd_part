#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

struct Data
{
    unsigned int i;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer(void);
        Serializer(const Serializer &);
        Serializer &operator=(const Serializer &);
        ~Serializer(void);
};

#endif