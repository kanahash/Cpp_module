/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap_explanation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:47:05 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:47:07 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "ScavTrap.hpp"ファイルをインクルードしています。
// このファイルには、ScavTrapクラスの設計図（クラス定義）が書かれています。
#include "ScavTrap.hpp"

// デフォルトコンストラクタです。
// `ClapTrap("Scav Default")`という部分で、親クラスであるClapTrapの引数付きコンストラクタを呼び出しています。
// これにより、ScavTrapオブジェクトが作られる前に、親クラスのClapTrapが初期化されます。
// そして、ScavTrap独自の初期値でメンバ変数を上書きしています。
ScavTrap::ScavTrap() : ClapTrap("Scav Default")
{
    this->hit_points = 100;    // ヒットポイントを100に設定
    this->energy_points = 50;  // エネルギーポイントを50に設定
    this->attack_damage = 20;  // アタックダメージを20に設定
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

// デストラクタです。
// オブジェクトが破棄されるときに呼び出されます。
// この関数が呼ばれた後、自動的に親クラスであるClapTrapのデストラクタが呼び出されます。
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor for " << this->name << " called" << std::endl;
}

// コピーコンストラクタです。
// `ClapTrap(other)`という部分で、親クラスのコピーコンストラクタを呼び出しています。
// これにより、親クラスのメンバ変数が正しくコピーされます。
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

// コピー代入演算子です。
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    // 自分自身への代入を防ぐためのチェックです。
    if(this != &other)
    {
        // 親クラスのコピー代入演算子を明示的に呼び出しています。
        // これにより、親クラスのメンバ変数（name, hit_pointsなど）がコピーされます。
        ClapTrap::operator=(other);
    }
        return(*this);
}

// 引数付きコンストラクタです。
// `ClapTrap(name)`という部分で、親クラスの引数付きコンストラクタを呼び出し、名前を渡しています。
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    // 親クラスの初期化が終わった後、ScavTrap独自の初期値でメンバ変数を設定します。
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

// `attack`関数です。これはClapTrapの`attack`関数をオーバーライド（上書き）しています。
// 動作自体は似ていますが、出力されるメッセージが異なります。
void ScavTrap::attack(const std::string& target)
{
    // 攻撃に必要なエネルギーポイントとヒットポイントがあるかチェックします。
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        // ScavTrap独自の攻撃メッセージを出力します。
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage! ScavTrap is ready to fight!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy of hit points left to attack!" << std::endl;
}

// ScavTrap独自の特殊能力である`guardGate`関数です。
// この関数は親クラスのClapTrapには存在しません。
void ScavTrap::guardGate()
{
    // ゲートキーパーモードになったことを示すメッセージを出力します。
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}
