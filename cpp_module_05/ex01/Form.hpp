#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(const std::string &, bool, const int, const int);
        Form(const Form &);
        Form &operator=(const Form &);
        ~Form(void);

        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;

        void beSigned(Bureaucrat &);

    private:
        const std::string m_name;
        bool m_isSigned;
        const int m_gradeSign;
        const int m_gradeExecute;

        class GradeException : public std::exception
        {
            public:
                GradeException(const std::string &);
                virtual ~GradeException() throw();
                virtual const char *what() const throw();
            private:
                std::string message;
        };

};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif