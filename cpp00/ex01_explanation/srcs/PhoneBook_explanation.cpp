/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_explanation.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 04:13:43 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:08:41 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp" // PhoneBookクラスの定義が書かれたヘッダーファイルを読み込みます。

// プログラムが最初に実行される場所です。
int main(void)
{
    // PhoneBookクラスのオブジェクト（実体）を作成します。
    // これで電話帳の機能を使う準備ができました。
    PhoneBook phonebook;
    // ユーザーからの入力を受け取るための文字列変数です。
    std::string input;

    // 無限ループです。ユーザーが"EXIT"と入力するか、入力エラーが発生するまで続きます。
    while(1)
    {
        // ユーザーから一行の入力を読み込みます。
        // std::getline(std::cin, input) は、入力ストリーム(std::cin)から一行を読み込み、
        // input変数に格納します。読み込みが成功すればtrueを返します。
        // std::cin.eof() は、入力の終端（EOF、例えばCtrl+DやCtrl+Zなど）に達したかを確認します。
        // もし読み込みに失敗するか、EOFに達したらループを抜けます。
        if(!std::getline(std::cin, input) || std::cin.eof())
            break; // ループを抜けます。

        // もし入力が"ADD"だったら
        if(input == "ADD")
        {
            // phonebookオブジェクトのaddContact関数を呼び出します。
            // 連絡先の追加に失敗したら（例えば、入力エラーがあったら）、ループを抜けます。
            if(!phonebook.addContact())
                break; // ループを抜けます。
        }
        // もし入力が"SEARCH"だったら
        else if(input == "SEARCH")
        {
            // phonebookオブジェクトのsearchContact関数を呼び出します。
            // 連絡先の検索に失敗したら（例えば、入力エラーがあったら）、ループを抜けます。
            if(!phonebook.searchContact())
                break; // ループを抜けます。
        }
        // もし入力が"EXIT"だったら
        else if(input == "EXIT")
            break; // ループを抜けます。
        // 他の無効な入力は特に何もせず、次のループで再度入力を促します。
    }
    // ループを抜けた後、画面に改行を出力します。
    std::cout << std::endl;
    // プログラムが正常終了したことを示します。
    return(0);
}
