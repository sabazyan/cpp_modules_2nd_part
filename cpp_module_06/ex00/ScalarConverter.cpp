#include "ScalarConverter.hpp"

enum types
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(const std::string &str)
{
    if (pseudoLiterals(str))
    {
        return;
    }
    if (detectType(str) == -1)
    {
        std::cout << "Wrong type!" << std::endl;
        return;
    }
    if(detectType(str) == CHAR)
    {
        charType(str);
    }
    else if (detectType(str) == INT)
    {
        intType(str);
    }
    else
    {
        floatDoubleType(str);
    }
}

int ScalarConverter::pseudoLiterals(const std::string &str)
{
    if (!str.compare("nan") || !str.compare("-inf") || !str.compare("+inf"))
    {
        std::cout << "char:\t" << "impossible" << std::endl;
        std::cout << "int:\t" << "impossible" << std::endl;
        std::cout << "float:\t" << str << "f" << std::endl;
        std::cout << "double:\t" << str << std::endl;
        return 1;
    }
    else if (!str.compare("nanf") || !str.compare("-inff") || !str.compare("+inff"))
    {
        std::cout << "char:\t" << "impossible" << std::endl;
        std::cout << "int:\t" << "impossible" << std::endl;
        std::cout << "float:\t" << str << std::endl;
        std::cout << "double:\t" << str.substr(0, str.length() - 1) << std::endl;
        return 1;
    }
    return 0;
}

int ScalarConverter::detectType(const std::string &str)
{
    int len = str.length();
    if (len == 1 && !isdigit(str[0]))
    {
        return CHAR;
    }
    if (str[0] == '-' || isdigit(str[0]))
    {
        for (int i = 1; i < len; ++i)
        {
            if (!isdigit(str[i]))
            {
                if (str[i - 1] != '-' && str[i] == '.' && str[i + 1] && isdigit(str[i + 1]))
                {
                    for (int j = i + 1; j < len; ++j)
                    {
                        if (!isdigit(str[j]) && str[j] == 'f' && j == len - 1)
                        {
                            return FLOAT;
                        }
                        else if (!isdigit(str[j]))
                        {
                            return -1;
                        }
                    }
                    return DOUBLE;
                }
                else
                {
                    return -1;
                }
            }
        }
        return INT;
    }
    return -1;
}

void ScalarConverter::charType(const std::string &str)
{
    char ch = str[0];
    int i = static_cast<int>(ch);
    float f = static_cast<float>(ch);
    double d = static_cast<double>(ch);
    std::cout << "char:\t" << "'" << ch << "'" << std::endl;
    std::cout << "int:\t" << i << std::endl;
    std::cout << "float:\t" << f << ".0f" << std::endl;
    std::cout << "double:\t" << d << ".0" << std::endl;
}

void ScalarConverter::utilCharInt(double d)
{
    if (d > CHAR_MAX || d < CHAR_MIN)
    {
        std::cout << "char:\t" << "impossible" << std::endl;
    }
    else if (d >= 32 && d <= 126)
    {
        char ch = static_cast<char>(d);
        std::cout << "char:\t" << "'" << ch << "'" << std::endl;
    }
    else
    {
        std::cout << "char:\t" << "Non displayable" << std::endl;
    }
    
    if (d > INT_MAX || d < INT_MIN)
    {
        std::cout << "int:\t" << "impossible" << std::endl;
    }
    else
    {
        int i = static_cast<int>(d);
        std::cout << "int:\t" << i << std::endl;
    }
}

void ScalarConverter::intType(const std::string &str)
{
    double d = strtod(str.c_str(), NULL);
    utilCharInt(d);
    float f = static_cast<float>(d);
    if (f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity())
    {
        std::cout << "float:\t" << f << ".0f" << std::endl;
    }
    else
    {
        std::cout << "float:\t" << f << std::endl;
    }
    if (d != std::numeric_limits<double>::infinity() && d != -std::numeric_limits<double>::infinity())
    {
        std::cout << "double:\t" << d << ".0" << std::endl;
    }
    else
    {
        std::cout << "double:\t" << d << ".0" << std::endl;
    }
}

void ScalarConverter::floatDoubleType(const std::string &str)
{
    double d = strtod(str.c_str(), NULL);
    utilCharInt(d);

    int count = 0;
    int length = str.length();
    bool isDot = false;
    int idx;
    for (idx = length - 1; idx >= 0 && (str[idx] == '0' || str[idx] == 'f'); --idx)
    {
        if (str[idx] == '0')
        {
            ++count;
        }
    }
    if (str[idx] && str[idx] == '.')
    {
        isDot = true;
    }

    if (d > __FLT_MAX__ || d < (-1 * __FLT_MAX__))
    {
        std::cout << "float:\t" << "impossible" << std::endl;
        std::cout << "double:\t" << d << std::endl;
    }
    else
    {
        float f = static_cast<float>(d);
        if (!count)
        {
            std::cout << "float:\t" << f << "f" << std::endl;
            std::cout << "double:\t" << d << std::endl;
        }
        else
        {
            std::cout << "float:\t" << f;
            if (isDot)
            {
                std::cout << ".";
            }
            for (int i = 0; i < count; ++i)
            {
                std::cout << "0";
            }
            std::cout << "f" << std::endl;
            
            std::cout << "double:\t" << d;
            if (isDot)
            {
                std::cout << ".";
            }
            for (int i = 0; i < count; ++i)
            {
                std::cout << "0";
            }
            std::cout << std::endl;
        }
    }    
}