#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", false, 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    m_target = "ShrubberyTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", false, 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor with parameters called" << std::endl;
    m_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    m_target = other.m_target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() && executor.getGrade() <= this->getGradeExecute())
    {
        std::ofstream file;
        file.open(m_target + "_shrubbery");
        file    << "          &&& &&  & &&\n"
                << "      && &\\/&\\|& ()|/ @, &&\n"
                << "      &\\/(/&/&||/& /_/)_&/_&\n"
                << "   &() &\\/&|()|/&\\/ \"%\" & ()\n"
                << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
                << "&&   && & &| &| /& & % ()& /&&\n"
                << " ()&_---()&\\&\\|&&-&&--%---()~\n"
                << "     &&     \\|||\n"
                << "             |||\n"
                << "             |||\n"
                << "             |||\n"
                << "       , -=-~  .-^- _";
        file.close();
    }
    else
    {
        throw GradeException("Grade Too Low Exception");
    }
}