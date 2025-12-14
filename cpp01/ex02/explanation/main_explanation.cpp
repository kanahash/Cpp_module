/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:27:39 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 23:27:44 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>   // std::string クラスを使用するために必要なヘッダーファイル
#include <iostream> // 標準入出力（std::cout, std::endl）を使用するために必要なヘッダーファイル

int main(void) // プログラムのエントリーポイント
{
    // 1. 文字列変数の宣言と初期化
    // 'std::string' 型の変数 'str' を宣言し、"HI THIS IS BRAIN" で初期化します。
    std::string str = "HI THIS IS BRAIN";

    // 2. ポインタの宣言と初期化
    // 'std::string*' 型のポインタ変数 'stringPTR' を宣言します。
    // '&str' は変数 'str' のメモリアドレスを取得する「アドレス演算子」です。
    // 'stringPTR' は 'str' のメモリアドレスを保持します。
    std::string* stringPTR = &str;

    // 3. 参照の宣言と初期化
    // 'std::string&' 型の参照変数 'stringREF' を宣言します。
    // 参照は宣言時に必ず初期化する必要があり、初期化後は別の変数を参照し直すことはできません。
    // 'stringREF' は変数 'str' の「別名」として機能します。
    std::string& stringREF = str;

    // --- メモリアドレスの出力 ---
    std::cout << "--- Memory address ---" << std::endl;
    // 変数 'str' 自体のメモリアドレスを出力します。
    std::cout << "Memory address of str: " << &str << std::endl;
    // ポインタ 'stringPTR' が「保持している」メモリアドレスを出力します。
    // これは 'str' のアドレスと同じになります。
    std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
    // 参照 'stringREF' が指す（つまり 'str' と同じ）メモリアドレスを出力します。
    // 参照も実体と同じメモリアドレスを持ちます。
    std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl; // 出力を見やすくするための空行

    // --- 値の出力 ---
    std::cout << "------- Values -------" << std::endl;
    // 変数 'str' の実際の値を出力します。
    std::cout <<"Value of str: " << str << std::endl;
    // ポインタ 'stringPTR' が「指している」メモリアドレスに格納されている値を出力します。
    // '*' は「間接参照演算子（デリファレンス演算子）」で、ポインタが指すアドレスの内容を取得します。
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    // 参照 'stringREF' の値を出力します。
    // 参照は元の変数の別名なので、参照名を直接使うと元の変数の値にアクセスできます。
    std::cout << "Value of stringREF: " << stringREF << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl; // 出力を見やすくするための空行

    return(0); // プログラムが正常終了したことをOSに伝えます。
}
