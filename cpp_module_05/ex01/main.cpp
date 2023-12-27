#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat buro("Buro", 30);
        Form form("Formik", false, 110, 25);

        std::cout << std::endl;
        std::cout << buro << std::endl;
        std::cout << form << std::endl;
        std::cout << form.getIsSigned() << std::endl;
        form.beSigned(buro);
        std::cout << form.getIsSigned() << std::endl;
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}