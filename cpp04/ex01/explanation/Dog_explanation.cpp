/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog_explanation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:34:20 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:34:23 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp" // Dogクラスの定義があるヘッダーファイルをインクルードします。
                   // 親クラスであるAnimalクラスの定義も、このヘッダーを通じてインクルードされます。

// デフォルトコンストラクタ
// Dogオブジェクトが新しく作られるときに呼ばれます。
// `: Animal()` は、**親クラス(Animal)** のデフォルトコンストラクタを先に呼び出すことを意味します。
// これにより、Animalクラスの初期化処理が最初に行われます。
Dog::Dog() : Animal()
{
    // Animalクラスのtype変数を "Dog" に設定します。
    // Animalクラスで保護されている(protected)メンバー変数なので、子クラスからアクセスできます。
    this->type = "Dog";
    
    // コンソールにメッセージを出力して、コンストラクタが呼ばれたことを知らせます。
    std::cout << "Dog default constructor called" << std::endl;
}

// デストラクタ
// Dogオブジェクトが破棄されるときに呼ばれます。
// 親クラスのデストラクタは、子クラスのデストラクタの後に自動的に呼ばれます。
Dog::~Dog()
{
    // コンソールにメッセージを出力して、デストラクタが呼ばれたことを知らせます。
    std::cout << "Dog destructor called" << std::endl;
}

// コピーコンストラクタ
// 既存のDogオブジェクトを元に、新しいDogオブジェクトを作る際に呼ばれます。
// `: Animal(copy)` は、**親クラス(Animal)** のコピーコンストラクタを呼び出し、
// 親クラスのメンバー(この場合は `type`)をコピーします。
Dog::Dog(const Dog &copy) : Animal(copy)
{
    // コンソールにメッセージを出力して、コピーコンストラクタが呼ばれたことを知らせます。
    std::cout << "Dog copy constructor called" << std::endl;
}

// コピー代入演算子
// 既存のDogオブジェクトに、別のDogオブジェクトの内容を代入する際に呼ばれます。
Dog& Dog::operator=(const Dog &src)
{
    // コンソールにメッセージを出力して、代入演算子が呼ばれたことを知らせます。
    std::cout << "Dog copy assignment operator called" << std::endl;
    
    // 自己代入のチェックを行います。`this` は現在のオブジェクトを指し、`&src` はコピー元のオブジェクトのアドレスです。
    // これらが同じでなければ、代入処理を実行します。
    if(this != &src)
    {
        // **親クラス(Animal)** のコピー代入演算子を明示的に呼び出します。
        // これにより、親クラスのメンバー変数(type)が正しくコピーされます。
        Animal::operator=(src);
    }
    // 代入されたオブジェクト自身への参照を返します。
    return(*this);
}

// makeSoundメソッド
// 仮想関数(virtual)としてAnimalクラスで定義されているため、
// Dogクラスで独自の振る舞いを実装(オーバーライド)できます。
void Dog::makeSound() const
{
    // `this->getType()` で親クラスの`type`を取得し、鳴き声と一緒に出力します。
    std::cout << this->getType() << "Wan Wan!" << std::endl;
}

// getBrainメソッド
// Dogクラスに存在するBrainオブジェクトへのポインタを返します。
// `const`は、このメソッドがオブジェクトの状態を変更しないことを保証します。
const Brain* Dog::getBrain() const
{
    // this->brain はDogクラス内に存在すると仮定されるBrainオブジェクトへのポインタです。
    // このポインタを返します。
    return(this->brain);
}
