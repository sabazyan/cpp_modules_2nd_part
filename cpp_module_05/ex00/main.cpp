#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1;
        Bureaucrat b2("Buro", 0);
        b2.decrement();
        // b2 = b1;
        Bureaucrat b3 = b1;
        
        std::cout << std::endl;
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
        std::cout << std::endl;    
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}