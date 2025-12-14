/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog_explanation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:16:03 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:16:06 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp" // "Dog.hpp"というヘッダーファイルを読み込む。
                   // ここにはDogクラスの設計図（宣言）が書かれている。
                   // このファイルは、さらに親クラスであるAnimal.hppを読み込んでいるはずです。

// Dogクラスのデフォルトコンストラクタ
// Dog型のオブジェクトが新しく作られるときに自動で呼び出される。
// Animal()は、親クラス（Animal）のデフォルトコンストラクタを呼び出すことを意味する。
Dog::Dog() : Animal()
{
    this->type = "Dog"; // 親クラスのメンバー変数'type'を"Dog"という文字列で上書きする。
                        // このメンバー変数は'protected'なので、子クラスからアクセスできる。
    std::cout << "Dog default constructor called" << std::endl;
    // オブジェクトが作られたことを示すメッセージを出力。
}

// Dogクラスのデストラクタ
// Dog型のオブジェクトが破棄されるときに自動で呼び出される。
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    // オブジェクトが破棄されたことを示すメッセージを出力。
    // この後、自動的に親クラス（Animal）のデストラクタが呼び出される。
}

// Dogクラスのコピーコンストラクタ
// 既存のDogオブジェクトから新しいDogオブジェクトを作る際に呼び出される。
// Animal(copy)で、親クラス（Animal）のコピーコンストラクタを呼び出し、親のデータをコピーする。
Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    // このDogクラスには独自のメンバー変数がないため、
    // 親クラスのコピーコンストラクタを呼び出すだけで十分。
    // ここでは特に他の処理は必要ない。
}

// Dogクラスのコピー代入演算子
// 既存のDogオブジェクトに、別のDogオブジェクトの値を代入する際に呼び出される。
Dog& Dog::operator=(const Dog &src)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    // 自分自身への代入（例: myDog = myDog;）を防ぐためのチェック。
    if(this != &src) {
        // Animal::operator=(src)で、親クラスのコピー代入演算子を呼び出す。
        // これにより、親クラスのメンバー変数（ここでは'type'）が正しくコピーされる。
        Animal::operator=(src);
    }
    return(*this); // 代入後のオブジェクト自身を返す。
}

// Dogの鳴き声を定義する関数
// 親クラス（Animal）のmakeSound()関数を上書き（オーバーライド）している。
void Dog::makeSound() const
{
    std::cout << this->getType() << "Wan Wan!" << std::endl;
    // この関数が呼び出されると、「Dog Wan Wan!」と出力される。
    // 仮想関数（virtual）のおかげで、Animal*型のポインタや参照でも、
    // 実際のオブジェクトがDogであれば、このmakeSound()が呼び出される。
}
