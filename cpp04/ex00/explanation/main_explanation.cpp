/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:17:17 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:17:31 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 必要なヘッダーファイルをすべて読み込む。
// ここには、これから使うクラスの「設計図」が書かれている。
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "--- Polymorphism Test ---" << std::endl;

    // 親クラスAnimalのポインタを使い、子クラスのオブジェクトを作る。
    // これがポリモーフィズムの典型的な使い方です。
    // 親クラスのポインタが、子クラスのオブジェクトを指すことができる。
    const Animal* meta = new Animal(); // Animalクラスのオブジェクトを作成。
    const Animal* j = new Dog();      // Dogクラスのオブジェクトを、Animal*型ポインタで指す。
    const Animal* i = new Cat();      // Catクラスのオブジェクトを、Animal*型ポインタで指す。

    // getType()はvirtualではないので、親クラスのAnimal::getType()が呼ばれる。
    // ただし、子クラスでgetType()をオーバーライドしているので、
    // ここではDogとCatそれぞれのgetType()が呼ばれる。
    std::cout << "j's type: " << j->getType() << std::endl;
    std::cout << "i's type: " << i->getType() << std::endl;

    std::cout << "--- Calling makeSound() ---" << std::endl;

    // makeSound()は親クラスのAnimalで'virtual'と宣言されている。
    // そのため、ポインタが指している「実際のオブジェクトの型」に応じて、
    // 適切なmakeSound()関数が呼び出される。
    // これがポリモーフィズムの核心です。
    i->makeSound();     // 実際のオブジェクトはCatなので、CatのmakeSound()が呼ばれる。
    j->makeSound();     // 実際のオブジェクトはDogなので、DogのmakeSound()が呼ばれる。
    meta->makeSound();  // 実際のオブジェクトはAnimalなので、AnimalのmakeSound()が呼ばれる。

    // newで確保したメモリは、deleteで解放する。
    // virtualデストラクタのおかげで、正しく子クラスのデストラクタも呼ばれる。
    delete meta;
    delete j;
    delete i;
    std::cout << std::endl;

    std::cout << "--- Non-Polymorphism Test ---" << std::endl;
    
    // こちらは'virtual'が付いていないAnimal（WrongAnimal）を使ったテスト。
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat(); // WrongCatオブジェクトをWrongAnimal*型ポインタで指す。
    
    // getType()は問題なく動く。
    std::cout << "wrongI's type: " << wrongI->getType() << std::endl;
    
    std::cout << "--- Calling makeSound() ---" << std::endl;
    
    // 問題の箇所。
    // makeSound()に'virtual'が付いていないため、コンパイラはポインタの型（WrongAnimal*）だけを見て関数を決める。
    // そのため、実際のオブジェクトがWrongCatであっても、WrongAnimal::makeSound()が呼び出されてしまう。
    // これが「ポリモーフィズムが働いていない」状態です。
    wrongI->makeSound();    // 常にWrongAnimal::makeSound()が呼ばれる。
    wrongMeta->makeSound(); // 常にWrongAnimal::makeSound()が呼ばれる。

    // newで確保したメモリを解放する。
    // デストラクタもvirtualではないため、wrongIのデストラクタ呼び出しに問題が発生する可能性がある。
    delete wrongMeta;
    delete wrongI;

    return(0); // プログラムが正常終了したことをOSに知らせる。
}
