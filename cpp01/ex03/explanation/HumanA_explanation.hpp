/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA_explanation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 00:44:51 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/17 00:44:53 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP // ヘッダーガードの開始: HUMANA_HPPがまだ定義されていない場合のみ、以下のコードがコンパイルされます。
                   // これにより、同じヘッダーファイルが複数回インクルードされることを防ぎ、多重定義エラーを回避します。
#define HUMANA_HPP // HUMANA_HPPを定義します。

#include "Weapon.hpp" // Weaponクラスの定義が含まれるWeapon.hppファイルをインクルードします。
                      // HumanAクラスがWeaponクラスを参照するため、Weaponの定義が必要です。

class HumanA // HumanAという名前のクラスを宣言します。
{
    private: // privateセクション: これらのメンバーはクラスの外部から直接アクセスできません。
        std::string name; // HumanAの名前を保存するstring型のメンバー変数です。
        Weapon& weapon;   // HumanAが使用するWeaponオブジェクトへの参照です。
                          // 参照であるため、HumanAはWeaponオブジェクトの所有権を持たず、
                          // 既存のWeaponオブジェクトを参照します。これは、WeaponがHumanAよりも長く存続することを意味します。
    public: // publicセクション: これらのメンバーはクラスの外部からアクセスできます。
        // コンストラクター: HumanAオブジェクトが作成されるときに呼び出されます。
        // HumanAの名前と、使用するWeaponオブジェクトへの参照を受け取ります。
        HumanA(std::string name, Weapon &weapon);
        
        // デストラクター: HumanAオブジェクトが破棄されるときに呼び出されます。
        // リソースの解放など、クリーンアップ処理が必要な場合に実装されます。
        ~HumanA();
        
        // attackメソッド: HumanAが攻撃を実行する際に呼び出される関数です。
        // 'void'は、このメソッドが値を返さないことを示します。
        // 'const'は、このメソッドがHumanAオブジェクトのメンバー変数を変更しないことを保証します。
        void attack(void) const;
};

#endif // ヘッダーガードの終了: HUMANA_HPPが定義されていれば、#ifndefから#endifまでのコードはスキップされます。
