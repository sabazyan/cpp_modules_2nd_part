#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &)
{
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &)
{
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string names[3] = {"shrubbery", "robotomy", "presidential"};
    AForm *(Intern::*functions[3])(const std::string &target) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
    for (int i = 0; i < 3; ++i)
    {
        if (names[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*functions[i])(target);
        }
    }
    std::cout << "Intern does not create a form" << std::endl;
    return NULL;
}

AForm *Intern::makeShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}