/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat_explanation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:19:40 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:20:24 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP  // もし "WRONGCAT_HPP" がまだ定義されていなければ...
#define WRONGCAT_HPP  // "WRONGCAT_HPP" を定義する。
                      // これは「インクルードガード」というおまじないです。
                      // このヘッダーファイルが複数回読み込まれるのを防ぎ、コンパイルエラーを避ける役割があります。

#include "WrongAnimal.hpp" // "WrongAnimal.hpp"を読み込む。
                          // WrongCatクラスは親クラスのWrongAnimalの機能を使うので、その設計図が必要です。

class WrongCat : public WrongAnimal // ここから WrongCat クラスの定義が始まります。
                                    // ": public WrongAnimal" は、WrongCatクラスがWrongAnimalクラスを「継承」することを意味します。
                                    // これにより、WrongCatクラスは親クラスのメンバー変数や関数を自動的に引き継ぎます。
{
    private:              // 'private'は、このクラスの内部からしかアクセスできないことを示します。
                          // このクラスには独自のメンバー変数がありません。

    public:               // 'public'は、どこからでもアクセスできることを示します。
                          // クラスの「外部向けインターフェース」を定義する場所です。
        WrongCat();       // デフォルトコンストラクタの宣言。
                          // WrongCatオブジェクトが作られるときに呼び出されます。

        ~WrongCat();      // デストラクタの宣言。
                          // オブジェクトが破棄されるときに呼び出されます。
                          // 親クラスのデストラクタに`virtual`がないため、メモリリークのリスクがあります。

        WrongCat(const WrongCat &copy); // コピーコンストラクタの宣言。
                                       // 既存のWrongCatオブジェクトをコピーして新しいオブジェクトを作るときに呼び出されます。

        WrongCat &operator=(const WrongCat &src); // コピー代入演算子の宣言。
                                                 // 既存のWrongCatオブジェクトに別のWrongCatオブジェクトを代入するときに呼び出されます。

        void makeSound() const; // 'makeSound'関数の宣言。
                                // 親クラス（WrongAnimal）にある同名の関数を「上書き」（オーバーライド）しています。
                                // しかし、親の関数に`virtual`が付いていないため、
                                // 親クラスのポインタからこの関数を呼び出しても、この関数は実行されません。
};

#endif // インクルードガードの終わり。
