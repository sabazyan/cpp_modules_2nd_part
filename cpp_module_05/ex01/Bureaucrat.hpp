#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &);
        Bureaucrat &operator=(const Bureaucrat &);
        ~Bureaucrat(void);

        const std::string getName() const;
        int getGrade() const;
        void increment(void);
        void decrement(void);

        void signForm(Form &);

    private:
        const std::string m_name;
        int m_grade;

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif