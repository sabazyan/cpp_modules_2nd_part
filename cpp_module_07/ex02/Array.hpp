#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
    public:
        Array(void) : m_arr(NULL), m_size(0) {}
        Array(size_t n) : m_arr(new T[n]), m_size(n) {
            for (size_t i = 0; i < n; ++i)
            {
                m_arr[i] = 0;
            }
        }
        Array(const Array &rhs)
        {
            m_size = rhs.m_size;
            m_arr = new T[rhs.m_size];
            for (size_t i = 0; i < rhs.m_size; ++i)
            {
                m_arr[i] = rhs.m_arr[i];
            }
        }
        Array &operator=(const Array &rhs)
        {
            if (*this != rhs)
            {
                delete[] m_arr;
                m_size = rhs.m_size;
                m_arr = new T[rhs.m_size];
                for (size_t i = 0; i < rhs.m_size; ++i)
                {
                    m_arr[i] = rhs.m_arr[i];
                }
            }
            return *this;
        }
        T &operator[](size_t i)
        {
            if (i >= m_size)
            {
                throw WrongIndex();
            }
            return m_arr[i];
        }
        ~Array(void)
        {
            delete[] m_arr;
        }
        int size(void)
        {
            return m_size;
        }
        class WrongIndex : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Index is out of range.";
                }
        };
    private:
        T *m_arr;
        size_t m_size; 
};

#endif