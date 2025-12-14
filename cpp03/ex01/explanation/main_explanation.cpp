/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:46:21 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:46:24 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "ScavTrap.hpp"ファイルをインクルードします。
// ここには、ScavTrapクラスの設計図（クラス定義）が書かれています。
#include "ScavTrap.hpp"

// プログラムの実行が開始されるメイン関数です。
int main(void)
{
    // --- ScavTrapオブジェクトの作成 ---
    std::cout << "--- Creating a ScavTrap named SCV-1 ---" << std::endl;
    // "SCV-1"という名前のScavTrapオブジェクトを作成します。
    // このとき、まず親クラスであるClapTrapのコンストラクタが呼ばれ、
    // 次にScavTrapのコンストラクタが呼ばれる「コンストラクタの連鎖」が起こります。
    ScavTrap scav1("SCV-1");
    std::cout << std::endl;

    // --- 継承された関数とオーバーライドされた関数のテスト ---
    std::cout << "--- Testing inherited and overridden functions ---" << std::endl;
    // `attack`関数を呼び出します。
    // ScavTrapクラスでオーバーライドされているため、ClapTrapとは異なるメッセージが表示されます。
    scav1.attack("a Robot");
    // `takeDamage`関数を呼び出します。
    // この関数はClapTrapから継承されたもので、ScavTrapでも同じ動作をします。
    scav1.takeDamage(10);
    // `beRepaired`関数を呼び出します。
    // この関数もClapTrapから継承されたものです。
    scav1.beRepaired(5);
    std::cout << std::endl;

    // --- コピーコンストラクタと代入演算子のテスト ---
    std::cout << "--- Testing copy constructor and assignment operator ---" << std::endl;
    // `scav1`オブジェクトをコピーして、`scav2`という新しいオブジェクトを作成します。
    // この行でコピーコンストラクタが呼び出されます。
    ScavTrap scav2 = scav1;
    // "SCV-3"という名前の`scav3`オブジェクトを作成します。
    ScavTrap scav3("SCV-3");
    // 既存の`scav3`に`scav1`の内容を代入します。
    // この行でコピー代入演算子が呼び出されます。
    scav3 = scav1;
    std::cout << std::endl;

    // --- プログラム終了 ---
    std::cout << "--- Program ending, destructor will be called ---" << std::endl;
    // main関数が終了すると、作成したオブジェクトが破棄されます。
    // このとき、「デストラクタの連鎖」が起こり、
    // まず子クラスのScavTrapのデストラクタが、次に親クラスのClapTrapのデストラクタが呼ばれます。

    return(0);    
}
