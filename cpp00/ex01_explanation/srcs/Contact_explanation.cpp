/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_explanation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 04:13:04 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:08:21 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contactクラスの定義が書かれたヘッダーファイルを読み込みます。
#include "Contact.hpp"

// Contactクラスのコンストラクタです。
// Contactオブジェクトが作られるときに自動的に実行されます。
// ここでメンバー変数（first_nameなど）を空文字列で初期化しています。
// これは、未定義の値が入るのを防ぎ、安全な状態から始めるために重要です。
Contact::Contact():
	first_name(""),    // 名を空文字列で初期化
	last_name(""),     // 姓を空文字列で初期化
	nickname(""),      // ニックネームを空文字列で初期化
	phone_number(""),  // 電話番号を空文字列で初期化
	darkest_secret("") // 最も暗い秘密を空文字列で初期化
	{
        // コンストラクタの中で特別な処理は今のところありません。
	}

// Contactクラスのデストラクタです。
// Contactオブジェクトが破棄されるときに自動的に実行されます。
// std::stringは自動でメモリ管理を行うため、ここで特別な解放処理は不要です。
Contact::~Contact()
{
    // デストラクタの中で特別な処理は今のところありません。
}

// -------------------- ゲッター関数 (Getter Functions) --------------------
// これらの関数は、privateなメンバー変数の値を取得するために使われます。
// 'const std::string&' は、文字列のコピーを作らずに参照を返すことで、効率を良くします。
// 最後の 'const' は、この関数がオブジェクトの状態（メンバー変数の値）を変更しないことを保証します。

// 名（ファーストネーム）を取得する関数。
const std::string& Contact::getFirstName() const
{
	return(first_name); // first_nameの参照を返します。
}

// 姓（ラストネーム）を取得する関数。
const std::string& Contact::getLastName() const
{
	return(last_name); // last_nameの参照を返します。
}

// ニックネームを取得する関数。
const std::string& Contact::getNickName() const
{
	return(nickname); // nicknameの参照を返します。
}

// 電話番号を取得する関数。
const std::string& Contact::getPhoneNumber() const
{
	return(phone_number); // phone_numberの参照を返します。
}

// 最も暗い秘密を取得する関数。
const std::string& Contact::getDarkestSecret() const
{
	return(darkest_secret); // darkest_secretの参照を返します。
}

// -------------------- セッター関数 (Setter Functions) --------------------
// これらの関数は、privateなメンバー変数の値を設定するために使われます。
// 'const std::string& name' は、引数として渡された文字列のコピーを作らずに
// 参照を受け取ることで効率を良くし、引数が変更されないことを保証します。

// 名（ファーストネーム）を設定する関数。
void Contact::setFirstName(const std::string& name)
{
	first_name = name; // 受け取ったnameをfirst_nameに代入します。
}

// 姓（ラストネーム）を設定する関数。
void Contact::setLastName(const std::string& name)
{
	last_name = name; // 受け取ったnameをlast_nameに代入します。
}

// ニックネームを設定する関数。
void Contact::setNickName(const std::string& name)
{
	nickname = name; // 受け取ったnameをnicknameに代入します。
}

// 電話番号を設定する関数。
void Contact::setPhoneNumber(const std::string& name)
{
	phone_number = name; // 受け取ったnameをphone_numberに代入します。
}

// 最も暗い秘密を設定する関数。
void Contact::setDarkestSecret(const std::string& name)
{
	darkest_secret = name; // 受け取ったnameをdarkest_secretに代入します。
}
