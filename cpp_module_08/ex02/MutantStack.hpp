#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <list>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void) {}
        MutantStack(const MutantStack &other) : std::stack<T>(other) {}
        MutantStack &operator=(const MutantStack &rhs)
        {
            if (this != &rhs)
            {
                this->stack.operator=(rhs);
            }
            return *this;
        }
        ~MutantStack(void) {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};

#endif