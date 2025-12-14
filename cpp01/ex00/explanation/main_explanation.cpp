/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:16:30 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 00:34:12 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombieクラスの定義（Zombie.hpp）をインクルードします。
                      // これにより、Zombieクラスや、newZombie、randomChump関数が使えるようになります。

int main(void) // プログラムのエントリーポイントであるmain関数です。
{
    // ヒープに割り当てるZombieオブジェクトへのポインタを宣言します。
    // この時点では、まだメモリは割り当てられていません。
    Zombie *new_Zombie; 

    // newZombie関数を呼び出して、ヒープメモリに新しいZombieオブジェクトを作成します。
    // "New Zombie"という名前が付けられ、そのオブジェクトへのポインタがnew_Zombieに代入されます。
    // この行でZombieのコンストラクタが呼ばれ、"New Zombie : created." のようなメッセージが出力されるはずです。
    new_Zombie = newZombie("New Zombie");

    // ヒープ上に作成されたゾンビのannounce()メソッドを呼び出します。
    // これにより、"New Zombie: BraiiiiiiinnnzzzZ..." と表示されます。
    new_Zombie->announce();

    // randomChump関数を呼び出します。
    // この関数内で、"random_Zombie"という名前のZombieオブジェクトがスタックメモリに作成されます。
    // 作成後すぐにannounce()が呼ばれ、"random_Zombie: BraiiiiiiinnnzzzZ..." と表示されます。
    // randomChump関数が終了すると同時に、スタック上の"random_Zombie"は自動的に破棄され、
    // デストラクタが呼ばれて "random_Zombie : destroyed." と表示されるはずです。
    randomChump("random_Zombie");

    // newZombieでヒープに割り当てたメモリを手動で解放します。
    // これにより、new_Zombieが指していたZombieオブジェクトのデストラクタが呼ばれ、
    // "New Zombie : destroyed." と表示されます。
    // ヒープメモリを使った場合、deleteを呼び忘れるとメモリリークの原因となります。
    delete(new_Zombie);

    // プログラムが正常終了したことを示すために0を返します。
    return(0);
}
