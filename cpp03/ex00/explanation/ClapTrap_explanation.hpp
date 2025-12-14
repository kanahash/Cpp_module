/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_explanation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:35:16 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:36:21 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// このファイルは、ClapTrapクラスの設計図（ヘッダーファイル）です。
// 通常、クラスを使うプログラムの先頭でインクルードされます。

#ifndef CLAPTRAP_HPP // #ifndef は、このヘッダーファイルが複数回読み込まれるのを防ぐ「インクルードガード」です。
#define CLAPTRAP_HPP // これにより、同じクラスが何度も定義されてしまうエラーを防ぎます。

#include <string>   // std::stringクラスを使うために必要です。
#include <iostream> // std::cout（標準出力）を使うために必要です。

class ClapTrap // これからClapTrapという名前のクラスを定義します。
{
    private: // ここから下の変数は、ClapTrapクラスの内部からしかアクセスできません。
             // これが「カプセル化」という考え方です。
            std::string name;        // ClapTrapの名前を格納する変数です。
            unsigned int hit_points;    // 体力（ヒットポイント）を格納する変数です。
            unsigned int energy_points; // エネルギーポイントを格納する変数です。
            unsigned int attack_damage; // 攻撃力を格納する変数です。

    public:  // ここから下の関数は、クラスの外部（他のプログラム）から呼び出すことができます。
            ClapTrap(); // デフォルトコンストラクタ。引数なしでオブジェクトが作られる時に呼ばれます。
                        // 例えば、ClapTrap clap; のように使います。
            ~ClapTrap(); // デストラクタ。オブジェクトが破棄される時に呼ばれます。
                         // メモリを解放したり、終了処理をしたりするのに使われます。
            ClapTrap(const ClapTrap& other); // コピーコンストラクタ。既存のオブジェクトをコピーして
                                             // 新しいオブジェクトを作る時に呼ばれます。
                                             // 例えば、ClapTrap new_clap = old_clap; のように使います。
            ClapTrap& operator=(const ClapTrap& other); // コピー代入演算子。既存のオブジェクトに
                                                        // 別のオブジェクトを代入する時に呼ばれます。
                                                        // 例えば、new_clap = another_clap; のように使います。
            ClapTrap(std::string name); // 引数付きコンストラクタ。名前を渡してオブジェクトを
                                        // 作る時に呼ばれます。
                                        // 例えば、ClapTrap player("Player1"); のように使います。

    // 以下の3つの関数は、ClapTrapの行動を定義するメンバ関数です。
    void attack(const std::string& target);    // 攻撃する関数。攻撃対象の名前を引数にとります。
                                               // 内部では、エネルギーポイントを消費し、ターゲットにダメージを与えます。
    void takeDamage(unsigned int amount);      // ダメージを受ける関数。ダメージ量を引数にとります。
                                               // 内部では、ヒットポイントが減ります。
    void beRepaired(unsigned int amount);      // 修復する関数。回復量を引数にとります。
                                               // 内部では、エネルギーポイントを消費し、ヒットポイントを回復します。
};

#endif // インクルードガードの終わり
