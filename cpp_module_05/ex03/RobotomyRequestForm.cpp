#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", false, 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
    m_target = "RobotomyTarget";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45)
{
    std::cout << "RobotomyRequestForm constructor with parameters called" << std::endl;
    m_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    m_target = other.m_target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        m_target = rhs.m_target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() && executor.getGrade() <= this->getGradeExecute())
    {
        std::srand(time(NULL));
        int num = rand() % 2;
        if (num)
        {
            std::cout << m_target << " has been robotomized successfully 50% of the time." << std::endl;
        }
        else
        {
            std::cout << "The robotomy failed." << std::endl;
        }
    }
    else
    {
        throw GradeException("Grade Too Low Exception");
    }
}