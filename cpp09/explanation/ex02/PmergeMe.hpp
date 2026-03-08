/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:52:50 by kanahash          #+#    #+#             */
/*   Updated: 2026/03/04 19:45:58 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
/*
    ヘッダガード。
    同一ヘッダが複数回インクルードされた場合の多重定義を防ぐ。

    C++では #pragma once を使うことも多いが、
    POSIX/移植性重視のプロジェクトではこの形式がよく使われる。
*/

#include <iostream>   // 標準入出力 (std::cout など)
#include <string>     // std::string
#include <vector>     // 動的配列コンテナ (連続メモリ)
#include <deque>      // 双方向キュー (非連続メモリブロック)
#include <algorithm>  // 汎用アルゴリズム (std::sort, lower_bound など)
#include <ctime>      // 計測用 (clock)
#include <iomanip>    // 出力フォーマット
#include <sstream>    // 文字列→数値変換
#include <climits>    // INT_MAX 等

/*
    PmergeMe クラス

    42課題「Ford-Johnson merge-insert sort」の実装クラス。

    目的：
        - vector と deque の両方で同じアルゴリズムを実行
        - 実行時間や比較回数を測定
        - STLコンテナによる性能差を検証

    理論背景：
        Ford-Johnson algorithm (merge-insert sort)
        は比較回数を最小化するソートアルゴリズムとして知られる。
*/
class PmergeMe
{
	private:

		/*
		    ソート対象のデータ

		    vec : std::vector
		        - 連続メモリ
		        - キャッシュ効率が高い
		        - ランダムアクセス O(1)

		    deq : std::deque
		        - 複数メモリブロック構造
		        - push_front / push_back が高速
		        - vectorよりキャッシュ局所性が弱い

		    この二つを比較することで
		    「アルゴリズム vs データ構造」の性能差を測定できる。
		*/
		std::vector<int> vec;
		std::deque<int> deq;

		/*
		    比較回数カウンタ

		    Ford-Johnsonアルゴリズムは
		    「比較回数を理論的最小に近づける」ことが特徴。

		    そのため比較回数を計測することで
		    実装の正しさや理論値との比較が可能になる。
		*/
		size_t vecComparisons;
		size_t deqComparisons;

		/*
		    ペア構造体

		    Ford-Johnsonアルゴリズムでは
		    配列を2要素のペアに分割して処理する。

		    (small, large) のペアを作ることで

		        [a,b,c,d,e,f]
		          ↓
		        (a,b)(c,d)(e,f)

		    のように管理する。
		*/
		struct VecPair
		{
			int small;   // ペアの小さい値
			int large;   // ペアの大きい値

			/*
			    pos

			    大きい値が「メインチェーン」に挿入された位置。
			    Ford-Johnsonでは小さい値を挿入する際に
			    探索範囲を制限するために使われる。
			*/
			size_t pos;
		};

		/*
		    vector用ソート関数

		    Ford-Johnsonアルゴリズムを
		    vector上で実装する内部関数。

		    vectorは連続メモリなので
		        - binary search
		        - lower_bound
		    との相性が良い。
		*/
	void sortVector(std::vector<int>& arr);

		/*
		    deque用ソート関数

		    vector版と同一アルゴリズムを
		    dequeに対して実行。

		    dequeは内部構造が分割配列のため
		    キャッシュミスが増えやすく
		    vectorより遅くなる可能性が高い。

		    この差を計測することが課題の主目的。
		*/
	void sortDeque(std::deque<int>& arr);

	public:

		/*
		    デフォルトコンストラクタ
		*/
		PmergeMe();

		/*
		    デストラクタ
		    動的メモリを直接扱っていないため
		    実質的には空になることが多い。
		*/
		~PmergeMe();

		/*
		    コピーコンストラクタ
		    Rule of Three の一部。

		    クラスがリソースを持つ場合、
		    コピー動作を明示する必要がある。
		*/
		PmergeMe(const PmergeMe &other);

		/*
		    代入演算子オーバーロード
		    これも Rule of Three の一部。
		*/
		PmergeMe& operator=(const PmergeMe &other);
		
		/*
		    プログラムのエントリ処理

		    引数:
		        ac : 引数数
		        av : 引数配列

		    処理内容:
		        1. 引数を整数に変換
		        2. vector / deque に格納
		        3. ソート実行
		        4. 実行時間計測
		        5. 結果出力

		    つまり main() のロジックを
		    クラス内部にカプセル化している。
		*/
		void run(int ac, char **av);
};

#endif
/*
    ヘッダガード終端
*/
