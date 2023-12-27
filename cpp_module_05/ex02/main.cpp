#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat buro("Buro", 1);
        ShrubberyCreationForm sh;
        // RobotomyRequestForm r;
        // PresidentialPardonForm p;
        // PresidentialPardonForm p2(p);

        buro.signForm(sh);
        sh.execute(buro);

        // buro.signForm(r);
        // r.execute(buro);

        // buro.signForm(p);
        // p.execute(buro);
        // std::cout << std::endl << p << std::endl << std::endl;
        // std::cout << std::endl << p2 << std::endl << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}