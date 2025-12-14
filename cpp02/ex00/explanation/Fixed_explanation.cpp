/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_explanation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:04:53 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 17:04:56 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp
// Fixedクラスの実装ファイルです。
// ヘッダーファイルで宣言されたメンバ関数をここで定義します。

#include "Fixed.hpp" // Fixedクラスの宣言を含むヘッダーファイルをインクルードします。
#include <iostream>  // 標準入出力（std::cout, std::endl）を使用するためにインクルードします。

// 演習00の要件:
// ・プライベートメンバ:
//   - 固定小数点数値を格納する整数 (例: _value)。
//   - 小数部のビット数を格納する静的定数整数。その値は常に整数リテラル8です (例: _fractionalBits)。

// 静的メンバ変数の定義と初期化
// C++98では、static const int型のメンバ変数がクラス定義内で初期化されている場合、
// 通常はここで再度の初期化は不要ですが、環境によっては必要になる場合があります。
// この課題のコンパイルエラー（"static data member 'fractionalBits' already has an initializer"）から判断すると、
// Fixed.hpp内で `static const int _fractionalBits = 8;` と初期化されているため、
// ここでの定義は不要です。もしエラーが出る場合はこの行を削除してください。
// const int Fixed::_fractionalBits = 8; // この行はFixed.hppで初期化済みのため通常は不要。

// Fixedクラスのデフォルトコンストラクタ
// オブジェクトが引数なしで作成されたときに呼び出されます (例: Fixed a;)。
// 演習の要件: 固定小数点数値を0に初期化する。
Fixed::Fixed(): value(0) // ここでプライベートメンバ 'value' (または _value) を0に初期化します。
{
    // コンストラクタが呼び出されたことを示すメッセージを出力します。
    std::cout << "Default constructor called" << std::endl;
}

// Fixedクラスのデストラクタ
// オブジェクトがスコープを抜けるなどして破棄されるときに呼び出されます。
// メモリの解放など、オブジェクト終了時のクリーンアップ処理をここで行います。
Fixed::~Fixed()
{
    // デストラクタが呼び出されたことを示すメッセージを出力します。
    std::cout << "Destructor called" << std::endl;
}

// Fixedクラスのコピーコンストラクタ
// 既存のFixedオブジェクトから新しいFixedオブジェクトが作成されるときに呼び出されます (例: Fixed b(a);)。
// 演習の要件: コピーコンストラクタの実装。
Fixed::Fixed(const Fixed& copy) // 'copy' はコピー元のオブジェクトです。
{
    // コピーコンストラクタが呼び出されたことを示すメッセージを出力します。
    std::cout << "Copy constructor called" << std::endl;
    // コピー代入演算子を呼び出して、'copy' オブジェクトの内容を現在のオブジェクトにコピーします。
    // これにより、重複するコードを避けることができます。
    *this = copy;
}

// Fixedクラスのコピー代入演算子オーバーロード
// 既存のFixedオブジェクトに別のFixedオブジェクトの値が代入されるときに呼び出されます (例: c = b;)。
// 演習の要件: コピー代入演算子オーバーロードの実装。
Fixed &Fixed::operator=(const Fixed &src) // 'src' は代入元のオブジェクトです。
{
    // コピー代入演算子が呼び出されたことを示すメッセージを出力します。
    std::cout << "Copy assignment operator called" << std::endl;
    // 自己代入（obj = obj; のような操作）を防ぐためのチェックです。
    // 自分自身への代入でなければ、処理を実行します。
    if(this != &src)
    {
        // srcオブジェクトの生の値を取得し、現在のオブジェクトの 'value' (または _value) に設定します。
        // ここで src.getRawBits() が呼び出され、その中で getRawBits のメッセージが出力されます。
        this->value = src.getRawBits();
    }
    // 代入後のオブジェクト自身への参照を返します。
    // これにより、連鎖的な代入 (obj1 = obj2 = obj3;) が可能になります。
    return(*this);
}

// Fixed::getRawBitsメンバ関数
// 演習の要件: 固定小数点値の生の値（raw value）を返す const メンバ関数。
// 'const' キーワードは、この関数がオブジェクトの内部状態を変更しないことを示します。
int Fixed::getRawBits(void) const
{
    // getRawBitsメンバ関数が呼び出されたことを示すメッセージを出力します。
    // 演習のサンプル出力に合わせるために必要です。
    std::cout << "getRawBits member function called" << std::endl;
    // 現在のオブジェクトの 'value' (または _value) メンバ変数の値を返します。
    return(this->value);
}

// Fixed::setRawBitsメンバ関数
// 演習の要件: 固定小数点数の生の値（raw value）を設定するメンバ関数。
void Fixed::setRawBits(int const raw) // 'raw' は設定する生の値です。
{
    // 現在のオブジェクトの 'value' (または _value) メンバ変数を 'raw' の値に設定します。
    this->value = raw;
}
