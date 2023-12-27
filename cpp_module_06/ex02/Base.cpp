#include "Base.hpp"

Base::~Base(void) {}

Base *generate(void)
{
    srand((unsigned) time(NULL));
	int i = rand() % 3;
    Base *ob;
    switch (i)
    {
        case 0:
            ob = new A;
            break;
        case 1:
            ob = new B;
            break;
        case 2:
            ob = new C;
            break;
    }
    return ob;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::exception &)
    {}
    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(std::exception &)
    {}
    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(std::exception &)
    {}
}