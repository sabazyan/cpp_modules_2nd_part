#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &);
        ~PresidentialPardonForm(void);

        void execute(Bureaucrat const &executor) const;
    private:
        std::string m_target;
};

#endif