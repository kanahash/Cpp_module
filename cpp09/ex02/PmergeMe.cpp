#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vecComparisons(0), deqComparisons(0) {}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
    : vec(other.vec),
      deq(other.deq),
      vecComparisons(other.vecComparisons),
      deqComparisons(other.deqComparisons) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
        vecComparisons = other.vecComparisons;
        deqComparisons = other.deqComparisons;
    }
    return (*this);
}

std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> j;

    if (n <= 1)
        return j;

    int a = 1;
    int b = 3;

    j.push_back(0);
    j.push_back(1);

    while (b < n)
    {
        j.push_back(b);
        int next = b + 2 * a;
        a = b;
        b = next;
    }
    return j;
}

struct VecCompare
{
    size_t* counter;
    VecCompare(size_t* c) : counter(c) {}
    bool operator()(int a, int b)
    {
        (*counter)++;
        return a < b;
    }
};

void PmergeMe::sortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::vector<VecPair> pairs;
    size_t i = 0;

    for (; i + 1 < arr.size(); i += 2)
    {
        VecPair p;
        vecComparisons++;

        if (arr[i] < arr[i + 1])
        {
            p.small = arr[i];
            p.large = arr[i + 1];
        }
        else
        {
            p.small = arr[i + 1];
            p.large = arr[i];
        }

        pairs.push_back(p);
    }

    bool hasStraggler = (i < arr.size());
    int straggler = hasStraggler ? arr[i] : 0;

    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].large);

    sortVector(mainChain);

    std::vector<size_t> position(pairs.size());
    for (size_t j = 0; j < pairs.size(); ++j)
    {
        for (size_t k = 0; k < mainChain.size(); ++k)
        {
            if (mainChain[k] == pairs[j].large)
            {
                position[j] = k;
                break;
            }
        }
    }

    for (size_t j = 0; j < pairs.size(); ++j)
    {
        size_t left = 0;
        size_t right = position[j];

        while (left < right)
        {
            size_t mid = (left + right) / 2;
            vecComparisons++;

            if (pairs[j].small < mainChain[mid])
                right = mid;
            else
                left = mid + 1;
        }

        mainChain.insert(mainChain.begin() + left, pairs[j].small);

        for (size_t k = 0; k < position.size(); ++k)
        {
            if (position[k] >= left)
                position[k]++;
        }
    }

    if (hasStraggler)
    {
        size_t left = 0;
        size_t right = mainChain.size();

        while (left < right)
        {
            size_t mid = (left + right) / 2;
            vecComparisons++;

            if (straggler < mainChain[mid])
                right = mid;
            else
                left = mid + 1;
        }

        mainChain.insert(mainChain.begin() + left, straggler);
    }

    arr = mainChain;
}

struct DeqCompare
{
    size_t* counter;
    DeqCompare(size_t* c) : counter(c) {}
    bool operator()(int a, int b)
    {
        (*counter)++;
        return a < b;
    }
};

void PmergeMe::sortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::deque<std::pair<int,int> > pairs;
    std::deque<int> mainChain;
    std::deque<int> pend;

    size_t i = 0;

    for (; i + 1 < arr.size(); i += 2)
    {
        deqComparisons++;
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    bool hasStraggler = (i < arr.size());
    int straggler = hasStraggler ? arr[i] : 0;

    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].second);

    sortDeque(mainChain);

    for (size_t j = 0; j < pairs.size(); ++j)
        pend.push_back(pairs[j].first);

    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    DeqCompare comp(&deqComparisons);

    for (size_t j = 0; j < jacob.size(); ++j)
    {
        int idx = jacob[j];
        if (idx >= (int)pend.size())
            continue;

        int pairSecond = pairs[idx].second;

        std::deque<int>::iterator bound =
            std::find(mainChain.begin(), mainChain.end(), pairSecond);

        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), bound, pend[idx], comp);

        mainChain.insert(pos, pend[idx]);
        inserted[idx] = true;
    }

    for (size_t j = 0; j < pend.size(); ++j)
    {
        if (inserted[j])
            continue;

        int pairSecond = pairs[j].second;

        std::deque<int>::iterator bound =
            std::find(mainChain.begin(), mainChain.end(), pairSecond);

        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), bound, pend[j], comp);

        mainChain.insert(pos, pend[j]);
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler, comp);

        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::run(int ac, char **av)
{
    if (ac < 2)
        return;

    try
    {
        vec.clear();
        deq.clear();
        vecComparisons = 0;
        deqComparisons = 0;

        for (int i = 1; i < ac; ++i)
        {
            std::string arg = av[i];

            if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
                throw std::runtime_error("Error");

            std::stringstream ss(arg);
            long val;

            if (!(ss >> val) || val < 0 || val > INT_MAX)
                throw std::runtime_error("Error");

            vec.push_back(static_cast<int>(val));
            deq.push_back(static_cast<int>(val));
        }

        std::cout << "Before: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        std::clock_t startVec = std::clock();
        sortVector(vec);
        std::clock_t endVec = std::clock();

        std::clock_t startDeq = std::clock();
        sortDeque(deq);
        std::clock_t endDeq = std::clock();

        std::cout << "After:  ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        double timeVec =
            static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

        double timeDeq =
            static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of "
                  << vec.size()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5)
                  << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of "
                  << deq.size()
                  << " elements with std::deque  : "
                  << std::fixed << std::setprecision(5)
                  << timeDeq << " us" << std::endl;

        std::cout << "Vector comparisons: " << vecComparisons << std::endl;
        std::cout << "Deque comparisons : " << deqComparisons << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
