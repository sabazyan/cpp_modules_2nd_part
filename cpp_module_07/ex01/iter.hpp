#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T>
void func(T &i)
{
    std::cout << i << std::endl;
}

template<typename T>
void iter(T *value, int length, void (*function)(T &i))
{
    for (int i = 0; i < length; ++i)
    {
        function(value[i]);
    }
}

template<typename T, typename C>
void iter(T *value, int length, void (*function)(C &i))
{
    for (int i = 0; i < length; ++i)
    {
        function(value[i]);
    }
}

#endif