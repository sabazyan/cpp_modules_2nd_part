#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe &other) : m_vec(other.m_vec), m_deq(other.m_deq) {};

PmergeMe &PmergeMe::operator = (const PmergeMe &other)
{
    if (this != &other)
    {
        this->m_vec = other.m_vec;
        this->m_deq = other.m_deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void) {};

void PmergeMe::parsing(char **argv)
{
    int i = 1;
    int value;
    while (argv[i] != NULL)
    {
        std::string str(argv[i]);
        if (str.empty())
        {
            throw std::invalid_argument("Error: Arguments must not be empty!");
        }
        if (str.find_first_not_of("0123456789") == std::string::npos)
        {
            value = atoi(str.c_str());
            if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
                throw std::out_of_range("Error: Numbers have to be in the range of int!");
            else if (value < 0)
                throw std::runtime_error("Error: Invalid arguments");
            else
            {
                this->m_vec.push_back(value);
                this->m_deq.push_back(value);
            }
        }
        else
            throw std::invalid_argument("Error: Invalid arguments");
        i++;
    }
}

void PmergeMe::FordJohnsonVector(void)
{
    size_t size = getVectorSize();
    bool is_odd = size % 2;
    std::vector<std::pair<int, int> > new_vec;
    new_vec.reserve(size / 2);
    size_t end = is_odd ? size - 1: size;
    int last = this->m_vec[size - 1];
    for (size_t i = 0; i < end; i += 2)
    {
        new_vec.push_back(std::make_pair(this->m_vec[i], this->m_vec[i + 1]));
    }
    swapPairElementsVector(new_vec);
    std::sort(new_vec.begin(), new_vec.end(), sortPairs);
    this->m_vec.clear();
    this->m_vec.push_back(new_vec[0].second);
    std::vector<int> smallests;
    for (size_t i = 0; i < new_vec.size(); i++)
    {
        this->m_vec.push_back(new_vec[i].first);
        if (i > 0)
             smallests.push_back(new_vec[i].second);
    }
    if (is_odd)
        smallests.push_back(last);

    int Jn_2 = 1;
	int Jn_1 = 1;
	int Jn = Jn_1 + 2 * Jn_2;
	while (Jn - 2 < static_cast<int>(smallests.size()))
	{
		for (int j = Jn - 2; j >= Jn_1 - 1; --j)
		{
			std::vector<int>::iterator it = std::upper_bound(this->m_vec.begin(), this->m_vec.end(), smallests[j]);
			this->m_vec.insert(it, smallests[j]);
		}
		Jn_2 = Jn_1;
		Jn_1 = Jn;
		Jn = Jn_1 + 2 * Jn_2;
	}
	for (int j = smallests.size() - 1; j > Jn_1 - 2; --j)
	{
		std::vector<int>::iterator it = std::upper_bound(this->m_vec.begin(), this->m_vec.end(), smallests[j]);
		this->m_vec.insert(it, smallests[j]);
	}
}

void PmergeMe::FordJohnsonDeque(void)
{
    size_t size = getDequeSize();
    bool is_odd = size % 2;
    std::deque<std::pair<int, int> > new_deq;
    size_t end = is_odd ? size - 1: size;
    int last = this->m_vec[size - 1];
    for (size_t i = 0; i < end; i += 2)
    {
        new_deq.push_back(std::make_pair(this->m_deq[i], this->m_deq[i + 1]));
    }
    swapPairElementsDeque(new_deq);
    std::sort(new_deq.begin(), new_deq.end(), sortPairs);
    this->m_deq.clear();
    this->m_deq.push_back(new_deq[0].second);
    std::deque<int> smallests;
    for (size_t i = 0; i < new_deq.size(); i++)
    {
        this->m_deq.push_back(new_deq[i].first);
        if (i > 0)
            smallests.push_back(new_deq[i].second);
    }
    if (is_odd)
        smallests.push_back(last);
    int Jn_2 = 1;
	int Jn_1 = 1;
	int Jn = Jn_1 + 2 * Jn_2;
	while (Jn - 2 < static_cast<int>(smallests.size()))
	{
		for (int j = Jn - 2; j >= Jn_1 - 1; --j)
		{
			std::deque<int>::iterator it = std::upper_bound(this->m_deq.begin(), this->m_deq.end(), smallests[j]);
			this->m_deq.insert(it, smallests[j]);
		}
		Jn_2 = Jn_1;
		Jn_1 = Jn;
		Jn = Jn_1 + 2 * Jn_2;
	}
	for (int j = smallests.size() - 1; j > Jn_1 - 2; --j)
	{
		std::deque<int>::iterator it = std::upper_bound(this->m_deq.begin(), this->m_deq.end(), smallests[j]);
		this->m_deq.insert(it, smallests[j]);
	}
}

void PmergeMe::printVector(const std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
}

void PmergeMe::printDeque(const std::deque<int> &deq)
{
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";
}

double PmergeMe::getTime(void)
{
    struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (static_cast<double>(tv.tv_usec) / 1000));
}

std::vector<int> PmergeMe::getVector(void) const
{
    return (this->m_vec);
}

std::deque<int> PmergeMe::getDeque(void) const
{
    return (this->m_deq);
}

size_t PmergeMe::getVectorSize(void) const
{
    return (this->m_vec.size());
}

size_t PmergeMe::getDequeSize(void) const
{
    return (this->m_deq.size());
}

void PmergeMe::swapPairElementsVector(std::vector< std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

void PmergeMe::swapPairElementsDeque(std::deque< std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

bool sortPairs(std::pair<int, int> &p1, std::pair<int, int> &p2)
{
    if (p1.first < p2.first)
        return (true);
    return (false);
}