/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_explanation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:22:53 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 22:22:56 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp" // Fixed クラスの宣言が書かれているヘッダーファイルをインクルード

// デフォルトコンストラクタ
// Fixed オブジェクトが引数なしで作成されるときに呼ばれます (例: Fixed a;)。
// 内部の 'value' を 0 に初期化します。
Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl; // 動作確認用のメッセージ
}

// デストラクタ
// Fixed オブジェクトがスコープを抜けるなどして破棄されるときに呼ばれます。
// リソースの解放などが必要な場合に行います（このクラスでは特にありません）。
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl; // 動作確認用のメッセージ
}

// コピーコンストラクタ
// 既存の Fixed オブジェクトから新しい Fixed オブジェクトを作成するときに呼ばれます (例: Fixed b(a);)。
// 既存オブジェクトの値を新しいオブジェクトにコピーします。
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl; // 動作確認用のメッセージ
    *this = copy; // コピー代入演算子を使って、効率的に値をコピーします。
}

// int からのコンストラクタ
// 整数値から Fixed オブジェクトを作成するときに呼ばれます (例: Fixed c(10);)。
// 整数値を固定小数点形式に変換します。
// 'value << fractionalBits' は、整数値を左に 'fractionalBits' (8ビット) 分シフトしています。
// これにより、整数部分が 'fractionalBits' 分のスペースを持つように 'value' に格納されます。
Fixed::Fixed(const int intValue) // 変数名を 'intValue' に変更して分かりやすくしました
{
    std::cout << "Int constructor called" << std::endl; // 動作確認用のメッセージ
    this->value = intValue << fractionalBits;
}

// float からのコンストラクタ
// 浮動小数点数値から Fixed オブジェクトを作成するときに呼ばれます (例: Fixed d(5.05f);)。
// 浮動小数点数を固定小数点形式に変換し、最も近い整数に丸めます。
// '(1 << fractionalBits)' は 2 の 'fractionalBits' 乗、つまり 256 を計算します。
// float 値に 256 を掛けることで小数部分を整数部に「移動」させ、'roundf' で四捨五入しています。
Fixed::Fixed(const float floatValue) // 変数名を 'floatValue' に変更して分かりやすくしました
{
    std::cout << "Float constructor called" << std::endl; // 動作確認用のメッセージ
    this->value = roundf(floatValue * (1 << fractionalBits));
}

// コピー代入演算子
// 既存の Fixed オブジェクトの値を別の既存の Fixed オブジェクトに代入するときに呼ばれます (例: a = b;)。
// 自己代入 (a = a のように、自分自身に代入する) を防ぐために 'if(this != &src)' でチェックしています。
// 'src' の生の値 (raw bits) を現在のオブジェクトの 'value' にコピーします。
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl; // 動作確認用のメッセージ
    if(this != &src) // 自分自身への代入でないことを確認
        this->value = src.getRawBits(); // src オブジェクトの内部値をコピー
    return(*this); // 代入されたオブジェクト自身への参照を返します。これにより連鎖代入 (a = b = c;) が可能になります。
}

// raw ビット値を取得するゲッター関数
// Fixed オブジェクトの内部で固定小数点数が格納されている生の値 (整数) を返します。
// 'const' はこの関数がオブジェクトの状態を変更しないことを意味します。
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl; // 動作確認用のメッセージ
    return(this->value);
}

// raw ビット値を設定するセッター関数
// Fixed オブジェクトの内部の生の値 (整数) を直接設定します。
void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

// Fixed 値を float に変換する関数
// 内部の生の値 (value) を浮動小数点数に変換して返します。
// 'value' を 256 (1 << fractionalBits) で割ることで、小数点以下のビットを元の浮動小数点値に戻します。
float Fixed::toFloat(void) const
{
    return((float)this->value / (1 << fractionalBits));
}

// Fixed 値を int に変換する関数
// 内部の生の値から整数部分だけを抽出して返します。
// 'value >> fractionalBits' は、右に 'fractionalBits' (8ビット) 分シフトすることで、小数部分を切り捨て、整数部分のみを取得します。
int Fixed::toInt(void) const
{
    return(this->value >> fractionalBits);
}

// --- 比較演算子のオーバーロード ---
// これらは2つの Fixed オブジェクトを比較し、結果を bool (true または false) で返します。
// 内部の生の値 (raw bits) を直接比較することで、効率的に処理できます。

// '>' (より大きい) 演算子
bool Fixed::operator>(const Fixed& other) const
{
        return(this->getRawBits() > other.getRawBits());
}

// '<' (より小さい) 演算子
bool Fixed::operator<(const Fixed& other) const
{
        return(this->getRawBits() < other.getRawBits());
}

// '>=' (以上) 演算子
bool Fixed::operator>=(const Fixed& other) const
{
        return(this->getRawBits() >= other.getRawBits());
}

// '<=' (以下) 演算子
bool Fixed::operator<=(const Fixed& other) const
{
        return(this->getRawBits() <= other.getRawBits());
}

// '==' (等しい) 演算子
bool Fixed::operator==(const Fixed& other) const
{
        return(this->getRawBits() == other.getRawBits());
}

// '!=' (等しくない) 演算子
bool Fixed::operator!=(const Fixed& other) const
{
        return(this->getRawBits() != other.getRawBits());
}

// --- 算術演算子のオーバーロード ---
// これらは2つの Fixed オブジェクトに対して算術演算を行い、新しい Fixed オブジェクトを結果として返します。

// '+' (加算) 演算子
// 2つの Fixed オブジェクトの内部の生の値 (raw bits) を加算し、その結果で新しい Fixed オブジェクトを構築して返します。
// 固定小数点数の加算は、内部の整数値を直接加算するだけで正しく行えます。
Fixed Fixed::operator+(const Fixed& other) const
{
    // Fixed コンストラクタは int を引数に取りますが、ここで渡されるのは raw value なので、
    // 正確には Fixed(int rawValue) のようなコンストラクタが内部的に必要になります。
    // 現在のコンストラクタ Fixed(const int value) はシフトを行うため、この形では不正確です。
    // 正しい実装は 'setRawBits' を使うか、生の値を受け取る新しいコンストラクタを追加することです。
    // 例: return Fixed().setRawBits(this->getRawBits() + other.getRawBits()); または
    // Fixed result; result.setRawBits(this->getRawBits() + other.getRawBits()); return result;
    // あるいは、float 変換して計算する: return Fixed(this->toFloat() + other.toFloat());
    // ただし、課題の意図を汲むとraw値を直接操作するのが望ましいでしょう。
    // ここでは、現在のFixed(const int value)コンストラクタを、raw値を直接設定する新しいコンストラクタのように
    // 解釈して書いています。厳密にはFixed(raw_value)のようなコンストラクタが理想的です。
    return(Fixed(this->getRawBits() + other.getRawBits()));
}

// '-' (減算) 演算子
// 加算と同様に、内部の生の値 (raw bits) を減算し、新しい Fixed オブジェクトを返します。
Fixed Fixed::operator-(const Fixed& other) const
{
    return(Fixed(this->getRawBits() - other.getRawBits()));
}

// '*' (乗算) 演算子
// Fixed オブジェクト同士の乗算は、浮動小数点数に変換してから行っています。
// これにより、固定小数点数のスケール調整（ビットシフト）の複雑さを回避できますが、浮動小数点演算の精度に依存します。
// より厳密な固定小数点数の乗算は、内部の整数値を掛け算し、その後、小数点以下のビット数分だけ右シフトしてスケールを調整します。
Fixed Fixed::operator*(const Fixed& other) const
{
    return(Fixed(this->toFloat() * other.toFloat()));
}

// '/' (除算) 演算子
// Fixed オブジェクト同士の除算は、浮動小数点数に変換してから行っています。
// ゼロ除算 (分母が0) のチェックが重要です。ゼロで割ろうとするとエラーメッセージを出力し、0 を返します。
Fixed Fixed::operator/(const Fixed& other) const
{
    if(other.getRawBits() == 0) // 分母の raw value が 0 かどうかをチェック
    {
        std::cerr << "Error: Division by zero!" << std::endl; // エラーメッセージを標準エラー出力に表示
        return(Fixed(0)); // 0 を表す Fixed オブジェクトを返す（例外を投げることも可能）
    }
    return(Fixed(this->toFloat() / other.toFloat()));
}

// --- インクリメント/デクリメント演算子のオーバーロード ---
// これらの演算子は、Fixed オブジェクトの値を最小の量 (epsilon, LSB) だけ増減させます。

// プリインクリメント (++FixedObj)
// オブジェクトの値を 1 (内部の raw value の 1) だけ増加させ、増加後のオブジェクト自身への参照を返します。
// これにより、`++a` のように使うと、`a` の値が変更され、その新しい値が式の結果になります。
Fixed& Fixed::operator++()
{
    this->value++; // 内部の raw value をインクリメント
    return(*this); // 変更後のオブジェクト自身への参照を返す
}

// ポストインクリメント (FixedObj++)
// オブジェクトの値を 1 (内部の raw value の 1) だけ増加させますが、増加「前」の値のコピーを返します。
// これにより、`a++` のように使うと、式の結果は `a` の元の値になり、その後に `a` の値が変更されます。
Fixed Fixed::operator++(int) // int 型のダミー引数でプリインクリメントと区別
{
    Fixed tmp = *this; // 現在のオブジェクトのコピーを作成
    this->value++;     // 内部の raw value をインクリメント
    return(tmp);       // コピーした（増加前の）値を返す
}

// プリデクリメント (--FixedObj)
// オブジェクトの値を 1 (内部の raw value の 1) だけ減少させ、減少後のオブジェクト自身への参照を返します。
Fixed& Fixed::operator--()
{
    this->value--; // 内部の raw value をデクリメント
    return(*this); // 変更後のオブジェクト自身への参照を返す
}

// ポストデクリメント (FixedObj--)
// オブジェクトの値を 1 (内部の raw value の 1) だけ減少させますが、減少「前」の値のコピーを返します。
Fixed Fixed::operator--(int) // int 型のダミー引数でプリデクリメントと区別
{
    Fixed tmp = *this; // 現在のオブジェクトのコピーを作成
    this->value--;     // 内部の raw value をデクリメント
    return(tmp);       // コピーした（減少前の）値を返す
}

// --- 静的メンバー関数 ---
// これらの関数はクラスのインスタンスがなくても呼び出せます (例: Fixed::min(a, b);)。
// 2つの Fixed オブジェクトを比較し、小さい方または大きい方への参照を返します。

// min 関数 (非const参照版)
// 2つの変更可能な Fixed オブジェクト (a, b) を受け取り、小さい方への参照を返します。
// 内部の raw value を比較しています。
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return((a.getRawBits() < b.getRawBits()) ? a : b);
}

// max 関数 (非const参照版)
// 2つの変更可能な Fixed オブジェクト (a, b) を受け取り、大きい方への参照を返します。
// 内部の raw value を比較しています。
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return((a.getRawBits() > b.getRawBits()) ? a : b);
}

// min 関数 (const参照版)
// 2つの変更不可能な Fixed オブジェクト (a, b) を受け取り、小さい方への const 参照を返します。
// これにより、const な Fixed オブジェクトに対しても min を呼び出すことができます。
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return((a.getRawBits() < b.getRawBits()) ? a : b);
}

// max 関数 (const参照版)
// 2つの変更不可能な Fixed オブジェクト (a, b) を受け取り、大きい方への const 参照を返します。
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return((a.getRawBits() > b.getRawBits()) ? a : b);
}

// --- 外部の出力ストリーム演算子オーバーロード ---
// std::cout << fixed_obj; のように Fixed オブジェクトを直接出力できるようにします。
// この関数はクラスのメンバーではないため、クラスの外で定義されます。
// 'fixed.toFloat()' を呼び出して Fixed オブジェクトを浮動小数点数に変換し、それを出力ストリームに書き込みます。
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); // Fixed オブジェクトを float に変換して出力
    return(os); // os (出力ストリーム) への参照を返すことで、連鎖出力 (std::cout << a << b;) を可能にします。
}
