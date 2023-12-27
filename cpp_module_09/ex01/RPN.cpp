#include "RPN.hpp"

RPN::RPN(void) {};

RPN::RPN(const RPN &other) : m_stack(other.m_stack) {};

RPN &RPN::operator = (const RPN &other)
{
    if (this != &other)
    {
        this->m_stack = other.m_stack;
    }
    return (*this);
}

RPN::~RPN(void) {};

void RPN::calculation(std::string line)
{
    if (line.empty())
    {
        throw std::invalid_argument("Error: Empty argument!");
    }
    std::string cleared_line = noSpace(line);
    if (cleared_line.empty())
        throw std::invalid_argument("Error: Empty string");
    std::string line_2;
    std::unique_copy(cleared_line.begin(), cleared_line.end(), std::back_insert_iterator<std::string>(line_2), isSpace);
    std::istringstream iss(line_2);
    std::string splitted_data;
    double value1, value2;
    double result;
    bool flag = false;
    while (getline(iss, splitted_data, ' '))
    {
        if (splitted_data.size() == 1 && splitted_data.find_first_not_of("0123456789+-/*") == std::string::npos)
        {
            if (isdigit(splitted_data[0]))
            {
                this->m_stack.push(atoi(splitted_data.c_str()));
            }
            else if (isOperator(splitted_data[0]) && this->m_stack.size() >= 2)
            {
                flag = true;
                value1 = this->m_stack.top();
                this->m_stack.pop();
                value2 = this->m_stack.top();
                this->m_stack.pop();
                result = operation(value2, value1, splitted_data.at(0));
                this->m_stack.push(result);
            }
            else
                throw std::runtime_error("Error: Invalid");
        }
        else
            throw std::invalid_argument("Error: Invalid values");
    }
    if (this->m_stack.size() == 1 && flag)
        std::cout << "result: " << this->m_stack.top() << std::endl;
    else
        throw std::runtime_error("Error: bad input");
};

std::string RPN::noSpace(std::string line)
{
    line.erase(0, line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ") + 1, line.length());
    return (line);
};

double RPN::operation(double num1, double num2, char op)
{
    if (op == '+')
        return (add(num1, num2));
    else if (op == '-')
        return (subtract(num1, num2));
    else if (op == '*')
        return (multiply(num1, num2));
    else if (op == '/')
        return (divide(num1, num2));
    else
        throw std::invalid_argument("Error: Wrong operation");
};

double RPN::add(double num1, double num2)
{
    return (num1 + num2);
};

double RPN::subtract(double num1, double num2)
{
    return (num1 - num2);
};

double RPN::multiply(double num1, double num2)
{
    return (num1 * num2);
};

double RPN::divide(double num1, double num2)
{
    if (num2 == 0)
    {
        throw std::invalid_argument("Error: Can't divide by 0");
    }
    return (num1 / num2);
};

bool RPN::isSpace(char c1, char c2)
{
    return (isspace(c1) && isspace(c2));
};

bool RPN::isOperator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/');
};