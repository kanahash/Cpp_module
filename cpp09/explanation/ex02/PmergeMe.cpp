#include "PmergeMe.hpp"

/*
    コンストラクタ
    比較回数カウンタを0で初期化する
*/
PmergeMe::PmergeMe() : vecComparisons(0), deqComparisons(0) {}

/*
    デストラクタ
*/
PmergeMe::~PmergeMe(){}

/*
    コピーコンストラクタ
    他のオブジェクトの内容をコピーする
*/
PmergeMe::PmergeMe(const PmergeMe &other)
    : vec(other.vec),
      deq(other.deq),
      vecComparisons(other.vecComparisons),
      deqComparisons(other.deqComparisons) {}

/*
    代入演算子
*/
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

/*
    Jacobsthal数列を生成する関数
    Ford-Johnsonアルゴリズムで挿入順序を決めるために使う
*/
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

/*
    vector用 比較回数カウント付き比較関数
    lower_boundで使用する
*/
struct VecCompare
{
    size_t* counter;

    VecCompare(size_t* c) : counter(c) {}

    bool operator()(int a, int b)
    {
        (*counter)++;  // 比較回数をカウント
        return a < b;
    }
};

/*
    vectorをFord-Johnsonアルゴリズムでソートする
*/
void PmergeMe::sortVector(std::vector<int>& arr)
{
    // 要素が1個以下ならソート不要
    if (arr.size() <= 1)
        return;

    std::vector<VecPair> pairs;
    size_t i = 0;

    /*
        2つずつペアを作る
        small と large に分ける
    */
    for (; i + 1 < arr.size(); i += 2)
    {
        VecPair p;

        vecComparisons++; // ペア内比較

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

    // 奇数個だった場合の最後の1個
    bool hasStraggler = (i < arr.size());
    int straggler = hasStraggler ? arr[i] : 0;

    /*
        large側だけを取り出して mainChain を作る
    */
    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].large);

    // 再帰的に large 側をソート
    sortVector(mainChain);

    /*
        各largeが mainChain のどこにあるか位置を記録
    */
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

    /*
        small側を二分探索で挿入
    */
    for (size_t j = 0; j < pairs.size(); ++j)
    {
        size_t left = 0;
        size_t right = position[j];

        // 二分探索
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

        // 挿入により位置がずれるので補正
        for (size_t k = 0; k < position.size(); ++k)
        {
            if (position[k] >= left)
                position[k]++;
        }
    }

    /*
        余った1要素（奇数個の場合）を挿入
    */
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

    // 結果を元配列へ代入
    arr = mainChain;
}

/*
    deque用ソート
    基本構造はvector版と同じ
*/
void PmergeMe::sortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;

    std::deque<std::pair<int,int> > pairs;
    std::deque<int> mainChain;
    std::deque<int> pend;

    size_t i = 0;

    // ペア作成
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

    // large側をmainChainへ
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].second);

    // 再帰
    sortDeque(mainChain);

    // small側をpendへ
    for (size_t j = 0; j < pairs.size(); ++j)
        pend.push_back(pairs[j].first);

    // Jacobsthal順に挿入
    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    DeqCompare comp(&deqComparisons);

    for (size_t j = 0; j < jacob.size(); ++j)
    {
        int idx = jacob[j];
        if (idx >= (int)pend.size())
            continue;

        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx], comp);

        mainChain.insert(pos, pend[idx]);
        inserted[idx] = true;
    }

    // まだ挿入されていないものを挿入
    for (size_t j = 0; j < pend.size(); ++j)
    {
        if (inserted[j])
            continue;

        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[j], comp);

        mainChain.insert(pos, pend[j]);
    }

    // 余り挿入
    if (hasStraggler)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler, comp);

        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

/*
    プログラム実行本体
    入力チェック → ソート → 時間計測 → 出力
*/
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

        // 入力チェック
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

        // ソート前表示
        std::cout << "Before: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        // vector時間計測
        std::clock_t startVec = std::clock();
        sortVector(vec);
        std::clock_t endVec = std::clock();

        // deque時間計測
        std::clock_t startDeq = std::clock();
        sortDeque(deq);
        std::clock_t endDeq = std::clock();

        // ソート後表示
        std::cout << "After:  ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        // マイクロ秒へ変換
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
