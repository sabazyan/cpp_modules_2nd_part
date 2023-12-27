#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cstdlib>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange &operator = (const BitcoinExchange &);
        ~BitcoinExchange(void);
        void btc_func(std::string);
    private:
        void readingInputFile(std::string);
        bool isValidDate(std::string);
        int isValidValue(std::string);
        bool isLeapYear(int);
        void readingDataFile(void);
        std::string noSpace(std::string);
        std::map< std::string, double, std::greater<std::string> > m_map;
};

#endif