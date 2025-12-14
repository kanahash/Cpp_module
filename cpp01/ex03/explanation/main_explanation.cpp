/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 00:45:47 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/17 00:45:53 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"  // Weaponクラスの定義をインクルードします。武器の機能を提供します。
#include "HumanA.hpp"  // HumanAクラスの定義をインクルードします。HumanAはコンストラクターで武器を必須とします。
#include "HumanB.hpp"  // HumanBクラスの定義をインクルードします。HumanBは後から武器を装備できます。

// main関数はプログラムのエントリーポイントです。
int main()
{
    // 最初のスコープブロックを開始します。
    // このブロック内で宣言されたオブジェクトは、ブロックの終わりで破棄されます。
    {
        // "crude spiked club"というタイプのWeaponオブジェクト'club'を作成します。
        Weapon club = Weapon("crude spiked club");

        // 'club'を武器として、"Bob"という名前のHumanAオブジェクト'bob'を作成します。
        // HumanAはコンストラクターで武器への参照を受け取るため、ここで武器が必須です。
        HumanA bob("Bob", club);
        
        // bobに攻撃させます。この時点では"crude spiked club"で攻撃します。
        bob.attack();
        
        // 'club'のタイプを"some other type of club"に変更します。
        // HumanAがWeaponへの参照を保持しているため、この変更はbobの武器にも直接反映されます。
        club.setType("some other type of club");
        
        // bobに再度攻撃させます。武器のタイプが変更されているため、新しいタイプで攻撃します。
        bob.attack();
    } // このブロックの終わりで、'bob'と'club'はスコープ外となり破棄されます。

    // 2番目のスコープブロックを開始します。
    // このブロック内で宣言されたオブジェクトは、ブロックの終わりで破棄されます。
    {
        // "crude spiked club"というタイプのWeaponオブジェクト'club'を作成します。
        Weapon club = Weapon("crude spiked club");
        
        // "Jim"という名前のHumanBオブジェクト'jim'を作成します。
        // HumanBはコンストラクターで武器を必須としないため、最初は武器を持っていません。
        HumanB jim("Jim");
        
        // jimに'club'を武器としてセットします。
        // HumanBはWeaponへのポインタを保持するため、後から武器を割り当てることができます。
        jim.setWeapon(club);
        
        // jimに攻撃させます。この時点では"crude spiked club"で攻撃します。
        jim.attack();
        
        // 'club'のタイプを"some other type of club"に変更します。
        // HumanBがWeaponへのポインタを保持しているため、この変更はjimの武器にも直接反映されます。
        club.setType("some other type of club");
        
        // jimに再度攻撃させます。武器のタイプが変更されているため、新しいタイプで攻撃します。
        jim.attack();
    } // このブロックの終わりで、'jim'と'club'はスコープ外となり破棄されます。

    // プログラムが正常に終了したことを示します。
    return 0;
}
