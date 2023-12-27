#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <cstdlib>

class RPN
{
    public:
        RPN(void);
        RPN(const RPN &);
        RPN &operator = (const RPN &);
        ~RPN(void);
        void calculation(std::string);
    private:
        std::string noSpace(std::string);
        double operation(double, double, char);
        double add(double, double);
        double subtract(double, double);
        double multiply(double, double);
        double divide(double, double);
        static bool isSpace(char, char);
        static bool isOperator(char);
        std::stack<double> m_stack;
};

#endif