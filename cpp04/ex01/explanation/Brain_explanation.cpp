/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain_explanation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:24:01 by kanahash          #+#    #+#             */
/*   Updated: 2025/08/06 16:24:05 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp" // Brain.hppヘッダーファイルをインクルードします。
                       // このファイルには、Brainクラスの宣言が含まれています。

// デフォルトコンストラクタ
// Brainクラスの新しいオブジェクトが作成されたときに自動的に呼び出されます。
Brain::Brain()
{
    // オブジェクトが作成されたことを示すメッセージを出力します。
    std::cout << "Brain default constructor called" << std::endl;
}

// デストラクタ
// Brainオブジェクトが破棄されるときに自動的に呼び出されます。
// メモリの解放など、オブジェクトの後片付け処理をここで行います。
Brain::~Brain()
{
    // オブジェクトが破棄されたことを示すメッセージを出力します。
    std::cout << "Brain destructor called" << std::endl;
}

// コピーコンストラクタ
// 既存のBrainオブジェクトから新しいBrainオブジェクトを作成するときに呼び出されます。
// 例: Brain newBrain = oldBrain;
Brain::Brain(const Brain &copy)
{
    int i; // ループ用の整数型変数iを宣言します。

    i = 0; // iを0で初期化します。
    // コピーコンストラクタが呼び出されたことを示すメッセージを出力します。
    std::cout << "Brain copy constructor called" << std::endl;
    // ループを使って、コピー元のアイデア配列(copy.ideas)から
    // 新しいオブジェクトのアイデア配列(this->ideas)に要素を100個すべてコピーします。
    while(i < 100)
    {
        this->ideas[i] = copy.ideas[i];
        i++;
    }
}

// コピー代入演算子
// 既存のBrainオブジェクトに別のBrainオブジェクトの内容を代入するときに呼び出されます。
// 例: existingBrain = anotherBrain;
Brain& Brain::operator=(const Brain &src)
{
    int i; // ループ用の整数型変数iを宣言します。

    i = 0; // iを0で初期化します。
    // コピー代入演算子が呼び出されたことを示すメッセージを出力します。
    std::cout << "Brain copy assignment operator called" << std::endl;
    
    // 自己代入のチェック
    // オブジェクト自身に代入しようとしていないか確認します。
    // 例: myBrain = myBrain;
    // もし同じオブジェクトであれば、余計な処理をせずにそのまま返します。
    if(this != &src)
    {
        // ループを使って、代入元のアイデア配列(src.ideas)から
        // 現在のオブジェクトのアイデア配列(this->ideas)に要素を100個すべてコピーします。
        while(i < 100)
        {
            this->ideas[i] = src.ideas[i];
            i++;
        }
    }
    // 代入されたオブジェクト自身の参照を返します。
    // これにより、連鎖的な代入(例: a = b = c;)が可能になります。
    return(*this);
}
