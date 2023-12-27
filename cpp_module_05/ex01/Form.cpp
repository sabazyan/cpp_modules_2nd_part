#include "Form.hpp"

Form::Form(void) : m_name("Form"), m_isSigned(false), m_gradeSign(20), m_gradeExecute(30)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, bool isSigned, int gradeSign, int gradeExecute)
    : m_name(name), m_gradeSign(gradeSign), m_gradeExecute(gradeExecute)
{
    std::cout << "Form constructor with parameters called" << std::endl;
    m_isSigned = isSigned;
    if (m_gradeSign < 1 || m_gradeExecute < 1)
    {
        throw GradeException("Grade Too High Exception");
    }
    else if (m_gradeSign > 150 || m_gradeExecute > 150)
    {
        throw GradeException("Grade Too Low Exception");
    }
}

Form::Form(const Form &other) : m_name(other.m_name), m_gradeSign(other.m_gradeSign),
    m_gradeExecute(other.m_gradeExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
    m_isSigned = other.m_isSigned;
}

Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {
        m_isSigned = rhs.m_isSigned;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
    out << rhs.getName() << ", form grade sign " << rhs.getGradeSign()
        << ", and grade execute " << rhs.getGradeExecute()
        << ", ";
    if (rhs.getIsSigned())
    {
        out << "and is signed.";
    }
    else
    {
        out << "and is not signed.";
    }
    return out;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

const std::string Form::getName() const
{
    return m_name;
}

bool Form::getIsSigned() const
{
    return m_isSigned;
}

int Form::getGradeSign() const
{
    return m_gradeSign;
}

int Form::getGradeExecute() const
{
    return m_gradeExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= m_gradeSign && !m_isSigned)
    {
        m_isSigned = true;
    }
    else
    {
        throw GradeException("Grade Too Low Exception");
    }
}

Form::GradeException::GradeException(const std::string &str)
{
    message = str;
}

Form::GradeException::~GradeException() throw() {}

const char *Form::GradeException::what() const throw()
{
    return message.c_str();
}