#include "AForm.hpp"

AForm::AForm(void) : m_name("AForm"), m_isSigned(false), m_gradeSign(20), m_gradeExecute(30)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, int gradeSign, int gradeExecute)
    : m_name(name), m_gradeSign(gradeSign), m_gradeExecute(gradeExecute)
{
    std::cout << "AForm constructor with parameters called" << std::endl;
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

AForm::AForm(const AForm &other) : m_name(other.m_name), m_gradeSign(other.m_gradeSign),
    m_gradeExecute(other.m_gradeExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
    m_isSigned = other.m_isSigned;
}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {
        m_isSigned = rhs.m_isSigned;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
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

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}

const std::string AForm::getName() const
{
    return m_name;
}

bool AForm::getIsSigned() const
{
    return m_isSigned;
}

int AForm::getGradeSign() const
{
    return m_gradeSign;
}

int AForm::getGradeExecute() const
{
    return m_gradeExecute;
}

void AForm::beSigned(Bureaucrat &b)
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

AForm::GradeException::GradeException(const std::string &str)
{
    message = str;
}

AForm::GradeException::~GradeException() throw() {}

const char *AForm::GradeException::what() const throw()
{
    return message.c_str();
}