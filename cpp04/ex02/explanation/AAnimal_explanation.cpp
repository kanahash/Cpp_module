/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal_explanation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:50:30 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:50:37 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp" // AAnimalクラスの定義があるヘッダーファイルをインクルードします。

// デフォルトコンストラクタ
// 新しいAAnimalオブジェクトが作られるときに自動的に呼び出されます。
// `: type("Animal")` は「初期化リスト」といい、メンバー変数`type`を"Animal"という文字列で初期化します。
// これにより、コンストラクタ本体に入る前に変数がセットされます。
AAnimal::AAnimal() : type("Animal" )
{
    // オブジェクトが作成されたことを示すメッセージを出力します。
    std::cout << "AAnimal default constructor called" << std::endl;
}

// デストラクタ
// AAnimalオブジェクトが破棄されるときに自動的に呼び出されます。
// 動的に確保したメモリの解放など、後片付けの処理をここで行います。
AAnimal::~AAnimal()
{
    // オブジェクトが破棄されたことを示すメッセージを出力します。
    std::cout << "AAnimal destructor called" << std::endl;
}

// コピーコンストラクタ
// 既存のAAnimalオブジェクトから新しいAAnimalオブジェクトを作成するときに呼び出されます。
// 例: `AAnimal newAnimal = oldAnimal;`
AAnimal::AAnimal(const AAnimal &copy)
{
    // コピーコンストラクタが呼び出されたことを示すメッセージを出力します。
    std::cout << "AAnimal copy constructor called" << std::endl;
    // コピー代入演算子を呼び出して、メンバー変数のコピーを処理します。
    // この方法はシンプルですが、深いコピー（ディープコピー）が必要な場合は、ここで直接実装する方が良い場合もあります。
    *this = copy;
}

// コピー代入演算子
// 既存のAAnimalオブジェクトに、別のAAnimalオブジェクトの内容を代入するときに呼び出されます。
// 例: `existingAnimal = anotherAnimal;`
AAnimal& AAnimal::operator=(const AAnimal &src)
{
    // コピー代入演算子が呼び出されたことを示すメッセージを出力します。
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    // 自己代入のチェック
    // オブジェクト自身に代入しようとしていないか確認します。
    // `this` は現在のオブジェクトを指すポインタ、`&src` はコピー元のオブジェクトのアドレスです。
    // これらが異なる場合のみ、代入処理を実行します。
    if(this != &src)
    {
        // コピー元の`type`を、現在のオブジェクトの`type`に代入します。
        this->type = src.type;
    }
    // 代入されたオブジェクト自身の参照を返します。
    // これにより、連鎖的な代入(例: `a = b = c;`)が可能になります。
    return(*this);
}

// getTypeメソッド
// オブジェクトの`type`を返すための「ゲッター」関数です。
// `const`は、この関数がオブジェクトの状態を変更しないことを示します。
std::string AAnimal::getType() const
{
    // `type`メンバー変数の値を返します。
    return(this->type);
}
