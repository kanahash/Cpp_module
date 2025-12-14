/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat_explanation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:19:18 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:19:31 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp" // "WrongCat.hpp"というヘッダーファイルを読み込む。
                       // ここにはWrongCatクラスの設計図（宣言）が書かれている。
                       // このファイルは、さらに親クラスであるWrongAnimal.hppを読み込んでいるはず。

// WrongCatクラスのデフォルトコンストラクタ
// WrongCat型のオブジェクトが新しく作られるときに自動で呼び出される。
// 親クラス（WrongAnimal）のデフォルトコンストラクタを先に呼び出す。
WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat"; // 親クラスのメンバー変数'type'を"WrongCat"で上書きする。
                             // このメンバー変数は'protected'なので、子クラスからアクセスできる。
    std::cout << "WrongCat default constructor called" << std::endl;
    // オブジェクトが作られたことを示すメッセージを出力。
}

// WrongCatクラスのデストラクタ
// WrongCat型のオブジェクトが破棄されるときに自動で呼び出される。
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
    // オブジェクトが破棄されたことを示すメッセージを出力。
    // この後、自動的に親クラス（WrongAnimal）のデストラクタが呼び出される。
}

// WrongCatクラスのコピーコンストラクタ
// 既存のWrongCatオブジェクトから新しいWrongCatオブジェクトを作る際に呼び出される。
// Animal(copy)で、親クラス（WrongAnimal）のコピーコンストラクタを呼び出し、親のデータをコピーする。
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    // このクラスには独自のメンバー変数がないため、親のコンストラクタを呼び出すだけでよい。
}

// WrongCatクラスのコピー代入演算子
// 既存のWrongCatオブジェクトに、別のWrongCatオブジェクトの値を代入する際に呼び出される。
WrongCat& WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    // 自分自身への代入（例: myWrongCat = myWrongCat;）を防ぐためのチェック。
    if(this != &src) {
        // 親クラスのコピー代入演算子を呼び出す。
        // これにより、親クラスのメンバー変数（ここでは'type'）が正しくコピーされる。
        WrongAnimal::operator=(src);
    }
    return(*this); // 代入後のオブジェクト自身を返す。
}

// WrongCatの鳴き声を定義する関数
// 親クラス（WrongAnimal）のmakeSound()関数を上書きしている。
// しかし、親の関数に'virtual'が付いていないため、
// 親クラスのポインタからこの関数を呼び出しても、この関数は実行されない。
void WrongCat::makeSound() const
{
    std::cout << this->getType() << "WrongCat sound" << std::endl;
    // 親クラスのポインタで呼び出した場合、代わりに「WrongAnimal sound...」というメッセージが出力されてしまう。
}
