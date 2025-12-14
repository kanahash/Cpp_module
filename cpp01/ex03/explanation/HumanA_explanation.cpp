/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA_explanation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 00:44:09 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/26 18:59:58 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp" // HumanAクラスの定義が含まれるヘッダーファイルをインクルードします。

// HumanAクラスのコンストラクターです。
// HumanAオブジェクトが作成されるときに呼び出されます。
// 引数として名前（std::string name）と武器への参照（Weapon &weapon）を受け取ります。
// 初期化リスト（: name(name), weapon(weapon)）を使って、メンバー変数'name'と'weapon'を初期化しています。
// これにより、コンストラクターの本体が実行される前にメンバー変数が確実に初期化されます。
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    // コンストラクターの本体は空ですが、必要であればここで追加の初期化ロジックを記述できます。
}

// HumanAクラスのデストラクターです。
// HumanAオブジェクトが破棄されるときに呼び出されます。
// ここでは特別なクリーンアップは必要ないため、本体は空です。
HumanA::~HumanA()
{
}

// attackメソッドは、HumanAオブジェクトが攻撃を実行する際に呼び出されます。
// 'void'は、このメソッドが値を返さないことを示します。
// 'const'は、このメソッドがオブジェクトのメンバー変数を変更しないことを保証します。
void HumanA::attack(void) const
{

    // 標準出力ストリーム（std::cout）を使用して、攻撃メッセージを出力します。
    // 'this->name'はHumanAオブジェクトの名前を参照します。
    // 'this->weapon.getType()'は、関連付けられた武器オブジェクトのgetType()メソッドを呼び出して、武器のタイプ（種類）を取得します。
    // 最後に'std::endl'で改行し、出力バッファをフラッシュします。
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

