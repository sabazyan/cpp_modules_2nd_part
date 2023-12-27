#include "Span.hpp"

Span::Span(void) : m_size(0) {}

Span::Span(size_t n) : m_size(n) {}

Span::Span(const Span &rhs) : m_size(rhs.m_size), m_vec(rhs.m_vec) {}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
        m_size = rhs.m_size;
    }
    return *this;
}

Span::~Span(void) {}

void Span::addNumber(int value)
{
    if (m_vec.size() < m_size)
    {
        m_vec.push_back(value);
    }
    else
    {
		throw std::invalid_argument("No space left in vector.");
    }
}

int Span::shortestSpan(void)
{
    if (m_vec.empty() || m_vec.size() == 1)
		throw std::invalid_argument("There are 0 or 1 element in vector.");
    
    std::sort(m_vec.begin(), m_vec.end());
    int span = *(m_vec.end() - 1) - *m_vec.begin();
    
    std::vector<int>::iterator it;
    for (it = m_vec.begin() + 1; it != m_vec.end(); ++it)
    {
        if (*it - *(it - 1) < span)
        {
            span = *it - *(it - 1);
        }
    }
	return span;
}

int Span::longestSpan(void)
{
    if (m_vec.empty() || m_vec.size() == 1)
		throw std::invalid_argument("There are 0 or 1 element in vector.");
    
    std::sort(m_vec.begin(), m_vec.end());
    int span = *(m_vec.end() - 1) - *m_vec.begin();
	return span;
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (begin > end)
    {
        return;
    }
    else if ((m_vec.size() + (int)(end - begin)) > m_size)
    {
        throw std::invalid_argument("No space left in vector.");
    }
    else
    {
        m_vec.insert(m_vec.end(), begin, end);
    }
}