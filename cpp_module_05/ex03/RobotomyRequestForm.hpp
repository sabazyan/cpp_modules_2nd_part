#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string);
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &);
        ~RobotomyRequestForm(void);

        void execute(Bureaucrat const &executor) const;
    private:
        std::string m_target;
};

#endif