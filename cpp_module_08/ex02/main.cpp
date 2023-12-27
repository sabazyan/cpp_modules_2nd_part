#include "MutantStack.hpp"

int main()
{
    //MutantStack
    MutantStack<char> stack;
    stack.push('s');
    stack.push('t');
    stack.push('a');
    stack.push('c');
    stack.push('k');

    MutantStack<char>::iterator it;
    std::cout << "----- MutantStack -----" << std::endl;
    for (it = stack.begin(); it != stack.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl << std::endl;

    //list
    std::list<char> list;
    list.push_back('l');
    list.push_back('i');
    list.push_back('s');
    list.push_back('t');

    std::list<char>::iterator ite;
    std::cout << "----- List -----" << std::endl;
    for (ite = list.begin(); ite != list.end(); ++ite)
    {
        std::cout << *ite;
    }
    std::cout << std::endl << std::endl;

    //vector
    std::vector<char> vector;
    vector.push_back('v');
    vector.push_back('e');
    vector.push_back('c');
    vector.push_back('t');
    vector.push_back('o');
    vector.push_back('r');

    std::vector<char>::iterator iter;
    std::cout << "----- Vector -----" << std::endl;
    for (iter = vector.begin(); iter != vector.end(); ++iter)
    {
        std::cout << *iter;
    }
    std::cout << std::endl;
    return 0;
}