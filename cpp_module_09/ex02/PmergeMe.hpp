#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &);
        PmergeMe &operator = (const PmergeMe &);
        ~PmergeMe(void);
        void parsing(char **);
        void FordJohnsonVector(void);
        void FordJohnsonDeque(void);
        void printVector(const std::vector<int> &);
        void printDeque(const std::deque<int> &);
        double getTime(void);
        std::vector<int> getVector(void) const;
        std::deque<int> getDeque(void) const;
        size_t getVectorSize(void) const;
        size_t getDequeSize(void) const;
    private:
        void swapPairElementsVector(std::vector< std::pair<int, int> > &);
        void swapPairElementsDeque(std::deque< std::pair<int, int> > &);
        std::vector<int> m_vec;
        std::deque<int> m_deq;
};

bool sortPairs(std::pair<int, int> &, std::pair<int, int> &);

#endif