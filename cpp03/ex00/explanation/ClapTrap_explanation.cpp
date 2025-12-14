/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_explanation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:34:38 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:36:18 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp" // ClapTrapクラスの宣言（設計図）が書かれたヘッダーファイルを読み込む

// デフォルトコンストラクタ
// 引数なしでClapTrapオブジェクトが作られたときに呼ばれる関数
// nameを"Default"、hit_pointsを10、energy_pointsを10、attack_damageを0で初期化する
ClapTrap::ClapTrap()
    :name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    // コンソールにメッセージを出力する
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// デストラクタ
// ClapTrapオブジェクトが破棄される（メモリから解放される）ときに呼ばれる関数
// 例えば、スコープを抜けたときなどに自動的に呼び出される
ClapTrap::~ClapTrap()
{
    // オブジェクトの名前と一緒にメッセージを出力する
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

// コピーコンストラクタ
// 既存のClapTrapオブジェクトをコピーして、新しいオブジェクトを作成するときに呼ばれる関数
// 例: ClapTrap newTrap = oldTrap;
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    // 後述の代入演算子を使って、otherオブジェクトの全ての属性をthis（新しいオブジェクト）にコピーする
    *this = other;
}

// コピー代入演算子
// 既存のClapTrapオブジェクトに、別のClapTrapオブジェクトを代入するときに呼ばれる関数
// 例: anotherTrap = oldTrap;
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    // 自己代入（自分自身への代入）を防ぐためのチェック
    if(this != &other)
    {
        // otherオブジェクトの各属性の値を、this（現在のオブジェクト）の属性にコピーする
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    // 代入後のオブジェクト自身を返す
    return(*this);
}

// 引数付きコンストラクタ
// `std::string`型の名前を引数に受け取ってClapTrapオブジェクトを作成するときに呼ばれる関数
// 例: ClapTrap myTrap("Player1");
ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    // オブジェクトの名前と一緒にメッセージを出力する
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

// 攻撃関数
// 引数で指定された`target`（攻撃対象）に攻撃する
void ClapTrap::attack(const std::string& target)
{
    // エネルギーポイントとヒットポイントが残っているかチェック
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        // 攻撃にはエネルギーポイントを1消費する
        this->energy_points--;
        // 攻撃したことと、与えるダメージ量をメッセージで出力する
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else
        // エネルギーまたはヒットポイントが不足している場合のメッセージを出力する
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to attack!" << std::endl;
}

// ダメージを受ける関数
// 引数`amount`分のダメージを受ける
void ClapTrap::takeDamage(unsigned int amount)
{
    // 受けるダメージが現在のヒットポイントよりも少ないかチェック
    if(this->hit_points > amount)
    {
        // ヒットポイントからダメージ量を減らす
        this->hit_points -= amount;
        // 受けたダメージ量をメッセージで出力する
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl; 
    }
    else
    {
        // ダメージを受けてヒットポイントが0以下になる場合
        this->hit_points = 0; // ヒットポイントを0にする
        // ダメージを受けた結果、倒れたことを示すメッセージを出力する
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and is now dead!" << std::endl;
    }
}

// 修復関数
// 引数`amount`分のヒットポイントを回復する
void ClapTrap::beRepaired(unsigned int amount)
{
    // エネルギーポイントとヒットポイントが残っているかチェック
    if(this->energy_points > 0 && this->hit_points > 0)
    {
        // 修復にはエネルギーポイントを1消費する
        this->energy_points--;
        // ヒットポイントを回復量分増やす
        this->hit_points += amount;
        // 回復したことをメッセージで出力する
        std::cout <<"ClapTrap " << this->name << " repairs itself for " <<amount << " hit points!" << std::endl;
    }
    else
        // エネルギーまたはヒットポイントが不足している場合のメッセージを出力する
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to repair itself!" << std::endl;
}
