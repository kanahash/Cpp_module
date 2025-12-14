/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:51:35 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:52:01 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"     // AAnimalクラスのヘッダーを読み込みます。抽象クラスです。
#include "Cat.hpp"         // Catクラスのヘッダーを読み込みます。
#include "Dog.hpp"         // Dogクラスのヘッダーを読み込みます。
#include "WrongAnimal.hpp" // WrongAnimalクラスのヘッダーを読み込みます。（このコードでは使用していません）
#include "WrongCat.hpp"    // WrongCatクラスのヘッダーを読み込みます。（このコードでは使用していません）
#include "Brain.hpp"       // Brainクラスのヘッダーを読み込みます。

#define ANIMALS_COUNT 4 // プリプロセッサディレクティブ。`ANIMALS_COUNT`という名前を`4`という値に置き換えます。

int main(void) // プログラムのメイン関数です。ここから実行が始まります。
{
    std::cout << "--- Creating an array of Dogs and Cats ---" << std::endl;
    // AAnimalクラスのポインタを4つ格納できる配列を宣言します。
    // AAnimalは抽象クラスなので、この配列には直接AAnimalオブジェクトを入れることはできません。
    // しかし、AAnimalを継承したDogやCatのオブジェクトのポインタを格納することはできます。
    AAnimal* animals[ANIMALS_COUNT];

    // 配列の前半にDogオブジェクトを作成します。
    // `ANIMALS_COUNT / 2` は `4 / 2` で `2` になります。
    for (int i = 0; i < ANIMALS_COUNT / 2; i++)
        // 新しいDogオブジェクトを動的に（実行時に）作成し、ポインタを配列に格納します。
        // ここではAAnimalポインタとして扱われていますが、実体はDogオブジェクトです。
        animals[i] = new Dog;
    
    // 配列の後半にCatオブジェクトを作成します。
    for (int i = ANIMALS_COUNT / 2; i < ANIMALS_COUNT; i++)
        // 新しいCatオブジェクトを動的に作成し、ポインタを配列に格納します。
        animals[i] = new Cat();
    std::cout << std::endl;

    std::cout << "--- Deleting the array of Animals ---" << std::endl;
    // `new`で確保したメモリは、必ず`delete`で解放する必要があります。
    // そうしないと「メモリリーク」という問題が起こります。
    for (int i = 0; i < ANIMALS_COUNT; i++)
        // `delete` を使うことで、`new` で確保したメモリを解放します。
        // AAnimalクラスのデストラクタが`virtual`なので、各オブジェクトの正しいデストラクタ（DogやCat）が呼ばれます。
        delete animals[i];
    std::cout << std::endl;
    
    std::cout << "--- Deep Copy Test ---" << std::endl;
    // `originalDog`という名前のDogオブジェクトを作成します。
    Dog originalDog;

    // `originalDog`を元に、コピーコンストラクタを使って`copiedDog`を初期化します。
    // もしDogクラスにディープコピーが実装されていれば、`brain`も新しく作成されます。
    Dog copiedDog = originalDog;

    // オリジナルのDogとコピーしたDogの`type`を出力します。
    std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
    std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;

    // オリジナルとコピーしたDogが持つ`brain`オブジェクトのメモリアドレスを出力します。
    // ディープコピーが正しく行われていれば、このアドレスは異なります。
    std::cout << "Original Dog's brain address: " << originalDog.getBrain() << std::endl;
    std::cout << "Copied Dog's brain address: " << copiedDog.getBrain() << std::endl;

    // 2つの`brain`のアドレスが異なるかどうかを比較します。
    if(originalDog.getBrain() != copiedDog.getBrain())
        // アドレスが異なれば、`brain`オブジェクトも個別に作成された（ディープコピー）ことになります。
        std::cout << "--> Deep copy successful! Brain addresses are different." << std::endl;
    else
        // アドレスが同じなら、`brain`オブジェクトが共有されている（シャローコピー）ことになります。
        std::cout << "--> Shallow copy detected! Brain address are the same." << std::endl;

    std::cout << "--- End of Deep Copy Test ---" << std::endl;
    std::cout << std::endl;

    return(0); // プログラムが正常に終了したことをOSに伝えます。
}
