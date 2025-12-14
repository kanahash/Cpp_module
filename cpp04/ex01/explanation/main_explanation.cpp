/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:48:06 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:48:08 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"    // Animalクラスのヘッダーを読み込みます。
#include "Cat.hpp"       // Catクラスのヘッダーを読み込みます。
#include "Dog.hpp"       // Dogクラスのヘッダーを読み込みます。
#include "WrongAnimal.hpp" // WrongAnimalクラスのヘッダーを読み込みます。
#include "WrongCat.hpp"    // WrongCatクラスのヘッダーを読み込みます。
#include "Brain.hpp"     // Brainクラスのヘッダーを読み込みます。

#define ANIMALS_COUNT 4 // プリプロセッサディレクティブで、`ANIMALS_COUNT`を4という値に置き換えます。

int main(void) // プログラムのメイン関数です。ここから実行が始まります。
{
    // Animalクラスのポインタを4つ格納できる配列を宣言します。
    // この配列には、Animalクラスを継承したDogやCatのオブジェクトを格納できます。
    Animal* animals[ANIMALS_COUNT];

    std::cout << "--- Creating an array of Dogs and Cats ---" << std::endl;
    // 配列の前半にDogオブジェクトを作成します。
    // `ANIMALS_COUNT / 2` は `4 / 2` で `2` になります。
    for (int i = 0; i < ANIMALS_COUNT / 2; i++)
        animals[i] = new Dog; // 新しいDogオブジェクトを動的に作成し、ポインタを配列に格納します。
    
    // 配列の後半にCatオブジェクトを作成します。
    // `ANIMALS_COUNT / 2` から `ANIMALS_COUNT - 1` までループします。
    for (int i = ANIMALS_COUNT / 2; i < ANIMALS_COUNT; i++)
        animals[i] = new Cat(); // 新しいCatオブジェクトを動的に作成し、ポインタを配列に格納します。
    std::cout << std::endl;

    std::cout << "--- Deleting the array of Animals ---" << std::endl;
    // 作成したすべてのオブジェクトをループで削除します。
    // `delete` を使うことで、`new` で確保したメモリを解放します。
    // `Animal` クラスのデストラクタが `virtual` なので、各オブジェクトの正しいデストラクタ(Dog, Cat)が呼ばれます。
    for (int i = 0; i < ANIMALS_COUNT; i++)
        delete animals[i];
    std::cout << std::endl;
    
    std::cout << "--- Deep Copy Test ---" << std::endl;
    // `originalDog`という名前のDogオブジェクトを作成します。
    Dog originalDog;

    // `originalDog`を元に、コピーコンストラクタを使って`copiedDog`を初期化します。
    // Dogクラスでディープコピーが実装されていれば、`brain`も新しく作成されます。
    Dog copiedDog = originalDog;

    // オリジナルのDogとコピーしたDogの`type`を出力します。
    std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
    std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;

    // オリジナルとコピーしたDogが持つ`brain`オブジェクトのメモリアドレスを出力します。
    std::cout << "Original Dog's brain address: " << originalDog.getBrain() << std::endl;
    std::cout << "Copied Dog's brain address: " << copiedDog.getBrain() << std::endl;

    // 2つの`brain`のアドレスが異なるかどうかを比較します。
    if(originalDog.getBrain() != copiedDog.getBrain())
        // アドレスが異なればディープコピー成功です。
        std::cout << "--> Deep copy successful! Brain addresses are different." << std::endl;
    else
        // アドレスが同じならシャローコピー（浅いコピー）です。
        std::cout << "--> Shallow copy detected! Brain address are the same." << std::endl;

    std::cout << "--- End of Deep Copy Test ---" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Simple Memory Leak Test ---" << std::endl;
    // Dogオブジェクトを動的に作成し、`Animal`ポインタ`j`に格納します。
    const Animal* j = new Dog();
    // Catオブジェクトを動的に作成し、`Animal`ポインタ`i`に格納します。
    const Animal* i = new Cat();
    
    // `delete` を使って、`new` で確保したメモリを解放します。
    // これを忘れるとメモリリークが発生します。
    delete j;
    delete i;

    return(0); // プログラムが正常終了したことをOSに伝えます。
}
