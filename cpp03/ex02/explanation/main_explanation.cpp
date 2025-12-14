/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:53:55 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:54:06 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "FragTrap.hpp"をインクルードして、FragTrapクラスの設計図を読み込みます。
// これにより、main関数でFragTrapオブジェクトを作成し、そのメンバ関数を呼び出せるようになります。
#include "FragTrap.hpp"

// プログラムの実行が開始されるメイン関数です。
int main(void)
{
    // --- FragTrapオブジェクトの作成 ---
    std::cout << "--- Creating a FragTrap named FRAG-1 ---" << std::endl;
    // "FRAG-1"という名前のFragTrapオブジェクトを作成します。
    // このとき、まず親クラスであるClapTrapのコンストラクタが呼ばれ、
    // 次にFragTrapのコンストラクタが呼ばれる「コンストラクタの連鎖」が起こります。
    FragTrap frag1("FRAG-1");
    std::cout << std::endl;

    // --- 継承された関数のテスト ---
    std::cout << "--- Testing inherited functions ---" << std::endl;
    // `attack`関数を呼び出します。この関数はClapTrapから継承されたものです。
    [cite_start]// FragTrapの攻撃力（attack_damage）は30なので、その値がメッセージに表示されます [cite: 141]。
    frag1.attack("enemy Robot");
    // `takeDamage`関数を呼び出します。これもClapTrapから継承されたものです。
    frag1.takeDamage(30);
    // `beRepaired`関数を呼び出します。これもClapTrapから継承されたものです。
    [cite_start]// 修復にはエネルギーポイントを1消費します [cite: 88]。
    frag1.beRepaired(20);
    std::cout << std::endl;

    // --- FragTrap独自の関数のテスト ---
    std::cout << "--- Testing FragTrap's unique function ---" << std::endl;
    // `highFivesGuys`関数を呼び出します。
    [cite_start]// この関数はFragTrap独自の特殊能力であり、親クラスであるClapTrapにはありません [cite: 142, 143]。
    [cite_start]// ポジティブなハイタッチのリクエストを標準出力に表示します [cite: 144]。
    frag1.highFivesGuys();
    std::cout << std::endl;

    // --- コピーコンストラクタと代入演算子のテスト ---
    std::cout << "--- Testing copy constructor and assignment operator ---" << std::endl;
    // `frag1`オブジェクトをコピーして、`frag2`という新しいオブジェクトを作成します。
    // この行でコピーコンストラクタが呼び出されます。
    FragTrap frag2 = frag1;
    // "FRAG-3"という名前の`frag3`オブジェクトを作成します。
    FragTrap frag3("FRAG-3");
    // 既存の`frag3`に`frag1`の内容を代入します。
    // この行でコピー代入演算子が呼び出されます。
    frag3 = frag1;
    std::cout << std::endl;

    // --- プログラム終了 ---
    std::cout << "--- Program ending, destructor will be called ---" << std::endl;
    // main関数の終了時に、作成されたオブジェクトが破棄されます。
    // このとき、「デストラクタの連鎖」が起こり、
    [cite_start]// まず子クラスのFragTrapのデストラクタが、次に親クラスのClapTrapのデストラクタが呼ばれます [cite: 136]。

    return(0);    
}
