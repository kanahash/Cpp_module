/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:23:27 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/25 22:23:39 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp" // Fixedクラスの宣言を含むヘッダーファイルをインクルードします。

int main( void ) {
    // Fixedオブジェクト 'a' をデフォルトコンストラクタで作成します。
    // 内部の 'value' は0に初期化されます。
    // -> "Default constructor called" と出力されます。
    Fixed a;

    // Fixedオブジェクト 'b' を作成し、初期化します。
    // まず、一時的な Fixed(5.05f) オブジェクトが作成されます。
    // 次に、一時的な Fixed(2) オブジェクトが作成されます。
    // これら2つの一時オブジェクトが乗算され、その結果が新しい一時オブジェクトになります。
    // その一時オブジェクトを使って、'b' がコピーコンストラクタで初期化されます。
    // 'b' は 'const' として宣言されているため、後で値を変更することはできません。
    // -> "Float constructor called" (for 5.05f)
    // -> "Int constructor called" (for 2)
    // -> "Float constructor called" (for multiplication result)
    // -> "Copy constructor called" (for b)
    // -> 一時オブジェクトの "Destructor called" が数回発生します。
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    // Fixedオブジェクト 'a' の現在の値を出力します。
    // 'a' はデフォルトで0なので、"0" と出力されます。
    // -> 'operator<<' と 'toFloat()' が呼ばれます。
    std::cout << a << std::endl;

    // 'a' をプリインクリメントします (例: ++a)。
    // 'a' の値は直ちに増加し、その増加後の値が出力されます。
    // 最小単位 (epsilon) だけ増加するため、0.00390625 のような値になります。
    // -> 'operator++()' と 'operator<<'、'toFloat()' が呼ばれます。
    std::cout << ++a << std::endl;

    // 'a' の現在の値を出力します。
    // 上の行で既にインクリメントされているので、前の行と同じ値が出力されます。
    // -> 'operator<<' と 'toFloat()' が呼ばれます。
    std::cout << a << std::endl;

    // 'a' をポストインクリメントします (例: a++)。
    // この行では、'a' の**現在の値**が出力されます。
    // その後、'a' の値がインクリメントされます。
    // -> 'operator++(int)' と 'operator<<'、'toFloat()' が呼ばれます。
    // -> "Copy constructor called" (for temporary object created by operator++(int))
    // -> "Copy assignment operator called" (if copy-elision doesn't happen)
    std::cout << a++ << std::endl;

    // 'a' の現在の値を出力します。
    // 上の行のポストインクリメントによって値がさらに増加しているので、新しい値が出力されます。
    // 例えば、0.00390625 が 0.0078125 になります。
    // -> 'operator<<' と 'toFloat()' が呼ばれます。
    std::cout << a << std::endl;

    // 'b' の値を出力します。
    // 'Fixed(5.05f) * Fixed(2)' の計算結果、約 10.1 が表示されます。
    // -> 'operator<<' と 'toFloat()' が呼ばれます。
    std::cout << b << std::endl;

    // 'Fixed::max' 静的メンバー関数を呼び出し、'a' と 'b' のうち大きい方を出力します。
    // 'a' は非const、'b' はconstなので、適切なオーバーロード（この場合、`Fixed::max(Fixed&, const Fixed&)`）が選択されます。
    // 'b' の値の方が大きいので、'b' の値が出力されます。
    // -> 'Fixed::max' と 'operator<<'、'toFloat()' が呼ばれます。
    std::cout << Fixed::max( a, b ) << std::endl;
    
    // プログラムが正常終了したことを示します。
    return 0;
} // ここで main 関数のスコープが終了し、'a' と 'b' のデストラクタが呼ばれます。
  // -> "Destructor called" (for a)
  // -> "Destructor called" (for b)
  