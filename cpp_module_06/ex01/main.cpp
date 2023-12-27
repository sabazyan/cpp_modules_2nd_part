#include "Serializer.hpp"

int main()
{
    Data data;
    data.i = -1;
    uintptr_t ui = Serializer::serialize(&data);
    std::cout << ui << std::endl;

    Data *data_p = Serializer::deserialize(ui);
    std::cout << data_p->i << std::endl;
    return 0;
}