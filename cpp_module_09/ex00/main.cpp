#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            BitcoinExchange btc;
            std::string file(av[1]);
            btc.btc_func(file);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
    }
    return (0);
}