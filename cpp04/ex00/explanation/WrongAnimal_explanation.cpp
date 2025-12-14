/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal_explanation.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:17:58 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:18:08 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp" // "WrongAnimal.hpp"というヘッダーファイルを読み込む。
                          // ここにWrongAnimalクラスの設計図（宣言）が書かれている。

// WrongAnimalクラスのデフォルトコンストラクタ
// WrongAnimal型のオブジェクトが作られるときに自動で呼び出される。
WrongAnimal::WrongAnimal() : type("Default") // メンバー変数'type'を"Default"で初期化。
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    // オブジェクトが作られたことを示すメッセージを出力。
}

// WrongAnimalクラスのデストラクタ
// WrongAnimal型のオブジェクトが破棄されるときに自動で呼び出される。
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    // オブジェクトが破棄されたことを示すメッセージを出力。
}

// WrongAnimalクラスのコピーコンストラクタ
// 既存のWrongAnimalオブジェクトから新しいWrongAnimalオブジェクトを作る際に呼び出される。
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy; // コピー代入演算子を呼び出して、メンバー変数をコピーする。
}

// WrongAnimalクラスのコピー代入演算子
// 既存のWrongAnimalオブジェクトに、別のWrongAnimalオブジェクトの値を代入する際に呼び出される。
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    // 自分自身への代入を防ぐためのチェック。
    if(this != &src)
        this->type = src.type; // srcオブジェクトの'type'をコピーする。
    return(*this); // 代入後のオブジェクト自身を返す。
}

// 'type'メンバー変数の値を取得する関数
// 'const'が付いているので、オブジェクトの状態を変更しない。
std::string WrongAnimal::getType() const
{
    return(this->type); // 'type'の値を返す。
}

// 'WrongAnimal'の鳴き声を定義する関数
// ここが重要なポイントです。この関数には'virtual'キーワードが付いていない。
// そのため、もしこのクラスを継承した子クラス（例：WrongCat）でこの関数を上書きしても、
// 親クラスのポインタでこの関数を呼び出した場合、常にこの関数が呼ばれてしまう。
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound... " << std::endl;
    // ポリモーフィズムが働かないため、子クラスが独自の鳴き声を定義していても、
    // 親クラスのポインタからはこのメッセージしか出力されない。
}
