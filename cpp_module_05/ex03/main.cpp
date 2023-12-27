#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    AForm *form;

    std::cout << std::endl;
    form = intern.makeForm("President", "Bender");
    std::cout << std::endl;
    delete form;
    return 0;
}