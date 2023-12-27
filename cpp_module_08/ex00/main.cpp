#include "easyfind.hpp"

int main()
{
    //vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    try
    {
        int value = 3;
        int value_2 = 42;
        std::cout << easyfind(vec, value) << std::endl;
        std::cout << easyfind(vec, value_2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    //array
    std::array<int, 3> arr = {1, 3, 5};
    try
    {
        int value_arr = 3;
        int value_arr2 = 42;
        std::cout << easyfind(arr, value_arr) << std::endl;
        std::cout << easyfind(arr, value_arr2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}