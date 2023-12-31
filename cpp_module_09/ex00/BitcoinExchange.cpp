#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m_map(other.m_map) {};

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->m_map = other.m_map;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {};

void BitcoinExchange::btc_func(std::string file)
{
    try
    {
        readingDataFile();
        readingInputFile(file);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
}

void BitcoinExchange::readingInputFile(std::string file)
{
    std::ifstream data(file);
    std::string line;
    std::string date;
    double value;
    size_t pos;
    int invalid;

    if (file.empty())
    {
        throw std::invalid_argument("Error: No filename provided");
    }
    else if (file.compare("data.csv") == 0)
    {
        throw std::runtime_error("Error: Invalid file");
    }
    if (!data.is_open() || !data.good())
    {
        throw std::runtime_error("Error: Not existing file");
    }
    getline(data, line);
    if (line != "date | value")
    {
        data.close();
        throw std::runtime_error("Error: Invalid file format");
    }
    while (!data.eof()) 
    {
        getline(data, line);
        if ((pos = line.find("|")) != std::string::npos)
        {
            if (!isValidDate(noSpace(line.substr(0, pos))))
            {
                std::cout << "Error: bad input " << noSpace(line.substr(0, pos)) << ":" << std::endl;
            }
            else
            {
                date = noSpace(line.substr(0, pos));
            }
            invalid = isValidValue(noSpace(line.substr(pos + 1, line.length())));
            switch (invalid)
            {
                case 1:
                    value = std::strtod((noSpace(line.substr(pos + 1))).c_str(), NULL);
                    break;
                case 2:
                    std::cout << "Error: Invalid value => " << noSpace(line.substr(pos + 1)) << std::endl;
                    break;
                case 3:
                    std::cout << "Error: not a positive number." << std::endl;
                    break;
                default:
                    std::cout << "Error: too large a number." << std::endl;
            }
            if (isValidDate(noSpace(line.substr(0, pos))) && invalid == 1)
            {
                std::map<std::string, double>::iterator it = this->m_map.lower_bound(date);
                if (it != this->m_map.end())
                {
                    double money = it->second * value;
                    std::cout << date << " => " << value << " = " << money << std::endl;
                }
                else
                {
                    std::cout << "Error: Not found -> " << date << std::endl;
                } 
            }
        }
        else
        {
            std::cout << "Error: bad input => " << line <<  std::endl;
        }
    }
}

bool BitcoinExchange::isValidDate(std::string line)
{
    if (line.length() != 10)
    {
        return (false);
    }
    for (size_t i = 0; i < line.size(); i++)
    {
        if ((i == 4 || i == 7))
        {
            if (line[i] != '-')
                return (false);
        }
        else 
        {
            if (!isdigit(line[i]))
                return (false);
        }
    }

    std::istringstream ss(line.c_str());
    std::string splitted_date;
    int year;
    int month;
    int day;
    int index = 0;
    while (getline(ss, splitted_date, '-'))
    {
        std::istringstream iss(splitted_date);
        if (index == 0)
        {
            if (splitted_date.size() != 4)
                return (false);
            iss >> year;
            if (iss.fail() || iss.bad() || iss.get() != EOF)
                return false;
        }
        else if (index == 1)
        {
            if (splitted_date.size() != 2)
                return (false);
            iss >> month;
            if (iss.fail() || iss.bad() || iss.get() != EOF)
                return (false);
            if (month < 1 || month > 12)
                return (false);
        }
        else if (index == 2)
        {
            if (splitted_date.size() != 2)
                return (false);
            iss >> day;
            if (iss.fail() || iss.bad() || iss.get() != EOF)
                return (false);
            if (day < 1 || day > 31)
                return (false);
            else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
                return (false);
            else if (month == 2 && isLeapYear(year) && day > 29)
                return (false);
            else if (month == 2 && !isLeapYear(year) && day > 28)
                return (false);
        }
        index++;
    }
    return (true);
}

int BitcoinExchange::isValidValue(std::string line)
{
    char* endPtr;
    double value = std::strtod(line.c_str(), &endPtr);
    std::string end(endPtr);
    if (!end.empty())
    {
        return (2);
    }
    else if (value < 0 || value > 1000)
    {
        if (value < 0)
            return (3);
        else if (value > 1000)
            return (4);
    }
    return (1);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void BitcoinExchange::readingDataFile(void)
{
    std::ifstream data;
    std::string line;
    std::string date;
    size_t pos;
    data.open("data.csv");
    if (!data.is_open())
    {
        throw std::runtime_error("Error: Can't open 'data.csv' file");
    }
    getline(data, line);
    if (line.empty() || line != "date,exchange_rate")
    {
        throw std::runtime_error("Error: invalid data");
    }
    while (!data.eof()) 
    {
        getline(data, line);
        if (line.empty())
            continue;
        if (line != "date,exchange_rate")
        {
            if ((pos = line.find(",")) != std::string::npos)
            {
                date = line.substr(0, pos);
                this->m_map[date] = std::strtod(line.substr(pos + 1).c_str(), NULL);
            }
            else
                throw std::runtime_error("Error: 'data.csv' file is in wrong format");
        }
    }
    data.close();
}

std::string BitcoinExchange::noSpace(std::string line)
{
    line.erase(0, line.find_first_not_of(" "));
    line.erase(line.find_last_not_of(" ") + 1, line.length());
    return (line);
}































