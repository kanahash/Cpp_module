/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie_explanation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:45:20 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 22:45:25 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombieクラスの定義を含むヘッダーファイルをインクルードします。

// デフォルトコンストラクタ
// Zombieオブジェクトが引数なしで作成されたときに呼び出されます。
// このコンストラクタでは特に初期化を行う必要がないため、空になっています。
Zombie::Zombie(void)
{
}

// 引数付きコンストラクタ
// std::string型のnameを引数にとり、Zombieオブジェクトの名前を初期化します。
Zombie::Zombie(std::string name)
{
	this->name = name; // 引数で渡されたnameを、メンバ変数nameに代入します。
}

// デストラクタ
// Zombieオブジェクトが破棄されるときに呼び出されます。
// 現在のところ、特別なクリーンアップ処理は必要ないため、空になっています。
Zombie::~Zombie()
{
}

// announceメソッド
// Zombieが「BraiiiiiiinnnzzzZ...」と叫ぶ動作をシミュレートします。
void Zombie::announce(void)
{
	// オブジェクトのnameメンバ変数と決められた文字列を標準出力に表示します。
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
