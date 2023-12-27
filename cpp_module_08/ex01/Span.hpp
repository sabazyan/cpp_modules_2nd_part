#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>

class Span 
{
    public:
        Span(void);
        Span(size_t n);
        Span(const Span &);
        Span &operator=(const Span &);
        ~Span(void);

        void addNumber(int);
        int shortestSpan(void);
        int longestSpan(void);
        void fill(std::vector<int>::iterator, std::vector<int>::iterator);
    private:
        size_t m_size;
        std::vector<int> m_vec;
};

#endif