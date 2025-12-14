/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_explanation.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:05:29 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 17:05:34 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP // ヘッダーガード: FIXED_HPPがまだ定義されていなければ、このファイルの内容をコンパイルします。
#define FIXED_HPP // FIXED_HPPを定義し、二重インクルードを防ぎます。

#include <string>   // 今回のFixedクラスでは直接使用していませんが、一般的なC++クラスで文字列操作が必要な場合に含めます。
#include <iostream> // std::cout, std::endl などの標準入出力機能を使用するために含めます。

// Fixedクラスの定義開始
// このクラスは、固定小数点数を表現することを目的としています。
class Fixed
{
    private: // プライベートメンバ: クラスの外部から直接アクセスできません。
             // これらはクラスの内部状態を管理するために使用されます。

        int value; [cite_start]// [cite: 99] 固定小数点数値を格納する整数型のメンバ変数です。
                   // 演習00の要件で「An integer to store the fixed-point number value.」と指定されています。

        static const int fractionalBits = 8; [cite_start]// [cite: 100] 小数部のビット数を格納する静的定数整数です。
                                             // 演習00の要件で「A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.」と指定されています。
                                             // 'static' はクラスの全インスタンスで共有されることを意味し、
                                             // 'const' は値が変更されないことを意味します。
                                             // C++98では、このように宣言時に初期化が可能です。

    public: // パブリックメンバ: クラスの外部からアクセス可能です。
            // これらの関数を通して、クラスの機能を利用します。

        Fixed(); [cite_start]// [cite: 102] デフォルトコンストラクタです。引数なしでオブジェクトが作成されるときに呼び出されます (例: Fixed a;)。
                 // 演習00の要件で「A default constructor that initializes the fixed-point number value to 0.」と指定されています。

        ~Fixed(); [cite_start]// [cite: 105] デストラクタです。オブジェクトが破棄されるときに呼び出されます。
                  // メモリ解放など、クリーンアップ処理を行います。
                  // 演習00の要件で「A destructor.」と指定されています。

        Fixed(const Fixed& copy); [cite_start]// [cite: 103] コピーコンストラクタです。既存のFixedオブジェクトから新しいオブジェクトが作成されるときに呼び出されます (例: Fixed b(a);)。
                                  // 演習00の要件で「A copy constructor.」と指定されています。
                                  // 'const Fixed&' は、引数が定数参照であり、元のオブジェクトが変更されないことを保証します。

        Fixed &operator=(const Fixed &src); [cite_start]// [cite: 104] コピー代入演算子のオーバーロードです。
                                            // 既存のFixedオブジェクトに別のFixedオブジェクトの値が代入されるときに呼び出されます (例: c = b;)。
                                            // 演習00の要件で「A copy assignment operator overload.」と指定されています。
                                            // 戻り値の型 'Fixed&' は、連鎖的な代入 (obj1 = obj2 = obj3;) を可能にします。
                                            // 'const Fixed&' は、代入元オブジェクトが変更されないことを保証します。
        
        int getRawBits(void) const; [cite_start]// [cite: 106, 107] 固定小数点値の生の値（raw value）を返すメンバ関数です。
                                    // 演習00の要件で「A member function int getRawBits (void) const; that returns the raw value of the fixed-point value.」と指定されています。
                                    // 'const' は、この関数がオブジェクトの内部状態（この場合は 'value'）を変更しないことを示します。

        void setRawBits(int const raw); [cite_start]// [cite: 108] 固定小数点数の生の値（raw value）を設定するメンバ関数です。
                                        // 演習00の要件で「A member function void setRawBits(int const raw ); that sets the raw value of the fixed-point number.」と指定されています。
                                        // 'int const raw' は、引数 'raw' が関数内で変更されないことを示します。
}; // クラス定義の終わりにはセミコロンが必要です。

#endif // ヘッダーガードの終わり
