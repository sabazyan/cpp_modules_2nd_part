#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &) {}

Serializer &Serializer::operator=(const Serializer &)
{
    return *this;
}

Serializer::~Serializer(void) {}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t ui = reinterpret_cast<uintptr_t>(ptr);
    return ui;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data*>(raw);
    return data;
}