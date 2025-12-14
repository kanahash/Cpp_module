/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap_explanation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:53:22 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:53:29 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// これはFragTrapクラスのヘッダーファイル（設計図）です。
// `ex02`の課題では、`ClapTrap`を継承してこのクラスを実装します。

#ifndef FRAGTRAP_HPP // インクルードガードです。このファイルが複数回読み込まれるのを防ぎます。
#define FRAGTRAP_HPP

#include "ClapTrap.hpp" // 親クラスであるClapTrapの定義を読み込むために必要です。
                         // これにより、FragTrapはClapTrapの機能を引き継ぐことができます。

// `class FragTrap : public ClapTrap`という記述は、
// FragTrapクラスがClapTrapクラスを「公開継承（public inheritance）」していることを意味します。
// これにより、FragTrapはClapTrapのpublicなメンバ関数を自分のメンバとして利用できます。
class FragTrap : public ClapTrap
{
    public: // ここから下の関数は、クラスの外部から呼び出すことができます。
        FragTrap(); // デフォルトコンストラクタ。引数なしでFragTrapオブジェクトが作られる時に呼ばれます。
                    // 例: `FragTrap frag;`
        ~FragTrap(); // デストラクタ。FragTrapオブジェクトが破棄される時に呼ばれます。
                     // この関数が呼ばれた後、自動的に親クラスのデストラクタも呼ばれます。
        FragTrap(std::string name); // 引数付きコンストラクタ。名前を渡してオブジェクトを作成する時に呼ばれます。
                                    // 例: `FragTrap player("FR4G-TP");`
        FragTrap(const FragTrap& other); // コピーコンストラクタ。既存のFragTrapオブジェクトから
                                         // 新しいオブジェクトを作成する時に呼ばれます。
                                         // 例: `FragTrap new_frag = old_frag;`
        FragTrap& operator=(const FragTrap& other); // コピー代入演算子。既存のFragTrapオブジェクトに
                                                    // 別のFragTrapオブジェクトを代入する時に呼ばれます。
                                                    // 例: `new_frag = another_frag;`

        // FragTrap独自の新しいメンバ関数です。
        // 親クラスにはない、このクラス特有の機能です。
        void highFivesGuys();
};

#endif // インクルードガードの終わり
