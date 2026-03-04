/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:52:50 by kanahash          #+#    #+#             */
/*   Updated: 2026/03/04 19:52:29 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    ヘッダガード
    このファイルが複数回 include されるのを防ぐ
*/
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*
    使用する標準ライブラリ一覧
*/

#include <iostream>     // cout, cerr
#include <string>       // std::string
#include <vector>       // std::vector
#include <deque>        // std::deque
#include <algorithm>    // lower_bound, find など
#include <ctime>        // clock() 時間計測
#include <iomanip>      // setprecision
#include <sstream>      // stringstream
#include <climits>      // INT_MAX

/*
    PmergeMe クラス
    Ford-Johnsonアルゴリズムを使って
    vector と deque を比較するクラス
*/
class PmergeMe
{
	private:

		/*
		    ソート対象データ
		    同じデータを vector と deque に保持する
		*/
		std::vector<int> vec;
		std::deque<int> deq;

		/*
		    比較回数カウンタ
		    アルゴリズムの効率検証用
		*/
		size_t vecComparisons;
		size_t deqComparisons;

		/*
		    vector専用ペア構造体
		    2つの数を small / large に分けて保持する
		*/
		struct VecPair
		{
			int small;  // 小さい方
			int large;  // 大きい方
		};

		/*
		    vector版ソート関数（再帰）
		*/
		void sortVector(std::vector<int>& arr);

		/*
		    deque版ソート関数（再帰）
		*/
		void sortDeque(std::deque<int>& arr);

	public:

		/*
		    デフォルトコンストラクタ
		*/
		PmergeMe();

		/*
		    デストラクタ
		*/
		~PmergeMe();

		/*
		    コピーコンストラクタ
		*/
		PmergeMe(const PmergeMe &other);

		/*
		    代入演算子オーバーロード
		*/
		PmergeMe& operator=(const PmergeMe &other);
		
		/*
		    プログラム実行用関数

		    1. 引数チェック
		    2. データ格納
		    3. ソート
		    4. 時間計測
		    5. 結果出力
		*/
		void run(int ac, char **av);
};

/*
    ヘッダガード終了
*/
#endif
