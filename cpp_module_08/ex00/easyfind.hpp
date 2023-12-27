#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <array>

template <typename T>
int easyfind(T container, int value)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
    {
        throw std::invalid_argument("Element not found");
    }
    return *it;
}

#endif