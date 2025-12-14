/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap_explanation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:53:10 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:53:12 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "FragTrap.hpp"をインクルードして、FragTrapクラスの設計図を読み込みます。
#include "FragTrap.hpp"

// デフォルトコンストラクタです。引数なしでFragTrapオブジェクトが作成されるときに呼ばれます。
// `ClapTrap("Frag Default")`という部分で、親クラスであるClapTrapのコンストラクタを呼び出し、
// 親クラスの初期化を先に行っています。
FragTrap::FragTrap() : ClapTrap("Frag Default")
{
    // 親クラスの初期化後、FragTrap独自の初期値でメンバ変数を設定します。
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    // コンストラクタが呼ばれたことを示すメッセージを出力します。
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

// デストラクタです。FragTrapオブジェクトが破棄されるときに呼ばれます。
// この関数が実行された後、自動的に親クラスのデストラクタが呼ばれます。
FragTrap::~FragTrap()
{
    // デストラクタが呼ばれたことを示すメッセージを出力します。
    std::cout << "FragTrap Destructor for " << this->name << " called" << std::endl;  
}

// 引数付きコンストラクタです。名前を引数としてFragTrapオブジェクトを作成する際に呼ばれます。
// `ClapTrap(name)`で親クラスのコンストラクタを呼び出し、名前を初期化します。
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    // 親クラスの初期化後、FragTrap独自の初期値を設定します。
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    // コンストラクタが呼ばれたことを示すメッセージを出力します。
    std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

// コピーコンストラクタです。既存のFragTrapオブジェクトから新しいオブジェクトを作成する際に呼ばれます。
// `ClapTrap(other)`で親クラスのコピーコンストラクタを呼び出し、親のメンバをコピーします。
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    // コピーコンストラクタが呼ばれたことを示すメッセージを出力します。
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

// コピー代入演算子です。既存のFragTrapオブジェクトに別のオブジェクトを代入する際に呼ばれます。
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    // 代入演算子が呼ばれたことを示すメッセージを出力します。
    std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
    // 自己代入（自分自身への代入）を防ぎます。
    if(this != &other)
        // 親クラスのコピー代入演算子を呼び出し、親のメンバをコピーします。
        ClapTrap::operator=(other);
    // 代入後のオブジェクト自身を返します。
    return(*this);
}

// FragTrap独自のメンバ関数です。
// 親クラスにはない、このクラス特有の機能です。
void FragTrap::highFivesGuys()
{
    [cite_start]// ポジティブなハイタッチのリクエストを標準出力に表示します [cite: 143, 144]。
    std::cout << "FragTrap " << this->name << " wants a high five!" << std::endl;
}
