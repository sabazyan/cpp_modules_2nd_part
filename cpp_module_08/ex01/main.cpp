#include "Span.hpp"

int main() {
    Span sp = Span(10);
    
    std::vector<int> vec;
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(3);
    
    try
    {
        sp.addNumber(2);
        sp.addNumber(5);
        sp.addNumber(4);
        sp.addNumber(42);

        sp.fill(vec.begin(), vec.end());

        std::cout << "The shortest span is " << sp.shortestSpan() << std::endl;
        std::cout << "The longest span is " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}