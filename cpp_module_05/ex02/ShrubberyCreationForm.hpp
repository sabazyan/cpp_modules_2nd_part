#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm 
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string);
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
        ~ShrubberyCreationForm(void);

        void execute(Bureaucrat const &executor) const;
    private:
        std::string m_target;
};

#endif