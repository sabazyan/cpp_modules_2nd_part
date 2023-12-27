#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    public:
        static void convert(const std::string &);

    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter &);
        ~ScalarConverter(void);
        static int pseudoLiterals(const std::string &);
        static int detectType(const std::string &);
        static void charType(const std::string &);
        static void utilCharInt(double);
        static void intType(const std::string &);
        static void floatDoubleType(const std::string &);
};

#endif