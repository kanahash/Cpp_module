#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

PmergeMe::PmergeMe() : vecComparisons(0), deqComparisons(0) {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec; deq = other.deq;
        vecComparisons = other.vecComparisons;
        deqComparisons = other.deqComparisons;
    }
    return *this;
}

struct CountingCmp
{
    size_t *count;
    explicit CountingCmp(size_t *c) : count(c) {}
    bool operator()(int a, int b) const { (*count)++; return a < b; }
};

struct FJPair
{
    int    small;
    int    large;
    bool   hasLarge;
};

struct FJPairCmpByLarge
{
    bool operator()(const FJPair &a, const FJPair &b) const
    {
        return a.large < b.large;
    }
};

static std::vector<size_t> buildJacobsthal(size_t maxVal)
{
    std::vector<size_t> j;
    j.push_back(1);
    j.push_back(3);
    while (true)
    {
        size_t next = j[j.size()-1] + 2 * j[j.size()-2];
        j.push_back(next);
        if (next > maxVal * 2 + 10) break;
    }
    return j;
}

static std::vector<size_t> makeInsertOrder(size_t total)
{
    std::vector<size_t> order;
    if (total == 0) return order;

    std::vector<size_t> jseq = buildJacobsthal(total);

    size_t prev = 0;
    for (size_t gi = 0; gi < jseq.size(); gi++)
    {
        if (prev >= total) break;
        size_t curr = (jseq[gi] < total) ? jseq[gi] : total;
        for (size_t k = curr; k > prev; k--)
            order.push_back(k);
        prev = jseq[gi];
        if (jseq[gi] >= total) break;
    }
    return order;
}


static void fordJohnsonVec(std::vector<int> &data, CountingCmp cmp)
{
    const size_t n = data.size();
    if (n <= 1) return;

    std::vector<FJPair> pairs;
    std::vector<int>    mainChain;

    size_t i = 0;
    while (i + 1 < n)
    {
        int a = data[i], b = data[i + 1];
        if (cmp(b, a)) std::swap(a, b);
        FJPair p; p.small = a; p.large = b; p.hasLarge = true;
        pairs.push_back(p);
        mainChain.push_back(b);
        i += 2;
    }

    bool hasStraggler = (n % 2 == 1);
    int  straggler    = hasStraggler ? data[n - 1] : 0;

    const size_t t = pairs.size();

    fordJohnsonVec(mainChain, cmp);

   
    std::vector<FJPair> sortedPairs(pairs);
    for (size_t a = 1; a < sortedPairs.size(); a++)
    {
        FJPair key = sortedPairs[a];
        size_t b = a;
        while (b > 0 && sortedPairs[b-1].large > key.large)
        {
            sortedPairs[b] = sortedPairs[b-1];
            b--;
        }
        sortedPairs[b] = key;
    }

    if (hasStraggler)
    {
        FJPair sp; sp.small = straggler; sp.large = 0; sp.hasLarge = false;
        sortedPairs.push_back(sp);
    }

    const size_t total = sortedPairs.size();

    std::vector<size_t> largeIdx(t);
    for (size_t idx = 0; idx < t; idx++) largeIdx[idx] = idx;

    std::vector<size_t> order = makeInsertOrder(total);

    for (size_t oi = 0; oi < order.size(); oi++)
    {
        size_t k   = order[oi] - 1;
        int    val = sortedPairs[k].small;

        std::vector<int>::iterator pos;

        if (!sortedPairs[k].hasLarge)
        {
            pos = std::lower_bound(mainChain.begin(), mainChain.end(), val, cmp);
        }
        else
        {
            std::vector<int>::iterator limit =
                mainChain.begin() + (std::ptrdiff_t)largeIdx[k];
            pos = std::lower_bound(mainChain.begin(), limit, val, cmp);
        }

        size_t insertPos = (size_t)(pos - mainChain.begin());
        mainChain.insert(pos, val);

        for (size_t j = 0; j < t; j++)
            if (largeIdx[j] >= insertPos) largeIdx[j]++;
    }

    data = mainChain;
}

void PmergeMe::sortVector(std::vector<int> &v)
{
    vecComparisons = 0;
    fordJohnsonVec(v, CountingCmp(&vecComparisons));
    std::cout << "Vector comparisons: " << vecComparisons << std::endl;
}

void PmergeMe::sortDeque(std::deque<int> &d)
{
    deqComparisons = 0;
    std::vector<int> tmp(d.begin(), d.end());
    fordJohnsonVec(tmp, CountingCmp(&deqComparisons));
    d.assign(tmp.begin(), tmp.end());
    std::cout << "Deque comparisons : " << deqComparisons << std::endl;
}

static bool isNumber(const std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

static bool hasDuplicate(const std::vector<int> &v)
{
    std::vector<int> tmp = v;
    std::sort(tmp.begin(), tmp.end());

    for (size_t i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] == tmp[i - 1])
            return true;
    }
    return false;
}

void PmergeMe::run(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::vector<int> v;
    std::deque<int>  d;

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (!isNumber(arg))
        {
            std::cerr << "Error" << std::endl;
            return;
        }

        long n = std::atol(argv[i]);

        if (n < 0 || n > INT_MAX)
        {
            std::cerr << "Error" << std::endl;
            return;
        }

        v.push_back(static_cast<int>(n));
        d.push_back(static_cast<int>(n));
    }

    if (hasDuplicate(v))
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    sortVector(v);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    sortDeque(d);
    end = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : "
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << v.size()
              << " elements with std::deque  : "
              << deqTime << " us" << std::endl;
}
