/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_explanation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:45:07 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:45:12 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "ClapTrap.hpp"ファイルをインクルードしています。
// このファイルには、ClapTrapクラスの設計図（メンバ変数や関数の定義）が書かれています。
// この.cppファイルでは、その設計図に基づいて各関数の具体的な処理を実装します。
#include "ClapTrap.hpp"

// デフォルトコンストラクタです。
// 引数なしでClapTrapのインスタンス（オブジェクト）が作られたときに自動的に呼び出されます。
// `ClapTrap clap;` のように使います。
// メンバ変数を初期化リストという形式で初期化しています。
// この形式は、コンストラクタの本体に入る前に初期化が完了するため、効率が良いとされています。
ClapTrap::ClapTrap()
    :name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    // コンストラクタが呼び出されたことを示すメッセージを標準出力に表示します。
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// デストラクタです。
// ClapTrapのインスタンスが破棄される（メモリから解放される）ときに自動的に呼び出されます。
// 例えば、インスタンスが定義されたスコープ（{ }で囲まれた範囲）を抜けたときなどに呼び出されます。
ClapTrap::~ClapTrap()
{
    // デストラクタが呼び出されたことを示すメッセージと、インスタンスの名前を標準出力に表示します。
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

// コピーコンストラクタです。
// 既存のClapTrapインスタンスを元に、新しいインスタンスを作成する際に自動的に呼び出されます。
// `ClapTrap new_clap = old_clap;` のように使います。
// `other`は、コピー元のインスタンスを参照しています。
ClapTrap::ClapTrap(const ClapTrap& other)
    :name(other.name), hit_points(other.hit_points), energy_points(other.energy_points),attack_damage(other.attack_damage)
{
    // コピーコンストラクタが呼び出されたことを示すメッセージを表示します。
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

// コピー代入演算子です。
// 既に存在するClapTrapインスタンスに、別のClapTrapインスタンスを代入する際に自動的に呼び出されます。
// `new_clap = old_clap;` のように使います。
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    // コピー代入演算子が呼び出されたことを示すメッセージを表示します。
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    // 自分自身への代入を防ぐためのチェックです。
    // `this`は現在のインスタンスを指すポインタ、`&other`は代入元のインスタンスのアドレスです。
    if(this != &other)
    {
        // 代入元のインスタンス（`other`）のメンバ変数の値を、
        // 現在のインスタンス（`this`）のメンバ変数にコピーします。
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    // 代入されたインスタンス自身を返します。
    return(*this);
}

// 引数付きコンストラクタです。
// std::string型の名前を引数としてClapTrapのインスタンスを作成する際に呼び出されます。
// `ClapTrap clap("Player1");` のように使います。
ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    // コンストラクタが呼び出されたことと、インスタンスの名前を表示します。
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

// `attack`メンバ関数です。
// `const std::string& target`という引数で、攻撃対象の名前を受け取ります。
void ClapTrap::attack(const std::string& target)
{
    // 攻撃に必要なエネルギーポイントとヒットポイントが残っているかを確認します。
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        // 攻撃するたびに、エネルギーポイントを1減らします。
        this->energy_points--;
        // 攻撃が行われたことを示すメッセージと、与えるダメージ量を表示します。
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else
        // 攻撃するためのポイントが不足している場合、その旨を表示します。
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to attack!" << std::endl;
}

// `takeDamage`メンバ関数です。
// `unsigned int amount`という引数で、受けるダメージ量を受け取ります。
void ClapTrap::takeDamage(unsigned int amount)
{
    // 受けるダメージ量が現在のヒットポイントよりも少ないかを確認します。
    if(this->hit_points > amount)
    {
        // ダメージ量分、ヒットポイントを減らします。
        this->hit_points -= amount;
        // ダメージを受けたことを示すメッセージを表示します。
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl; 
    }
    else
    {
        // ダメージ量が現在のヒットポイント以上の場合、ヒットポイントを0にします。
        this->hit_points = 0;
        // 死亡したことを示すメッセージを表示します。
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and is now dead!" << std::endl;
    }
}

// `beRepaired`メンバ関数です。
// `unsigned int amount`という引数で、回復量を受け取ります。
void ClapTrap::beRepaired(unsigned int amount)
{
    // 修復に必要なエネルギーポイントとヒットポイントが残っているかを確認します。
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        // 修復するたびに、エネルギーポイントを1減らします。
        this->energy_points--;
        // 回復量分、ヒットポイントを増やします。
        this->hit_points += amount;
        // 修復が完了したことを示すメッセージを表示します。
        std::cout <<"ClapTrap " << this->name << " repairs itself for " <<amount << " hit points!" << std::endl;
    }
    else
        // 修復するためのポイントが不足している場合、その旨を表示します。
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to repair itself!" << std::endl;
}
