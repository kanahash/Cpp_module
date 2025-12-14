/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_explanation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:45:18 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:45:22 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// これはClapTrapクラスのヘッダーファイル（設計図）です。
// 通常、このクラスを利用するソースファイルの先頭でインクルードして使います。

#ifndef CLAPTRAP_HPP // 同じヘッダーファイルが複数回読み込まれるのを防ぐための「インクルードガード」です。
#define CLAPTRAP_HPP // この記述がないと、コンパイルエラーになる可能性があります。

#include <string>   // 名前を格納する`std::string`型を使うために必要です。
#include <iostream> // メッセージを標準出力に出力する`std::cout`を使うために必要です。

class ClapTrap // これからClapTrapという名前のクラスを定義します。
{
    protected: // ここから下のメンバ変数は、ClapTrapクラス自身と、
               // このクラスを継承した子クラスからアクセスできます。
               // これは`ex01`以降の課題で継承を使うために必要な変更です。
            std::string name;        // ClapTrapの名前を格納する変数です。
            unsigned int hit_points;    // 体力（ヒットポイント）を格納する変数です。
            unsigned int energy_points; // エネルギーポイントを格納する変数です。
            unsigned int attack_damage; // 攻撃力を格納する変数です。

    public:  // ここから下のメンバ関数は、クラスの外部から自由に呼び出すことができます。
            ClapTrap(); // デフォルトコンストラクタ。引数なしでClapTrapオブジェクトが作られる時に呼ばれます。
                        // 例: `ClapTrap clap;`
            virtual ~ClapTrap(); // デストラクタ。オブジェクトが破棄される時に呼ばれます。
                                 // `virtual`キーワードが付いているのは、継承関係のクラスで
                                 // 正しくデストラクタが呼ばれるようにするためです。
            ClapTrap(const ClapTrap& other); // コピーコンストラクタ。既存のClapTrapオブジェクトから
                                             // 新しいオブジェクトを作成する時に呼ばれます。
                                             // 例: `ClapTrap new_clap = old_clap;`
            ClapTrap& operator=(const ClapTrap& other); // コピー代入演算子。既存のClapTrapオブジェクトに
                                                        // 別のClapTrapオブジェクトを代入する時に呼ばれます。
                                                        // 例: `new_clap = another_clap;`
            ClapTrap(std::string name); // 引数付きコンストラクタ。名前を渡してオブジェクトを作成する時に呼ばれます。
                                        // 例: `ClapTrap player("Player1");`

    // 以下の3つの関数は、ClapTrapの行動を定義するメンバ関数です。
    void attack(const std::string& target);    // 攻撃する関数。攻撃対象の名前を引数にとります。
                                               // 内部では、エネルギーポイントを消費し、ターゲットにダメージを与えます。
    void takeDamage(unsigned int amount);      // ダメージを受ける関数。ダメージ量を引数にとります。
                                               // 内部では、ヒットポイントが減ります。
    void beRepaired(unsigned int amount);      // 修復する関数。回復量を引数にとります。
                                               // 内部では、エネルギーポイントを消費し、ヒットポイントを回復します。
};

#endif // インクルードガードの終わり
