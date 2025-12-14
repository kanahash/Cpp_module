/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:34:09 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/24 01:34:16 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp" // Harlクラスの宣言を含むヘッダーファイルをインクルード

// Harlクラスのデフォルトコンストラクタ
// Harlオブジェクトが作成される際に呼び出されます。
// 現時点では特別な初期化は不要なため、空の実装です。
Harl::Harl()
{
}

// Harlクラスのデストラクタ
// Harlオブジェクトが破棄される際に呼び出されます。
// 現時点では特別なクリーンアップは不要なため、空の実装です。
Harl::~Harl()
{   
}

// debugレベルの不満を表現するプライベートメソッド
// 主に問題診断のための詳細な情報（デバッグメッセージ）を出力します。
void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

// infoレベルの不満を表現するプライベートメソッド
// プログラムの実行状況を追跡するための情報（情報メッセージ）を出力します。
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std:: endl;
}

// warningレベルの不満を表現するプライベートメソッド
// システムにおける潜在的な問題や警告（警告メッセージ）を出力します。
// これは通常、処理を中断するほどではないが、注意が必要な事柄です。
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

// errorレベルの不満を表現するプライベートメソッド
// 回復不能なエラーや重大な問題（エラーメッセージ）が出力されます。
// 通常、手動での介入が必要な状況を示します。
void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Harlの主な公開インターフェース。指定されたレベルに応じて不満を言わせます。
// if/else if/else の連鎖を避け、メンバー関数へのポインタを使用しています。
void Harl::complain(std::string level)
{
    int i; // ループカウンタ

    i = 0; // カウンタを0で初期化
    // Harlが認識する不満レベルの文字列を格納する配列
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Harlクラスのメンバー関数へのポインタを格納する配列
    // 各要素は、上記levels配列の同じインデックスに対応する関数を指します。
    // 例: fptr[0] は debug() 関数を指します。
    void (Harl::*fptr[4])() ={&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    // ループを使って、入力された'level'文字列が認識するレベルのいずれかと一致するかをチェック
    while(i < 4)
    {
        if(level == levels[i]) // 現在のレベルが入力されたレベルと一致する場合
        {
            // (this->*fptr[i])() は、現在のHarlオブジェクト（this）の
            // fptr[i]が指すメンバー関数を呼び出す構文です。
            (this->*fptr[i])();
            return; // 適切な関数が呼び出されたので、complain関数を終了します。
        }
        i++; // 次のレベルへ進む
    }
    // ループが完了してもどのレベルとも一致しなかった場合（無効なレベルが入力された場合）
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
