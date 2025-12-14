/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap_explanation.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:47:11 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:47:31 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// これはScavTrapクラスのヘッダーファイル（設計図）です。
// `ex00`の`ClapTrap`クラスを継承して、新しいクラスを定義します。

#ifndef SCAVTRAP_HPP // インクルードガードです。このファイルが複数回読み込まれるのを防ぎます。
#define SCAVTRAP_HPP

#include "ClapTrap.hpp" // 親クラスであるClapTrapの定義を読み込むために必要です。
                         // これにより、ScavTrapはClapTrapの機能を引き継ぐことができます。

// `class ScavTrap : public ClapTrap` という記述は、
// ScavTrapクラスがClapTrapクラスを「公開継承（public inheritance）」していることを意味します。
// これにより、ClapTrapのpublicなメンバがScavTrapのpublicなメンバとして利用可能になります。
class ScavTrap : public ClapTrap
{
    public: // ここから下の関数は、クラスの外部から呼び出すことができます。
        ScavTrap(); // デフォルトコンストラクタ。引数なしでScavTrapオブジェクトが作られる時に呼ばれます。
                    // 例: `ScavTrap scav;`
        ~ScavTrap(); // デストラクタ。ScavTrapオブジェクトが破棄される時に呼ばれます。
                     // この関数が呼ばれた後、自動的に親クラスのデストラクタも呼ばれます。
        ScavTrap(const ScavTrap& other); // コピーコンストラクタ。既存のScavTrapオブジェクトから
                                         // 新しいオブジェクトを作成する時に呼ばれます。
                                         // 例: `ScavTrap new_scav = old_scav;`
        ScavTrap& operator=(const ScavTrap& other); // コピー代入演算子。既存のScavTrapオブジェクトに
                                                    // 別のScavTrapオブジェクトを代入する時に呼ばれます。
                                                    // 例: `new_scav = another_scav;`
        ScavTrap(std::string name); // 引数付きコンストラクタ。名前を渡してオブジェクトを作成する時に呼ばれます。
                                    // 例: `ScavTrap player("SCV-1");`

        // 親クラスであるClapTrapの`attack()`関数をオーバーライド（上書き）しています。
        // 同じ関数名ですが、ScavTrap独自の振る舞いを実装します。
        void attack(const std::string& target);
        
        // ScavTrap独自の新しいメンバ関数です。
        // 親クラスにはない、このクラス特有の機能です。
        void guardGate();
};

#endif // インクルードガードの終わり

