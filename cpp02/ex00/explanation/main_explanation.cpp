/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:05:37 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 17:05:53 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // 標準入出力（std::cout, std::endl）を使用するためにインクルードします。
#include "Fixed.hpp" // 作成したFixedクラスの定義を含むヘッダーファイルをインクルードします。
                     // これにより、Fixedクラスのオブジェクトを作成し、そのメンバ関数を呼び出すことができます。

int main(void) // C++プログラムのエントリポイント（開始点）です。
{
    // Fixedオブジェクトの作成と、それに伴うコンストラクタの呼び出し、およびコピー代入演算子のテストを行います。

    Fixed a; // Fixedクラスのオブジェクト 'a' を作成します。
             [cite_start]// この行により、Fixedクラスの「デフォルトコンストラクタ」が呼び出され、Fixedオブジェクト 'a' が初期化されます [cite: 102]。
             [cite_start]// 演習のサンプル出力では "Default constructor called" と表示されることが期待されます [cite: 124]。

    Fixed b(a); // Fixedクラスのオブジェクト 'b' を作成し、オブジェクト 'a' の内容で初期化します。
                [cite_start]// この行により、Fixedクラスの「コピーコンストラクタ」が呼び出され、'a' の内容が 'b' にコピーされます [cite: 103]。
                [cite_start]// 演習のサンプル出力では "Copy constructor called" と表示されることが期待されます [cite: 125]。

    Fixed c; // Fixedクラスのオブジェクト 'c' を作成します。
             [cite_start]// この行により、Fixedクラスの「デフォルトコンストラクタ」が再び呼び出され、'c' が初期化されます [cite: 102]。
             [cite_start]// 演習のサンプル出力では "Default constructor called" と表示されることが期待されます [cite: 127]。

    c = b; // 既存のFixedオブジェクト 'c' に、既存のFixedオブジェクト 'b' の値を代入します。
           [cite_start]// この行により、Fixedクラスの「コピー代入演算子オーバーロード」が呼び出され、'b' の内容が 'c' に代入されます [cite: 104]。
           [cite_start]// 演習のサンプル出力では "Copy assignment operator called" と表示されることが期待されます [cite: 126, 128]。
           [cite_start]// (注: コメントにもあるように、実装によってはこの行の出力が異なる場合があります [cite: 126])。

    std::cout << a.getRawBits() << std::endl; [cite_start]// オブジェクト 'a' の生の値（raw value）を取得し、標準出力に表示します [cite: 106, 107]。
                                              [cite_start]// Fixed::getRawBits() 関数が呼び出されると、"getRawBits member function called" が出力され [cite: 129, 130, 132, 133, 134, 135]、
                                              [cite_start]// その後 'a' の内部の値（初期化により0）が表示されます [cite: 131]。

    std::cout << b.getRawBits() << std::endl; [cite_start]// オブジェクト 'b' の生の値を取得し、標準出力に表示します [cite: 106, 107]。
                                              [cite_start]// 同様に "getRawBits member function called" が出力され [cite: 129, 130, 132, 133, 134, 135]、
                                              [cite_start]// その後 'b' の内部の値（'a' からコピーされた0）が表示されます [cite: 133]。

    std::cout << c.getRawBits() << std::endl; [cite_start]// オブジェクト 'c' の生の値を取得し、標準出力に表示します [cite: 106, 107]。
                                              [cite_start]// 同様に "getRawBits member function called" が出力され [cite: 129, 130, 132, 133, 134, 135]、
                                              [cite_start]// その後 'c' の内部の値（'b' から代入された0）が表示されます [cite: 135]。

    return(0); // プログラムが正常終了したことをOSに伝えます。
               [cite_start]// main関数が終了すると、作成された Fixed オブジェクト 'a', 'b', 'c' のデストラクタが、作成された逆の順序で呼び出されます [cite: 136, 137, 138]。
               [cite_start]// 演習のサンプル出力では "Destructor called" が複数回表示されます [cite: 136, 137, 138]。
}
