// =============================================================================
// PmergeMe.cpp  —  Ford-Johnson アルゴリズム (Merge Insertion Sort) の実装
//
// ■ このファイルで何をしているか？
//   整数の列を「できるだけ少ない比較回数で」昇順ソートします。
//   使うアルゴリズムは Ford-Johnson 法（1959年考案）で、
//   情報理論的な下限に非常に近い比較回数でソートできることが証明されています。
//
// ■ 普通のソートと何が違うの？
//   バブルソート  → 最悪 n*(n-1)/2 回の比較
//   クイックソート → 平均 n*log(n) 回（比較回数の最小化が目的ではない）
//   Ford-Johnson  → n=21 で最大 66 回（理論的最小値）
//
// ■ アルゴリズムの3ステップ（大まかなイメージ）
//   Step 1: 要素を2個ずつペアにして、各ペアの「大きい方」だけ取り出す
//   Step 2: 「大きい方」の列を再帰的にソートする
//   Step 3: 「小さい方」を、賢い順番（Jacobsthal 順序）で挿入していく
// =============================================================================

#include "PmergeMe.hpp"
#include <algorithm>   // std::lower_bound, std::swap
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>       // clock()


// =============================================================================
// コンストラクタ / デストラクタ / コピー
//
// ・vecComparisons: vector でソートした際の比較回数カウンタ
// ・deqComparisons: deque でソートした際の比較回数カウンタ
// =============================================================================
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


// =============================================================================
// struct CountingCmp  —  「何回比較したか」を数えながら比較する関数オブジェクト
//
// ■ 関数オブジェクトとは？
//   operator() を持つ構造体は、関数のように () で呼び出せます。
//   std::lower_bound などのSTL関数に「比較のやり方」として渡せます。
//
//   例:
//     size_t n = 0;
//     CountingCmp cmp(&n);
//     cmp(3, 5);   // → true（3 < 5）、同時に n が 1 増える
//     cmp(7, 2);   // → false（7 < 2 は偽）、同時に n が 2 になる
//
// ■ なぜポインタで count を持つか？
//   再帰呼び出しの中でも「同じカウンタ」を共有するためです。
//   値で持つと、再帰の各階層でカウンタがコピーされてしまい、
//   合計比較回数を正確に集計できなくなります。
// =============================================================================
struct CountingCmp
{
    size_t *count;                                    // カウンタのアドレスを持つ

    explicit CountingCmp(size_t *c) : count(c) {}    // コンストラクタ

    bool operator()(int a, int b) const
    {
        (*count)++;   // 呼ばれるたびにカウントアップ
        return a < b; // a が b より小さければ true を返す（昇順比較）
    }
};


// =============================================================================
// struct FJPair  —  ペア（大きい方 + 小さい方）を表す構造体
//
// Ford-Johnson では要素を必ず「ペア」として扱います。
//
//   small : ペアの小さい方（後で mainChain に「挿入」される側）
//   large : ペアの大きい方（先に mainChain に並ぶ側）
//           ※ small <= large が常に成り立つ
//
//   hasLarge : true  → 通常のペア
//              false → straggler（奇数個の場合に余った1個）
//
// ■ straggler とは？
//   入力が奇数個のとき、最後の1個はペアを作れません。
//   この余り1個を straggler（はぐれ者）と呼びます。
//   straggler には対応する large がないため、
//   挿入時に探索範囲の「上限」を設定できません。
// =============================================================================
struct FJPair
{
    int  small;
    int  large;
    bool hasLarge;   // false = straggler（large なし）
};


// =============================================================================
// struct FJPairCmpByLarge  —  FJPair を large の値で比較する関数オブジェクト
//
// C++98 では lambda（ラムダ式）が使えないため、
// ソートの比較ロジックをこのように構造体として書きます。
//
// 使用箇所: sortedPairs を large の昇順に並べ直すとき
// =============================================================================
struct FJPairCmpByLarge
{
    bool operator()(const FJPair &a, const FJPair &b) const
    {
        return a.large < b.large;  // large が小さい順に並べる
    }
};


// =============================================================================
// buildJacobsthal()  —  Jacobsthal 数列を生成する
//
// ■ Jacobsthal 数列とは？
//   1, 3, 5, 11, 21, 43, 85, 171, ...
//
//   漸化式: J(k) = J(k-1) + 2 * J(k-2)
//     J(1) = 1
//     J(2) = 3
//     J(3) = 3 + 2×1 = 5
//     J(4) = 5 + 2×3 = 11
//     J(5) = 11 + 2×5 = 21
//     ...
//
// ■ なぜこの数列を使うの？
//   小さい方の要素を「どの順番で挿入するか」がソートの比較回数を左右します。
//   Jacobsthal 順序で挿入すると、各挿入の「二分探索の範囲」が
//   ちょうど 2^m - 1 個になります。
//
//   2^m - 1 個の列への二分探索は m 回で完了します（例: 7個 → 3回）。
//   これが「比較回数を最小にできる」秘密です。
//
// ■ 引数 maxVal について
//   ペアの個数（t）以上の数列を生成するため、十分大きくなるまで生成します。
// =============================================================================
static std::vector<size_t> buildJacobsthal(size_t maxVal)
{
    std::vector<size_t> j;
    j.push_back(1);   // J(1) = 1
    j.push_back(3);   // J(2) = 3

    while (true)
    {
        // J(k) = 直前の値 + 2 × 2つ前の値
        size_t next = j[j.size()-1] + 2 * j[j.size()-2];
        j.push_back(next);

        if (next > maxVal * 2 + 10) break;   // 十分な大きさになったら終了
    }
    return j;
}


// =============================================================================
// makeInsertOrder()  —  挿入する順番のリストを作る
//
// ■ 何を返すか？
//   1〜total の番号が「Jacobsthal 順序」に並んだリストを返します。
//   ここでの番号は「何番目のペアの small を挿入するか」を表します（1始まり）。
//
// ■ 具体例（total = 10 のとき）
//   Jacobsthal 数列: 1, 3, 5, 11, ...
//
//   グループ1: J(0)=0 ～ J(1)=1  → 降順で [1]
//   グループ2: J(1)=1 ～ J(2)=3  → 降順で [3, 2]
//   グループ3: J(2)=3 ～ J(3)=5  → 降順で [5, 4]
//   グループ4: J(3)=5 ～ J(4)=11 → 10で打ち切り → 降順で [10, 9, 8, 7, 6]
//
//   結果: [1, 3, 2, 5, 4, 10, 9, 8, 7, 6]
//
// ■ なぜ「降順」なのか？
//   グループの中で大きい番号から先に挿入することで、
//   後続の挿入の探索範囲が広がりすぎるのを防ぎます。
//   この順序が 2^m - 1 の探索範囲を保証する鍵です。
// =============================================================================
static std::vector<size_t> makeInsertOrder(size_t total)
{
    std::vector<size_t> order;
    if (total == 0) return order;

    std::vector<size_t> jseq = buildJacobsthal(total);

    size_t prev = 0;   // 1つ前のグループの末尾（初期値は 0）

    for (size_t gi = 0; gi < jseq.size(); gi++)
    {
        if (prev >= total) break;

        // このグループの末尾（total を超えないようにクリップ）
        size_t curr = (jseq[gi] < total) ? jseq[gi] : total;

        // curr から prev+1 まで降順で追加
        for (size_t k = curr; k > prev; k--)
            order.push_back(k);   // 1-indexed

        prev = jseq[gi];
        if (jseq[gi] >= total) break;
    }
    return order;
}


// =============================================================================
// fordJohnsonVec()  —  Ford-Johnson ソートの本体
//
// 参考文献: TAOCP (Knuth) Volume 3, Algorithm 5.3.1M
//
// ■ 全体の流れ（n=8 の例: [8, 3, 5, 7, 4, 2, 6, 1]）
//
//   【Step M1: ペア作成】
//     隣接する2要素を比べてペアを作る
//     (8,3)→(small=3, large=8),  (5,7)→(small=5, large=7)
//     (4,2)→(small=2, large=4),  (6,1)→(small=1, large=6)
//     mainChain = [8, 7, 4, 6]  ← large だけ集めた列
//
//   【Step M2: 再帰ソート】
//     mainChain = [8, 7, 4, 6] を再帰的に Ford-Johnson ソート
//     → mainChain = [4, 6, 7, 8]  ← ソート済み
//
//   【pendant の並べ直し】
//     再帰後、mainChain は昇順になっている
//     各 large がどの位置にいるか確認し、対応する small（pendant）を並べ直す
//     sortedPairs = [(small=2,large=4), (small=1,large=6),
//                    (small=5,large=7), (small=3,large=8)]
//     → q_1=2, q_2=1, q_3=5, q_4=3
//
//   【Step M3: Jacobsthal 順序で挿入】
//     挿入順: [1, 3, 2, 4] → q_1, q_3, q_2, q_4
//     q_1=2 を挿入: [2, 4, 6, 7, 8]      （探索範囲 0個 → 0回比較）
//     q_3=5 を挿入: [2, 4, 5, 6, 7, 8]   （探索範囲 3個 → 2回比較）
//     q_2=1 を挿入: [1, 2, 4, 5, 6, 7, 8]（探索範囲 3個 → 2回比較）
//     q_4=3 を挿入: [1, 2, 3, 4, 5, 6, 7, 8]（探索範囲 7個 → 3回比較）
// =============================================================================
static void fordJohnsonVec(std::vector<int> &data, CountingCmp cmp)
{
    const size_t n = data.size();
    if (n <= 1) return;   // 要素が1個以下ならすでにソート済み、何もしない


    // -------------------------------------------------------------------------
    // Step M1: ペアを作る
    //
    // 2個ずつ取り出して比較し、small（小さい方）と large（大きい方）に分ける。
    // large だけを mainChain に集める。
    //
    // 注意: 奇数個の場合、最後の1個はペアを作れない（straggler）。
    // -------------------------------------------------------------------------
    std::vector<FJPair> pairs;      // 作ったペアを格納
    std::vector<int>    mainChain;  // large だけを集めた列

    size_t i = 0;
    while (i + 1 < n)
    {
        int a = data[i], b = data[i + 1];

        // b < a なら swap して a <= b にする（1回比較）
        if (cmp(b, a)) std::swap(a, b);

        FJPair p;
        p.small    = a;     // 小さい方
        p.large    = b;     // 大きい方
        p.hasLarge = true;  // 通常ペア
        pairs.push_back(p);
        mainChain.push_back(b);  // large だけ mainChain へ

        i += 2;  // 2個ずつ進む
    }

    // 奇数個なら最後の1個が straggler
    bool hasStraggler = (n % 2 == 1);
    int  straggler    = hasStraggler ? data[n - 1] : 0;

    const size_t t = pairs.size();   // ペアの個数（= pendant の個数）


    // -------------------------------------------------------------------------
    // Step M2: mainChain を再帰的にソート
    //
    // mainChain（large だけの列）を Ford-Johnson で再帰的にソートする。
    // 再帰が終わると mainChain は昇順になる: c_1 <= c_2 <= ... <= c_t
    //
    // 再帰の終了条件: n <= 1 のとき（上の if 文）
    // -------------------------------------------------------------------------
    fordJohnsonVec(mainChain, cmp);


    // -------------------------------------------------------------------------
    // pendant の並べ直し ← Knuth の重要ポイント！
    //
    // ■ なぜ並べ直しが必要か？
    //   pairs は「入力の順番」で並んでいる。
    //   しかし再帰後の mainChain は「値の昇順」に並んでいる。
    //
    //   Ford-Johnson の理論では:
    //     q_1（1番目の pendant）は mainChain の最小値 c_1 とペアになっている。
    //     q_1 <= c_1 は確定しているので、q_1 を挿入するとき
    //     「c_1 より前」を探すだけでよい → 探索範囲 0個 → 比較 0回！
    //
    //   この「q_1 の比較回数 0」が Ford-Johnson の効率の源泉。
    //   もし pairs[0] をそのまま q_1 として使うと、
    //   pairs[0].large が mainChain の最小値である保証がなくなり、
    //   探索範囲が 0 にならない → 比較回数が増える。
    //
    // ■ 並べ直しの方法
    //   pairs を large の昇順に安定ソートする。
    //   すると sortedPairs[i].large == mainChain[i] が成り立つ。
    //   sortedPairs[0].small が q_1（最小 large のペアの small）になる。
    //
    // ■ 安定ソートを使う理由
    //   同じ large 値が複数あるとき（重複）、元の順序を保つため。
    //   C++98 では std::stable_sort に lambda を渡せないので、
    //   insertion sort（安定ソートの一種）を自前で実装している。
    // -------------------------------------------------------------------------
    std::vector<FJPair> sortedPairs(pairs);  // pairs のコピー

    // large の昇順で安定ソート（insertion sort で実装）
    for (size_t a = 1; a < sortedPairs.size(); a++)
    {
        FJPair key = sortedPairs[a];
        size_t b = a;
        // key.large より大きい要素を右にずらす
        while (b > 0 && sortedPairs[b - 1].large > key.large)
        {
            sortedPairs[b] = sortedPairs[b - 1];
            b--;
        }
        sortedPairs[b] = key;
    }
    // ここで sortedPairs[i].large == mainChain[i] が保証される


    // -------------------------------------------------------------------------
    // straggler を sortedPairs の末尾に追加
    //
    // straggler を「ペアの数 t+1 番目の pendant」として扱う。
    // こうすることで、makeInsertOrder に total = t+1 を渡せば
    // straggler も Jacobsthal 順序の中に組み込まれる。
    //
    // ■ なぜ最後に別処理せず Jacobsthal 順序に入れるのか？
    //   straggler を最後に処理すると探索範囲が広くなりすぎる。
    //
    //   例（n=5, t=2）:
    //     ❌ straggler を最後に処理: q_1(0回) + q_2(2回) + straggler(3回) = 5回
    //     ✅ Jacobsthal に組み込む:  q_1(0回) + straggler(2回) + q_2(2回) = 4回
    //
    //   1回少なくなる。これが理論値を達成するために必要な工夫。
    // -------------------------------------------------------------------------
    if (hasStraggler)
    {
        FJPair sp;
        sp.small    = straggler;
        sp.large    = 0;      // 使わないが初期化しておく
        sp.hasLarge = false;  // straggler フラグ
        sortedPairs.push_back(sp);
    }

    const size_t total = sortedPairs.size();  // t（奇数なら t+1）


    // -------------------------------------------------------------------------
    // largeIdx の初期化
    //
    // largeIdx[i] = 「sortedPairs[i].large が mainChain の何番目にいるか」
    //
    // 初期値は i そのもの（並べ直し後は sortedPairs[i].large == mainChain[i]）。
    //
    // pendant を mainChain に挿入するたびに、挿入した位置より後ろにいる
    // large は1つずつ右にずれる → largeIdx を +1 更新する。
    //
    // ■ なぜ largeIdx が必要か？
    //   pendant q_i を挿入するとき、「q_i の large（c_i）より前」だけを
    //   探索すれば十分（q_i <= c_i が既知のため c_i との比較不要）。
    //   largeIdx[i] が「c_i の現在位置」を教えてくれるので、
    //   探索範囲を [begin, largeIdx[i]) に絞ることができる。
    // -------------------------------------------------------------------------
    std::vector<size_t> largeIdx(t);
    for (size_t idx = 0; idx < t; idx++) largeIdx[idx] = idx;


    // -------------------------------------------------------------------------
    // Step M3: Jacobsthal 順序で pendant を挿入
    //
    // makeInsertOrder(total) が返す順序で、各 pendant を mainChain に挿入する。
    //
    // ■ 通常 pendant（hasLarge = true）の挿入:
    //   探索範囲 = [mainChain.begin(), mainChain.begin() + largeIdx[k])
    //   ※ largeIdx[k] は exclusive（c_k 自体を含まない）
    //   ※ q_k <= c_k は既知なので、c_k との比較は不要
    //
    // ■ straggler（hasLarge = false）の挿入:
    //   対応する large がないため、mainChain 全体を探索する。
    //
    // std::lower_bound(begin, end, val, cmp):
    //   [begin, end) の範囲で val 以上の最初の位置を返す（二分探索）。
    //   例: [1, 4, 6, 7, 8] に 5 を挿入 → 位置2（6 の前）
    // -------------------------------------------------------------------------
    std::vector<size_t> order = makeInsertOrder(total);

    for (size_t oi = 0; oi < order.size(); oi++)
    {
        size_t k   = order[oi] - 1;         // 1-indexed → 0-indexed に変換
        int    val = sortedPairs[k].small;   // 挿入する値

        std::vector<int>::iterator pos;      // 挿入する位置（イテレータ）

        if (!sortedPairs[k].hasLarge)
        {
            // straggler: mainChain 全体を二分探索
            pos = std::lower_bound(mainChain.begin(), mainChain.end(), val, cmp);
        }
        else
        {
            // 通常 pendant: [begin, largeIdx[k]) の範囲だけ二分探索
            // largeIdx[k] が探索の上限（exclusive）
            std::vector<int>::iterator limit =
                mainChain.begin() + (std::ptrdiff_t)largeIdx[k];
            pos = std::lower_bound(mainChain.begin(), limit, val, cmp);
        }

        // 挿入位置のインデックスを保存してから mainChain に挿入
        size_t insertPos = (size_t)(pos - mainChain.begin());
        mainChain.insert(pos, val);

        // 挿入によって右にずれた large の位置を更新
        // straggler は largeIdx を持たないので t 個分だけループ
        for (size_t j = 0; j < t; j++)
            if (largeIdx[j] >= insertPos) largeIdx[j]++;
    }

    // ソート済み mainChain で data を上書き
    data = mainChain;
}


// =============================================================================
// sortVector()  —  std::vector 用のエントリーポイント
//
// vecComparisons をリセットしてから fordJohnsonVec を呼び出し、
// 終わったら比較回数を表示する。
// =============================================================================
void PmergeMe::sortVector(std::vector<int> &v)
{
    vecComparisons = 0;
    fordJohnsonVec(v, CountingCmp(&vecComparisons));
    std::cout << "Vector comparisons: " << vecComparisons << std::endl;
}


// =============================================================================
// sortDeque()  —  std::deque 用のエントリーポイント
//
// ■ なぜ deque を直接ソートしないのか？
//   Ford-Johnson の実装では std::lower_bound や insert を頻繁に使う。
//   deque はランダムアクセスが遅く、中間への insert も vector より遅い。
//   そのため一度 vector に変換し、ソート後に deque に書き戻す。
// =============================================================================
void PmergeMe::sortDeque(std::deque<int> &d)
{
    deqComparisons = 0;
    std::vector<int> tmp(d.begin(), d.end());   // deque → vector にコピー
    fordJohnsonVec(tmp, CountingCmp(&deqComparisons));
    d.assign(tmp.begin(), tmp.end());            // ソート結果を deque に書き戻す
    std::cout << "Deque comparisons : " << deqComparisons << std::endl;
}

// =============================================================================
// 入力検証（Error Handling）
//
// Ford-Johnson アルゴリズムとは直接関係ないが、
// プログラムとして安全に動作させるために入力チェックを行う。
//
// 42 C++ Module 09 の evaluator が必ず確認する部分である。
//
// チェックしている内容は次の4つ:
//
//   1. 引数が存在するか
//   2. 引数がすべて「数字のみ」か
//   3. int の範囲に収まっているか
//   4. 重複した数値がないか
//
// もしどれか1つでも違反していれば
//
//     Error
//
// を表示して処理を終了する。
// =============================================================================



// =============================================================================
// isNumber()  —  文字列が「数字のみ」で構成されているかチェック
//
// ■ 何をする関数？
//   引数で渡された文字列が
//
//       "12345"
//
// のように「0〜9 の数字だけ」で構成されているか確認する。
//
// ■ なぜ必要？
//   std::atol() は
//
//       "12abc"
//
// のような文字列でも
//
//       → 12
//
// として解釈してしまう。
// これは入力として不正なので、事前にチェックする必要がある。
//
// ■ アルゴリズム
//
//   1文字ずつ調べて
//
//       std::isdigit()
//
// で数字かどうか判定する。
//
// ■ 戻り値
//
//   true  → すべて数字
//   false → 数字以外を含む
// =============================================================================
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



// =============================================================================
// hasDuplicate()  —  重複した数値が存在するかチェック
//
// ■ 何をする関数？
//   vector の中に同じ数値が2回以上出現するか確認する。
//
// ■ なぜ必要？
//   PmergeMe の subject では
//
//       positive integer sequence
//
// と書かれているため、多くの evaluator は
//
//       重複 = Error
//
// と解釈する。
//
// ■ アルゴリズム
//
//   1. vector をコピーする
//   2. sort() で昇順に並べる
//   3. 隣り合う要素が同じなら重複
//
// ■ 計算量
//
//   O(n log n)
//
// ただし入力サイズは最大3000程度なので問題ない。
// =============================================================================
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

// =============================================================================
// run()  —  プログラムのメイン処理
//
// コマンドライン引数を読み取り、vector と deque の両方でソートして
// ソート前後の数列・比較回数・処理時間を表示する。
//
// ■ 追加された入力検証
//
//   (1) 引数が存在するか
//   (2) 文字列が数字のみか
//   (3) int の範囲内か
//   (4) 重複がないか
//
// どれか1つでも違反した場合:
//
//     Error
//
// を表示して終了する。
//
// ■ 処理時間の単位
//   clock() は CPU クロック数を返す。
//   CLOCKS_PER_SEC で割ると秒になるので、
//   さらに 1e6 を掛けてマイクロ秒に変換する。
// =============================================================================
void PmergeMe::run(int argc, char **argv)
{
    std::vector<int> v;
    std::deque<int>  d;

    // 引数を整数に変換してコンテナに格納
    for (int i = 1; i < argc; i++)
    {
        long n = std::atol(argv[i]);
        if (n < 0)
        {
            std::cerr << "Error: negative number." << std::endl;
            return;
        }
        v.push_back(static_cast<int>(n));
        d.push_back(static_cast<int>(n));
    }

    // ソート前を表示
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // vector でソート & 時間計測
    clock_t start = clock();
    sortVector(v);
    clock_t end   = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // deque でソート & 時間計測
    start = clock();
    sortDeque(d);
    end   = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // ソート後を表示
    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // 処理時間を表示（マイクロ秒）
    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << v.size()
              << " elements with std::deque  : " << deqTime << " us" << std::endl;
}
