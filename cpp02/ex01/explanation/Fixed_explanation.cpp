/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_explanation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:40:34 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 17:40:37 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.cpp
// このファイルは、Fixedクラスの各メンバー関数（メソッド）や
// オーバーロードされた演算子（操作の定義）が実際に何をするかを定義しています。

#include "Fixed.hpp" // Fixedクラスの宣言（ヘッダーファイル）を読み込みます。
#include <cmath>     // roundf関数を使うために必要です。roundfは浮動小数点数を四捨五入する関数です。
                     // C++11以降ではcmathに含まれますが、C++98ではcstdlibやmath.hの場合もあります。

// 固定小数点数の内部表現で使用するビット数（小数点以下の桁数）は、
// Fixed.hppで「static const int fractionalBits = 8;」として定義されています。
// これはクラスのすべてのインスタンスで共有される定数です。
// 通常、static const メンバーはクラス内で初期化できますが、
// 古いC++98の環境では、クラス外で定義と初期化が必要な場合があります。
// 今回のコードでは、Fixed.hppで初期化されているため、ここでは特に操作は不要です。


// -------------------------------------------------------------------------
// コンストラクタ群 (オブジェクトが作成されるときに自動的に呼び出される関数)
// -------------------------------------------------------------------------

// デフォルトコンストラクタ (引数なしでFixedオブジェクトが作られるとき)
// 例: Fixed a;
Fixed::Fixed() : value(0) // メンバー初期化子リスト: メンバー変数'value'を0で初期化します。
{
    // 初期化されたことを示すメッセージを出力します。
    std::cout << "Default constructor called" << std::endl;
}

// デストラクタ (Fixedオブジェクトが破棄されるときに自動的に呼び出される関数)
// 例: main関数の終わりや、スコープを抜けるとき
Fixed::~Fixed()
{
    // 破棄されたことを示すメッセージを出力します。
    std::cout << "Destructor called" << std::endl;
}

// コピーコンストラクタ (既存のFixedオブジェクトから新しいFixedオブジェクトが作られるとき)
// 例: Fixed d(b);  Fixed other = someFixed;
Fixed::Fixed(const Fixed& copy) // 'const Fixed& copy' は、変更しないFixedオブジェクトを引数にとることを意味します。
{
    // コピーされたことを示すメッセージを出力します。
    std::cout << "Copy constructor called" << std::endl;
    // 自分自身を、引数'copy'の内容で代入します。
    // これにより、コピー代入演算子`operator=`が内部的に呼び出されます。
    // この方法は、コードの重複を避けるためによく使われます。
    *this = copy;
}

// int型引数を受け取るコンストラクタ (整数からFixedオブジェクトを作る)
// 例: Fixed b(10);
Fixed::Fixed(const int intValue) // 'const int intValue' は、変更しない整数を引数にとることを意味します。
{
    // 整数から変換されたことを示すメッセージを出力します。
    std::cout << "Int constructor called" << std::endl;
    // ここが固定小数点数変換の核心部分です。
    // 整数を固定小数点形式に変換します。
    // `intValue << fractionalBits` は、`intValue` を `fractionalBits` ビット分左にシフトします。
    // これは `intValue * (2 ^ fractionalBits)` と同じ意味です。
    // 例: intValue = 10, fractionalBits = 8 の場合
    // 10 (0...01010_2) を8ビット左シフトすると 10 * 2^8 = 10 * 256 = 2560 となります。
    // これで、小数点以下8ビット分の空間が確保され、整数部分が正しい位置に配置されます。
    this->value = intValue << fractionalBits;
}

// float型引数を受け取るコンストラクタ (浮動小数点数からFixedオブジェクトを作る)
// 例: Fixed c(42.42f);
Fixed::Fixed(const float floatValue) // 'const float floatValue' は、変更しない浮動小数点数を引数にとることを意味します。
{
    // 浮動小数点数から変換されたことを示すメッセージを出力します。
    std::cout << "Float constructor called" << std::endl;
    // 浮動小数点数を固定小数点形式に変換します。
    // まず `floatValue` に `(1 << fractionalBits)` (つまり 2^fractionalBits) を掛けます。
    // 例: floatValue = 42.42f, fractionalBits = 8 の場合
    // 42.42 * (1 << 8) = 42.42 * 256 = 10860.43... となります。
    // `roundf()` は、この結果を最も近い整数に四捨五入します。
    // これにより、小数点以下の情報が整数部分のビットに含まれる形になります。
    this->value = roundf(floatValue * (1 << fractionalBits));
}

// -------------------------------------------------------------------------
// 演算子オーバーロード (既存の演算子にFixedクラスでの振る舞いを定義)
// -------------------------------------------------------------------------

// 代入演算子オーバーロード (Fixedオブジェクトが別のFixedオブジェクトに代入されるとき)
// 例: a = b;
Fixed &Fixed::operator=(const Fixed &src) // `Fixed&` は、代入後に自分自身への参照を返すことを意味します。
                                          // `const Fixed& src` は、変更しないFixedオブジェクトを引数にとることを意味します。
{
    // 代入演算子が呼び出されたことを示すメッセージを出力します。
    std::cout << "Copy assignment operator called" << std::endl;
    // 自己代入のチェック: もし自分自身を自分自身に代入しようとしているなら、何もしません。
    // (例: Fixed a; a = a; のような場合)
    if(this != &src) // 'this' は現在のオブジェクトのポインタ、'&src' は引数オブジェクトのアドレスです。
    {
        // 引数'src'の生の固定小数点値を取得し、自分自身の'value'に代入します。
        this->value = src.getRawBits();
    }
    // 代入操作の一般的な慣習として、自分自身への参照を返します。
    // これにより、`a = b = c;` のような連結代入が可能になります。
    return(*this);
}

// -------------------------------------------------------------------------
// メンバー関数 (オブジェクトが持つ機能)
// -------------------------------------------------------------------------

// 生のビット値を取得する関数 (Fixedオブジェクトの内部の整数値そのままを返す)
// 例: myFixed.getRawBits();
int Fixed::getRawBits(void) const // 'const' は、この関数がオブジェクトの内部状態を変更しないことを示します。
{
    // 関数が呼び出されたことを示すメッセージを出力します。
    // 課題の出力例にはこのメッセージがあるので含めていますが、
    // 通常、getter関数ではこのような出力はしません。
    std::cout << "getRawBits member function called" << std::endl;
    // 内部の固定小数点値（整数）をそのまま返します。
    return(this->value);
}

// 生のビット値を設定する関数 (Fixedオブジェクトの内部の整数値を直接設定する)
// 例: myFixed.setRawBits(someInt);
void Fixed::setRawBits(int const raw) // 'int const raw' は、変更しない整数を引数にとることを意味します。
{
    // 引数で与えられた生の値で、内部の固定小数点値を上書きします。
    this->value = raw;
}

// 固定小数点値をfloat型に変換して返す関数
// 例: float f = myFixed.toFloat();
float Fixed::toFloat(void) const // 'const' は、この関数がオブジェクトの内部状態を変更しないことを示します。
{
    // 固定小数点数から浮動小数点数への変換です。
    // 内部の整数値 (`this->value`) を `(1 << fractionalBits)` (つまり 2^fractionalBits) で割ります。
    // `(float)this->value` とキャストすることで、整数除算ではなく浮動小数点除算が行われます。
    // 例: value = 2560, fractionalBits = 8 の場合
    // 2560 / (1 << 8) = 2560 / 256 = 10.0f となります。
    // 例: value = 10860, fractionalBits = 8 の場合
    // 10860 / 256 = 42.421875f となります。
    return((float)this->value / (1 << fractionalBits));
}

// 固定小数点値をint型に変換して返す関数
// 例: int i = myFixed.toInt();
int Fixed::toInt(void) const // 'const' は、この関数がオブジェクトの内部状態を変更しないことを示します。
{
    // 固定小数点数から整数への変換です。
    // 内部の整数値 (`this->value`) を `fractionalBits` ビット分右にシフトします。
    // これは `this->value / (2 ^ fractionalBits)` と同じ意味です。
    // 整数への右シフトは、小数点以下の部分を自動的に切り捨てます（負の数の扱いはC++98では注意が必要ですが、ここでは正の数のみを想定）。
    // 例: value = 2560, fractionalBits = 8 の場合
    // 2560 >> 8 = 10 となります。
    // 例: value = 10860, fractionalBits = 8 の場合
    // 10860 >> 8 = 42 となります（小数点以下は切り捨て）。
    return(this->value >> fractionalBits);
}

// -------------------------------------------------------------------------
// グローバル関数 (クラスの外部で定義されるが、クラスと密接に関連する機能)
// -------------------------------------------------------------------------

// 挿入演算子 `<<` のオーバーロード (Fixedオブジェクトをstd::coutなどに出力できるようにする)
// 例: std::cout << someFixedObject;
// この関数はFixedクラスのメンバー関数ではありません。
// 最初の引数は出力ストリームオブジェクトへの参照 (`std::ostream& os`)、
// 2番目の引数は出力したいFixedオブジェクトへのconst参照 (`const Fixed& fixed`) です。
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    // `fixed.toFloat()` を呼び出してFixedオブジェクトをfloat値に変換し、
    // そのfloat値をストリーム `os` に挿入します。
    os << fixed.toFloat();
    // ストリームオブジェクト自身への参照を返します。
    // これにより、`std::cout << fixed_a << fixed_b << std::endl;` のような連結出力が可能になります。
    return(os);
}
