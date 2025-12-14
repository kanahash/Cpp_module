/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal_explanation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:12:53 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:13:01 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp" // "Animal.hpp"というヘッダーファイルを読み込む。
                     // このファイルには、Animalクラスの宣言（設計図）が書かれている。

// Animalクラスのデフォルトコンストラクタ
// Animal型のオブジェクトが新しく作られるときに自動で呼び出される。
Animal::Animal() : type("Animal" ) // 初期化リスト。ここでは、メンバー変数'type'を"Animal"という文字列で初期化している。
{
    std::cout << "Animal default constructor called" << std::endl;
    // オブジェクトが作られたことを示すメッセージを出力。
}

// Animalクラスのデストラクタ
// Animal型のオブジェクトが破棄されるときに自動で呼び出される。
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
    // オブジェクトが破棄されたことを示すメッセージを出力。
}

// Animalクラスのコピーコンストラクタ
// 既存のAnimalオブジェクトから新しいAnimalオブジェクトを作る際に呼び出される。
// 例: Animal newAnimal = oldAnimal;
Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy; // コピー代入演算子を呼び出して、メンバー変数をコピーする。
}

// Animalクラスのコピー代入演算子
// 既存のAnimalオブジェクトに、別のAnimalオブジェクトの値を代入する際に呼び出される。
// 例: Animal animal1; Animal animal2; animal1 = animal2;
Animal& Animal::operator=(const Animal &src)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    // 自分自身への代入（例: animal1 = animal1;）を防ぐためのチェック。
    // 無駄な処理や予期せぬエラーを防ぐために重要。
    if(this != &src) 
        this->type = src.type; // srcオブジェクトの'type'を、現在のオブジェクトの'type'にコピーする。
    
    return(*this); // 代入後のオブジェクト自身を返す。これにより、a = b = c; のような連結代入が可能になる。
}

// 'type'メンバー変数の値を取得するための関数
// 'const'が付いているので、この関数はオブジェクトの状態を変更しないことを保証する。
std::string Animal::getType() const
{
    return(this->type); // 'type'の値を返す。
}

// 'Animal'が鳴く動作を定義する関数
// 'const'が付いているので、この関数はオブジェクトの状態を変更しない。
void Animal::makeSound() const
{
    std::cout << "Animal doesn't make any sound... " << std::endl;
    // このクラスは一般的な"動物"を表すため、具体的な鳴き声は持たないことを示している。
    // 'Dog'や'Cat'のような派生クラスが、この関数を具体的な鳴き声で上書き（オーバーライド）することを想定している。
}
