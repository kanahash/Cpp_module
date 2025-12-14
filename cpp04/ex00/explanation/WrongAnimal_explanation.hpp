/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal_explanation.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:18:39 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:18:45 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP  // もし "WRONGANIMAL_HPP" がまだ定義されていなければ...
#define WRONGANIMAL_HPP  // "WRONGANIMAL_HPP" を定義する。
                         // これは「インクルードガード」というおまじないです。
                         // このヘッダーファイルが複数回読み込まれるのを防ぎ、コンパイルエラーを避ける役割があります。

#include <string>        // std::stringクラスを使うために、stringヘッダーファイルを読み込む。
#include <iostream>      // std::coutやstd::endlを使うために、iostreamヘッダーファイルを読み込む。

class WrongAnimal        // ここから WrongAnimal という名前のクラス（設計図）が始まります。
{
    protected:           // 'protected'は、このクラスと、このクラスを継承するクラスからのみアクセスできることを示します。
        std::string type;  // 動物の種類（例: "WrongCat"）を保存するメンバー変数です。

    public:              // 'public'は、どこからでもアクセスできることを示します。
                         // クラスの「外部向けインターフェース」を定義する場所です。
        WrongAnimal();   // デフォルトコンストラクタの宣言。オブジェクトが作られるときに呼び出されます。

        ~WrongAnimal();  // デストラクタの宣言。オブジェクトが破棄されるときに呼び出されます。
                         // ここが重要なポイントです。このデストラクタには**`virtual`が付いていません**。
                         // そのため、子クラスのオブジェクトを親クラスのポインタで削除すると、
                         // 子クラスのデストラクタが呼び出されず、メモリリークの原因になる可能性があります。

        WrongAnimal(const WrongAnimal &copy); // コピーコンストラクタの宣言。

        WrongAnimal &operator=(const WrongAnimal &src); // コピー代入演算子の宣言。

        std::string getType() const; // 'type'を取得する関数の宣言。

        void makeSound() const; // 'makeSound'関数の宣言。
                                // ここも重要なポイントです。この関数には**`virtual`が付いていません**。
                                // そのため、このクラスを継承した子クラスでこの関数をオーバーライドしても、
                                // 親クラスのポインタからこの関数を呼び出すと、常にこの親クラスの関数が呼ばれてしまいます。
                                // これが「ポリモーフィズムが働かない」状態です。
};

#endif
