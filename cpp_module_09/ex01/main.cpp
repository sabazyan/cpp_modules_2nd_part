#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac == 2)
    {
        try
        {
            RPN rpn;
            std::string arg(av[1]);
            rpn.calculation(arg);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: Bad arguments!" << std::endl; 
    return (0);
}