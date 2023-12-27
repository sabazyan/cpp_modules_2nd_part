#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", false, 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
    m_target = "PresidentialTarget";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", false, 25, 5)
{
    std::cout << "PresidentialPardonForm constructor with parameters called" << std::endl;
    m_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    m_target = other.m_target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() && executor.getGrade() <= this->getGradeExecute())
    {
        std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
    {
        throw GradeException("Grade Too Low Exception");
    }
}