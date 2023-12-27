#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &);
        Intern &operator=(const Intern &);
        ~Intern(void);

        AForm *makeForm(const std::string &, const std::string &);
    private:
        AForm *makeShrubbery(const std::string &);
        AForm *makeRobotomy(const std::string &);
        AForm *makePresidential(const std::string &);
};

#endif