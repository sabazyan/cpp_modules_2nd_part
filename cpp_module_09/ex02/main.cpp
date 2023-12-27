#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc > 2)
    {
        try
        {
            PmergeMe pmg;
            std::vector<int> vec;
            std::deque<int> deq;

            pmg.parsing(argv);
            vec = pmg.getVector();
            deq = pmg.getDeque();

            std::cout << "Before: ";
            // pmg.printVector(vec);
            pmg.printDeque(deq);
            std::cout << std::endl;

            double start_vec = pmg.getTime();
            pmg.FordJohnsonVector();
            double end_vec = pmg.getTime();
            
            double start_deq = pmg.getTime();
            pmg.FordJohnsonDeque();
            double end_deq = pmg.getTime();

            vec = pmg.getVector();
            deq = pmg.getDeque();

            std::cout << std::endl;
            std::cout << "After: ";
            // pmg.printVector(vec);
            pmg.printDeque(deq);
            std::cout << std::endl;

            std::cout << "Time to process a range of " << pmg.getVectorSize() << " elements with std::vector : " << (end_vec - start_vec) << " us" << std::endl;
            std::cout << "Time to process a range of " << pmg.getDequeSize() << " elements with std::deque : " << (end_deq - start_deq) << " us" << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: Arguments must be more than 1" << std::endl;
    return (0);
}