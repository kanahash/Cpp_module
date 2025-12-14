/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB_explanation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 00:44:59 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/17 00:45:06 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp" // HumanBクラスの定義が含まれるヘッダーファイルをインクルードします。

// HumanBクラスのコンストラクターです。
// HumanBオブジェクトが作成されるときに呼び出されます。
// 引数として名前（std::string name）を受け取ります。
// 初期化リスト（: name(name), weapon(NULL)）を使って、メンバー変数'name'を初期化し、
// 'weapon'ポインタをNULL（nullptr）で初期化しています。
// これは、HumanBが最初から武器を持っているとは限らないため、ポインタを安全な状態にするためです。
HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    // コンストラクターの本体は空ですが、必要であればここで追加の初期化ロジックを記述できます。
}

// HumanBクラスのデストラクターです。
// HumanBオブジェクトが破棄されるときに呼び出されます。
// ここでは特別なクリーンアップは必要ないため、本体は空です。
HumanB::~HumanB()
{
}

// attackメソッドは、HumanBオブジェクトが攻撃を実行する際に呼び出されます。
// 'void'は、このメソッドが値を返さないことを示します。
// 'const'は、このメソッドがオブジェクトのメンバー変数を変更しないことを保証します。
void HumanB::attack(void) const
{
    // 武器ポインタ'weapon'がNULLでない（つまり、武器がセットされている）かを確認します。
    if(this->weapon)
        // 武器がある場合、標準出力ストリーム（std::cout）を使用して、攻撃メッセージを出力します。
        // 'this->name'はHumanBオブジェクトの名前を参照します。
        // 'this->weapon->getType()'は、武器ポインタが指すWeaponオブジェクトのgetType()メソッドを呼び出して、武器のタイプを取得します。
        // ポインタなので、メンバーアクセスには'.'ではなく'->'を使用します。
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        // 武器がない場合、標準出力ストリーム（std::cout）を使用して、武器がないことを示すメッセージを出力します。
        std::cout << this->name << "don't have a weapon" << std::endl;
}

// setWeaponメソッドは、HumanBに武器をセットするために使用されます。
// 引数として、セットするWeaponオブジェクトへの参照（Weapon& weapon）を受け取ります。
void HumanB::setWeapon(Weapon& weapon)
{
    // 受け取ったWeaponオブジェクトのアドレスを、メンバー変数'weapon'ポインタに代入します。
    // これにより、HumanBはこの特定のWeaponオブジェクトを参照するようになります。
    this->weapon = &weapon;
}
