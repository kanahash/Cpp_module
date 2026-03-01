/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* PmergeMe.cpp                                       :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/14 20:52:50 by kanahash          #+#    #+#             */
/* Updated: 2026/03/01 20:25:38 by kanahash         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// --- コンストラクタ・デストラクタ ---
PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return (*this);
}

/**
 * @brief ヤコブスタール数 (Jacobsthal numbers) を生成する
 * * Ford-Johnson法において、挿入ソートの比較回数を最小限にするための
 * 特殊な数列（1, 3, 5, 11, 21...）を作成します。
 */
std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> j;
    if (n <= 1) return j;

    int a = 1; // 1番目
    int b = 3; // 2番目
    j.push_back(a);

    while (b < n)
    {
        j.push_back(b);
        int next = b + 2 * a; // 前々回の2倍 + 前回 = 次の数
        a = b;
        b = next;
    }
    return j;
}

/**
 * @brief Ford-Johnsonアルゴリズム (std::vector版)
 * * 1. ペアを作り、大きい方を mainChain、小さい方を pend に分ける
 * 2. mainChain を再帰的にソートする
 * 3. pend の要素をヤコブスタール数の順序で mainChain に二分探索挿入する
 */
void PmergeMe::sortVector(std::vector<int>& arr)
{
    // 再帰の終了条件：要素が1つ以下ならソートの必要なし
    if (arr.size() <= 1)
        return;

    // STEP 1: 要素をペアにして比較
    std::vector<std::pair<int, int> > pairs;
    size_t i = 0;
    for (; i + 1 < arr.size(); i += 2)
    {
        // (小さい方, 大きい方) の順でペアを作る
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // 要素が奇数個の場合、最後に残った1つを「straggler（はぐれ者）」として保存
    bool hasStraggler = (i < arr.size());
    int straggler = hasStraggler ? arr[i] : 0;

    // STEP 2: 各ペアの「大きい方」を集めて mainChain を作る
    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].second);

    // mainChain 自体を再帰的にソート（これが完了するまで次に進まない）
    sortVector(mainChain);

    // STEP 3: 各ペアの「小さい方」を pend (挿入待ちリスト) に入れる
    std::vector<int> pend;
    for (size_t j = 0; j < pairs.size(); ++j)
        pend.push_back(pairs[j].first);

    // STEP 4: 効率的な挿入順序（ヤコブスタール数）を使って挿入
    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    // ヤコブスタール数のインデックスに基づき挿入
    for (size_t j = 0; j < jacob.size(); ++j)
    {
        int idx = jacob[j];
        if (idx >= (int)pend.size()) continue;

        // lower_bound = 二分探索で「自分以上の値が最初に現れる位置」を探す
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx]);

        mainChain.insert(pos, pend[idx]);
        inserted[idx] = true;
    }

    // まだ挿入されていない残りの要素（ヤコブスタール数以外のインデックス）を挿入
    for (size_t j = 0; j < pend.size(); ++j)
    {
        if (inserted[j]) continue;
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);
        mainChain.insert(pos, pend[j]);
    }

    // STEP 5: 最後に straggler（奇数個目の余り）があれば挿入
    if (hasStraggler)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    // ソートが完了した mainChain を元の参照に戻す
    arr = mainChain;
}

/**
 * @brief Ford-Johnsonアルゴリズム (std::deque版)
 * * ロジックは vector版と全く同じですが、使用するコンテナが std::deque になります。
 * deque は「先頭や末尾への挿入」に強いという特徴があります。
 */
void PmergeMe::sortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    size_t i = 0;
    for (; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    bool hasStraggler = (i < arr.size());
    int straggler = hasStraggler ? arr[i] : 0;

    std::deque<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].second);

    sortDeque(mainChain);

    std::deque<int> pend;
    for (size_t j = 0; j < pairs.size(); ++j)
        pend.push_back(pairs[j].first);

    std::vector<int> jacob = generateJacobsthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    for (size_t j = 0; j < jacob.size(); ++j)
    {
        int idx = jacob[j];
        if (idx >= (int)pend.size()) continue;

        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx]);
        mainChain.insert(pos, pend[idx]);
        inserted[idx] = true;
    }

    for (size_t j = 0; j < pend.size(); ++j)
    {
        if (inserted[j]) continue;
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);
        mainChain.insert(pos, pend[j]);
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

/**
 * @brief 実行管理関数
 * * 引数のパース、エラーチェック、時間計測、結果の出力を担当します。
 */
void PmergeMe::run(int ac, char **av)
{
    if (ac < 2) return;

    try
    {
        vec.clear();
        deq.clear();

        // 1. 引数の読み込みとエラーチェック
        for (int i = 1; i < ac; ++i)
        {
            std::string arg = av[i];
            // 数字以外が入っていないかチェック
            if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
                throw std::runtime_error("Error");

            std::stringstream ss(arg);
            long val;
            // 範囲チェック (負の数やINT_MAX超え)
            if (!(ss >> val) || val < 0 || val > INT_MAX)
                throw std::runtime_error("Error");

            vec.push_back(static_cast<int>(val));
            deq.push_back(static_cast<int>(val));
        }

        // 2. ソート前の表示
        std::cout << "Before: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        // 3. vector版の計測
        std::clock_t startVec = std::clock();
        sortVector(vec);
        std::clock_t endVec = std::clock();

        // 4. deque版の計測
        std::clock_t startDeq = std::clock();
        sortDeque(deq);
        std::clock_t endDeq = std::clock();

        // 5. ソート後の表示
        std::cout << "After:  ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;

        // 6. 処理時間の算出 (マイクロ秒)
        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
        double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

        std::cout << "Time to process a range of " << vec.size() 
                  << " elements with std::vector : " << std::fixed 
                  << std::setprecision(5) << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of " << deq.size() 
                  << " elements with std::deque  : " << std::fixed 
                  << std::setprecision(5) << timeDeq << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
