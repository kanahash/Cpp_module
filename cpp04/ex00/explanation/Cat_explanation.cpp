/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat_explanation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:14:25 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:14:28 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp" // "Cat.hpp"というヘッダーファイルを読み込む。
                   // ここにはCatクラスの設計図（宣言）が書かれている。
                   // このファイルは、さらに親クラスであるAnimal.hppを読み込んでいるはず。

// Catクラスのデフォルトコンストラクタ
// Cat型のオブジェクトが新しく作られるときに自動で呼び出される。
// Animal()は、親クラス（Animal）のデフォルトコンストラクタを呼び出すことを意味する。
Cat::Cat() : Animal()
{
    this->type = "Cat"; // 親クラスのメンバー変数'type'を"Cat"という文字列で上書きする。
                        // このメンバー変数は'protected'なので、子クラスからアクセスできる。
    std::cout << "Cat default constructor called" << std::endl;
    // オブジェクトが作られたことを示すメッセージを出力。
}

// Catクラスのデストラクタ
// Cat型のオブジェクトが破棄されるときに自動で呼び出される。
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    // オブジェクトが破棄されたことを示すメッセージを出力。
    // この後、自動的に親クラス（Animal）のデストラクタが呼び出される。
}

// Catクラスのコピーコンストラクタ
// 既存のCatオブジェクトから新しいCatオブジェクトを作る際に呼び出される。
Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy; // コピー代入演算子を呼び出して、メンバー変数をコピーする。
}

// Catクラスのコピー代入演算子
// 既存のCatオブジェクトに、別のCatオブジェクトの値を代入する際に呼び出される。
Cat& Cat::operator=(const Cat &src)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    // 自分自身への代入（例: myCat = myCat;）を防ぐためのチェック。
    if(this != &src) {
        // Animal::operator=(src)で、親クラスのコピー代入演算子を呼び出す。
        // これにより、親クラスのメンバー変数（ここでは'type'）が正しくコピーされる。
        Animal::operator=(src);
    }
    return(*this); // 代入後のオブジェクト自身を返す。
}

// Catの鳴き声を定義する関数
// 親クラス（Animal）のmakeSound()関数を上書き（オーバーライド）している。
void Cat::makeSound() const
{
    std::cout << this->getType() << "Nya-----" << std::endl;
    // この関数が呼び出されると、「Cat Nya-----」と出力される。
    // 仮想関数（virtual）のおかげで、Animal*型のポインタや参照でも、
    // 実際のオブジェクトがCatであれば、このmakeSound()が呼び出される。
}
