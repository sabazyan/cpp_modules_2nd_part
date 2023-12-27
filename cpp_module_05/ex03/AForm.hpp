#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(const std::string, bool, const int, const int);
        AForm(const AForm &);
        AForm &operator=(const AForm &);
        virtual ~AForm(void);

        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        
        void beSigned(Bureaucrat &);
        virtual void execute(Bureaucrat const &executor) const = 0;

    private:
        const std::string m_name;
        bool m_isSigned;
        const int m_gradeSign;
        const int m_gradeExecute;

    protected:
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

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif