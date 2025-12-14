/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:36:24 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/02 22:37:01 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrapクラスの設計図（ヘッダーファイル）を読み込みます。
// これにより、ClapTrapクラスのオブジェクトを作成し、そのメンバ関数を使うことができるようになります。
#include "ClapTrap.hpp"

// プログラムの実行が開始される場所です。
int main(void)
{
    // ループ処理に使うための整数型変数です。
    int i;

    // "CL4P-TP"という名前のClapTrapオブジェクトを作成します。
    // 引数付きコンストラクタが呼ばれ、名前が"CL4P-TP"に設定されます。
    ClapTrap clap("CL4P-TP");
    
    // 引数なしでClapTrapオブジェクトを作成します。
    // デフォルトコンストラクタが呼ばれ、名前は"Default"に、他の属性は初期値に設定されます。
    ClapTrap defaultClap;
    
    // --- 攻撃テスト ---
    std::cout << "--- Attack Test ---" << std::endl;
    // `clap`オブジェクトの`attack`関数を呼び出し、"a bad guy"を攻撃対象とします。
    // `attack`関数はエネルギーポイントを1消費します。
    clap.attack("a bad guy");
    // 再び`attack`関数を呼び出します。
    clap.attack("another bad guy");
    std::cout << std::endl;

    // --- ダメージを受けるテスト ---
    std::cout << "--- Take Damage Test ---" << std::endl;
    // `clap`オブジェクトの`takeDamage`関数を呼び出し、5ポイントのダメージを与えます。
    // `hit_points`が5減ります。
    clap.takeDamage(5);
    // `takeDamage`関数を再度呼び出し、10ポイントのダメージを与えます。
    // `hit_points`が0以下になるので、`clap`は「dead」（死んだ）と表示されます。
    clap.takeDamage(10);
    std::cout << std::endl;

    // --- 修復テスト ---
    std::cout << "--- Repair Test ---" << std::endl;
    // `clap`オブジェクトの`beRepaired`関数を呼び出し、5ポイントの修復を試みます。
    // しかし、前のテストで`hit_points`が0になっているため、修復できずエラーメッセージが表示されます。
    clap.beRepaired(5);
    std::cout << std::endl;

    // --- デフォルトClapTrapのテスト ---
    std::cout << "--- Default ClapTrap Test ---" << std::endl;
    // `defaultClap`オブジェクトの各関数をテストします。
    // `attack`関数が実行され、エネルギーが1減ります。
    defaultClap.attack("target");
    // `takeDamage`関数が実行され、ヒットポイントが3減ります。
    defaultClap.takeDamage(3);
    // `beRepaired`関数が実行され、エネルギーが1減り、ヒットポイントが2回復します。
    defaultClap.beRepaired(2);
    std::cout << std::endl;

    // --- エネルギー枯渇テスト ---
    std::cout << "--- Energy Exhaustion Test ---" << std::endl;
    // "RUNNER"という名前の新しいClapTrapオブジェクトを作成します。
    ClapTrap runner("RUNNER");
    i = 0;
    // `runner`はエネルギーポイントを10持っているので、11回目の攻撃はできません。
    // この`while`ループは、エネルギーがなくなるまで攻撃を繰り返すことをシミュレートします。
    while(i < 11)
    {
        runner.attack("a tree");
        i++;
    }
    // エネルギーが0になっているので、`beRepaired`関数は実行できません。
    runner.beRepaired(1);
    std::cout << std::endl;

    // プログラムが正常に終了したことを示します。
    return(0);    
}
