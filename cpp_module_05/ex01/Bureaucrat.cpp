#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Default"), m_grade(100)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : m_name(name)
{
    std::cout << "Bureaucrat constructor with parameters called" << std::endl;
    if (grade < 1)
    {
        throw GradeException("Grade Too High Exception");
    }
    else if (grade > 150)
    {
        throw GradeException("Grade Too Low Exception");
    }
    m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        m_grade = rhs.m_grade;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return out;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return m_name;
}

int Bureaucrat::getGrade() const
{
    return m_grade;
}

void Bureaucrat::increment(void)
{
    if (m_grade - 1 < 1)
    {
        throw GradeException("Grade Too High Exception");
    }
    --m_grade;
}

void Bureaucrat::decrement(void)
{
    if (m_grade + 1 > 150)
    {
        throw GradeException("Grade Too Low Exception");
    }
    ++m_grade;
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << m_name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << m_name << " couldn't sign " << f.getName()
                << " because of " << e.what() << std::endl;  
    }
}

Bureaucrat::GradeException::GradeException(const std::string &str)
{
    message = str;
}

Bureaucrat::GradeException::~GradeException() throw() {}

const char *Bureaucrat::GradeException::what() const throw()
{
    return message.c_str();
}