/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_explanation.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:23:18 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 22:23:20 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP // ヘッダーガードの開始: FIXED_HPP がまだ定義されていなければ…
#define FIXED_HPP // FIXED_HPP を定義します。これにより、同じヘッダーファイルが複数回インクルードされるのを防ぎます。

#include <string>     // 文字列操作が必要な場合に備えてインクルードされますが、このクラスでは直接使用されていません。
#include <iostream>   // 標準入出力（std::cout, std::endl など）を使用するためにインクルードされます。
#include <cmath>      // 数学関数（例: roundf）を使用するためにインクルードされます。

// Fixed クラスの宣言
// このクラスは固定小数点数を表現し、算術演算や比較演算をサポートします。
class Fixed
{
    // private メンバー: クラスの外部から直接アクセスできないデータや関数。
    // クラスの内部実装の詳細であり、カプセル化されています。
    private:
        int value; // 固定小数点数を整数として内部に格納するための変数。
                   // 例えば、値 10.1 を 1010 のように、小数部分を整数の一部として扱います。

        // static const メンバー: クラスのすべてのインスタンスで共有される定数。
        // 'static' なので、Fixed オブジェクトごとにコピーされません。
        // 'const' なので、変更できません。
        static const int fractionalBits = 8; // 小数点以下のビット数。この値が固定小数点の精度を決定します。
                                            // 8ビットの場合、小数点の後に 8 ビット分の情報が格納されます（2^8 = 256 段階の精度）。

    // public メンバー: クラスの外部からアクセスできるデータや関数。
    // Fixed オブジェクトを操作するためのインターフェースを提供します。
    public:
        // --- コンストラクタとデストラクタ ---

        // デフォルトコンストラクタ: 引数なしで Fixed オブジェクトを初期化します (例: Fixed a;)。
        Fixed();
        // デストラクタ: Fixed オブジェクトが破棄されるときに呼ばれます。リソースの解放などを行います。
        ~Fixed();
        // コピーコンストラクタ: 既存の Fixed オブジェクトから新しいオブジェクトを作成します (例: Fixed b(a);)。
        Fixed(const Fixed& copy);
        // int コンストラクタ: 整数値から Fixed オブジェクトを作成します (例: Fixed c(10);)。
        Fixed(const int value);
        // float コンストラクタ: 浮動小数点数値から Fixed オブジェクトを作成します (例: Fixed d(5.05f);)。
        Fixed(const float value);
        // コピー代入演算子: 既存の Fixed オブジェクトの値を別の既存のオブジェクトに代入します (例: a = b;)。
        // '&' は参照を意味し、オブジェクト自身を返すことで連鎖代入を可能にします。
        // 'const Fixed &src' は、引数が参照であり、かつ変更されないことを保証します。
        Fixed &operator=(const Fixed &src);
        
        // --- ゲッターとセッター ---

        // getRawBits: 内部の生の値（固定小数点表現の整数値）を取得します。
        // 'const' は、この関数がオブジェクトの状態を変更しないことを示します。
        int getRawBits(void) const;
        // setRawBits: 内部の生の値（固定小数点表現の整数値）を設定します。
        // 'int const raw' は、引数 'raw' が関数内で変更されないことを示します。
        void setRawBits(int const raw);
        
        // --- 型変換関数 ---

        // toFloat: Fixed 値を浮動小数点数 (float) に変換して返します。
        float toFloat(void) const;
        // toInt: Fixed 値を整数 (int) に変換して返します（小数点以下は切り捨てられます）。
        int toInt(void) const;

        // --- 比較演算子オーバーロード ---
        // これらの関数は、2つの Fixed オブジェクトを比較し、結果を bool (true または false) で返します。
        // 'const' は、これらの比較がオブジェクトの状態を変更しないことを保証します。
        // '>': より大きい
        bool operator>(const Fixed& other) const;
        // '<': より小さい
        bool operator<(const Fixed& other) const;
        // '>=': 以上
        bool operator>=(const Fixed& other) const;
        // '<=': 以下
        bool operator<=(const Fixed& other) const;
        // '==': 等しい
        bool operator==(const Fixed& other) const;
        // '!=': 等しくない
        bool operator!=(const Fixed& other) const;

        // --- 算術演算子オーバーロード ---
        // これらの関数は、2つの Fixed オブジェクトに対して算術演算を行い、新しい Fixed オブジェクトを結果として返します。
        // 'const' は、これらの演算が元のオブジェクトの状態を変更しないことを保証します。
        // '+': 加算
        Fixed operator+(const Fixed& other) const;
        // '-': 減算
        Fixed operator-(const Fixed& other) const;
        // '*': 乗算
        Fixed operator*(const Fixed& other) const;
        // '/': 除算
        Fixed operator/(const Fixed& other) const;

        // --- インクリメント/デクリメント演算子オーバーロード ---
        // これらの演算子は、Fixed オブジェクトの値を最小単位（epsilon）で増減させます。

        // プリインクリメント (++FixedObj): オブジェクトの値を増加させ、増加後のオブジェクト自身への参照を返します。
        Fixed& operator++();
        // ポストインクリメント (FixedObj++): オブジェクトの値を増加させますが、増加「前」の値のコピーを返します。
        // ダミーの 'int' 引数は、プリインクリメントとポストインクリメントを区別するために使用されます。
        Fixed operator++(int);
        // プリデクリメント (--FixedObj): オブジェクトの値を減少させ、減少後のオブジェクト自身への参照を返します。
        Fixed& operator--();
        // ポストデクリメント (FixedObj--): オブジェクトの値を減少させますが、減少「前」の値のコピーを返します。
        Fixed operator--(int);

        // --- 静的メンバー関数 ---
        // これらの関数は 'static' なので、Fixed クラスのインスタンスを作成しなくても直接呼び出せます (例: Fixed::min(a, b);)。
        // 2つの Fixed オブジェクトを比較し、小さい方または大きい方への参照を返します。

        // min (非const参照版): 変更可能な Fixed オブジェクトを受け取り、小さい方への参照を返します。
        static Fixed& min(Fixed& a, Fixed& b);
        // max (非const参照版): 変更可能な Fixed オブジェクトを受け取り、大きい方への参照を返します。
        static Fixed& max(Fixed& a, Fixed& b);

        // min (const参照版): 変更不可能な Fixed オブジェクトを受け取り、小さい方への const 参照を返します。
        // これにより、const な Fixed オブジェクトに対しても min を呼び出すことができます。
        static const Fixed& min(const Fixed& a, const Fixed& b);
        // max (const参照版): 変更不可能な Fixed オブジェクトを受け取り、大きい方への const 参照を返します。
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

// --- グローバルな出力ストリーム演算子オーバーロード ---
// この関数はクラスのメンバーではないため、クラスの外で宣言されます。
// 'std::cout << fixed_obj;' のように、Fixed オブジェクトを直接標準出力に表示できるようにします。
// 'std::ostream& os' は出力ストリームへの参照で、'const Fixed& fixed' は出力する Fixed オブジェクトです。
// 'return(os)' は、連続して出力 (例: std::cout << a << b;) できるようにするために必要です。
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // ヘッダーガードの終了
