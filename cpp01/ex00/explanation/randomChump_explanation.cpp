/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump_explanation.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:32:44 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/16 00:34:07 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Zombieクラスの定義（Zombie.hpp）を読み込みます。
                      // これでZombieクラスの作り方を知り、使えるようになります。

// randomChump関数は、一時的に現れて自己紹介するゾンビを作ります。
// std::string name: 作るゾンビに与える名前です。
void randomChump(std::string name)
{
    // ここがポイント！ Zombieオブジェクトを「一時的な棚」（スタックメモリ）に作ります。
    // Zombie randomChump(name); は、こんな意味です:
    // 1. "randomChump"という名前のZombie用の場所を「一時的な棚」に用意します。
    // 2. その場所に、'name'（例えば"random_Zombie"）という名前の新しいZombieを作ります。
    //    この時、Zombieの「生まれたときの処理」（コンストラクタ）が動いて、
    //    「random_Zombie : created.」のようなメッセージが出るはずです。
    //
    // このゾンビは、この関数が終わると同時に自動的に「消滅」します。
    // プログラマーが何か特別なことをしなくても、勝手に片付くので便利です。
    Zombie randomChump(name); 
    
    // 作ったゾンビに「自己紹介して！」と命令します。
    // これで「random_Zombie: BraiiiiiiinnnzzzZ...」と表示されます。
    randomChump.announce(); 

    // ここでrandomChump関数が終わりです。
    // 関数が終わると同時に、上の行で作った「randomChump」という名前のゾンビは
    // 「一時的な棚」から自動的に取り除かれ、「消滅」します。
    // その際、Zombieの「消えるときの処理」（デストラクタ）が動いて、
    // 「random_Zombie : destroyed.」のようなメッセージが出るはずです。
    // なので、このゾンビは関数の外からはもう使えません。
}
