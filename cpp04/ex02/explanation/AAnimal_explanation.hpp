/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal_explanation.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:51:04 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:51:10 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP  // もし "AANIMAL_HPP" がまだ定義されていなければ...
#define AANIMAL_HPP  // "AANIMAL_HPP" を定義します。
                   // これは、このヘッダーファイルが複数回読み込まれるのを防ぐための「インクルードガード」です。

#include<string>     // 文字列を扱うための `std::string` クラスを使えるようにします。
#include<iostream>   // 標準入出力（`std::cout`など）を使えるようにします。

// AAnimalという名前のクラスを定義します。
// クラス名の`A`は、これが「抽象（Abstract）」クラスであることを示す慣習です。
class AAnimal
{
    protected:
        // `type`は、このクラスとその子クラス（派生クラス）からのみアクセスできる「protected」なメンバー変数です。
        // これには動物の種類（例："Dog"や"Cat"）を格納します。
        std::string type;
    public:
        // ここから下は、クラスの外から誰でもアクセスできる「public」なメンバー関数です。

        // デフォルトコンストラクタ
        // 新しいAAnimalオブジェクトが作られるときに呼ばれます。
        AAnimal();

        // デストラクタ
        // `virtual`キーワードは、継承関係でオブジェクトを正しく削除するために必要です。
        // これにより、子クラスのデストラクタが確実に呼ばれるようになります。
        virtual ~AAnimal();

        // コピーコンストラクタ
        // 既存のAAnimalオブジェクトを元に、新しいAAnimalオブジェクトを作る際に呼ばれます。
        AAnimal(const AAnimal &copy);

        // コピー代入演算子
        // 既存のAAnimalオブジェクトに、別のAAnimalオブジェクトの内容を代入する際に呼ばれます。
        AAnimal &operator=(const AAnimal &src);

        // getTypeメソッド
        // 動物の種類（`type`）を返すための関数です。
        // `const`は、この関数がオブジェクトの状態を変更しないことを示します。
        std::string getType() const;

        // makeSoundメソッド
        // `virtual void makeSound() const = 0;` は「純粋仮想関数」と呼ばれます。
        // `= 0` をつけることで、このクラスは**抽象クラス**となり、単独ではオブジェクトを直接作成できません。
        // 子クラスは必ずこの`makeSound`関数を実装（オーバーライド）しなければなりません。
        // これにより、すべての動物（子クラス）が必ず鳴き声を持つことを強制できます。
        virtual void makeSound() const = 0;
        
};

#endif
