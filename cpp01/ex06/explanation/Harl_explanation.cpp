/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:46:46 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/24 14:46:49 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp" // Harlクラスの定義をインクルード

// Harlクラスのデフォルトコンストラクタ
Harl::Harl()
{
    // コンストラクタでの特別な初期化は不要
}

// Harlクラスのデストラクタ
Harl::~Harl()
{   
    // デストラクタでの特別なクリーンアップは不要
}

// DEBUGレベルのメッセージを表示するメソッド
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

// INFOレベルのメッセージを表示するメソッド
void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std:: endl;
}

// WARNINGレベルのメッセージを表示するメソッド
void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

// ERRORレベルのメッセージを表示するメソッド
void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// 指定されたログレベルに応じてHarlの不平を表示するメソッド
// この関数は、入力された文字列レベルを対応する数値インデックスに変換し、
// その後、switch文を使用して、指定されたレベルとその上位レベルのすべてのメッセージを表示します。
void Harl::complain(std::string level)
{
    int i = 0; // 配列を走査するためのカウンタ
    int level_index = -1; // 入力されたレベルに対応するインデックス。
                          // 認識されないレベルの場合は初期値-1のまま。

    // 認識するログレベルの文字列配列
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // whileループを使用して、入力された'level'文字列が'levels'配列のどこに一致するかを検索します。
    // 一致が見つかった場合、そのインデックスを'level_index'に格納し、ループを終了します。
    while(i < 4)
    {
        if(level == levels[i])
        {
            level_index = i; // 一致するインデックスを'level_index'に設定
            break;           // 見つかったらループを終了
        }
        i++; // 次の配列要素へ
    }

    // switch文は、'level_index'の値に基づいて異なるコードブロックを実行します。
    // ここでは、各caseの最後に'break'がないことで、「フォールスルー」というC++の特性を利用しています。
    // フォールスルーとは、あるcaseブロックの実行が終了した後、明示的な'break'がない限り、
    // 次のcaseブロックのコードが続けて実行される動作を指します。
    switch(level_index)
    {
        case 0: // 'level_index'が0の場合（"DEBUG"に対応）
            this->debug(); // DEBUGメッセージを表示
            // break文がないため、次のcase 1に処理がフォールスルーします。
        case 1: // 'level_index'が1の場合（"INFO"に対応）、またはcase 0からフォールスルーした場合
            this->info();  // INFOメッセージを表示
            // break文がないため、次のcase 2に処理がフォールスルーします。
        case 2: // 'level_index'が2の場合（"WARNING"に対応）、またはcase 1からフォールスルーした場合
            this->warning(); // WARNINGメッセージを表示
            // break文がないため、次のcase 3に処理がフォールスルーします。
        case 3: // 'level_index'が3の場合（"ERROR"に対応）、またはcase 2からフォールスルーした場合
            this->error();   // ERRORメッセージを表示
            break; // ここでbreak文があるため、switch文の実行が終了します。
                   // これにより、ERRORメッセージの後に他のメッセージが表示されるのを防ぎます。
        default: // 'level_index'がどのcaseにも一致しない場合（例: -1の場合）
            // 認識されない、または無効なログレベルが入力された場合に表示されるメッセージ
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            std::cout << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off." << std::endl;
            break; // defaultケースの実行後、switch文を終了します。
    }
}
