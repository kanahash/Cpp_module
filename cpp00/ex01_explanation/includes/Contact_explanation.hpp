/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_explanation.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:06:07 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:06:16 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// インクルードガード（Include Guard）と呼ばれるものです。
// これにより、このヘッダーファイルが複数回含まれることによるエラーを防ぎます。
// 例えば、他のファイルがこのContact.hppを2回インクルードしようとしても、
// 1回目ですでに定義されているため、2回目以降は無視されます。
#ifndef CONTACT_HPP // もしCONTACT_HPPがまだ定義されていなければ
#define CONTACT_HPP // CONTACT_HPPを定義する

// 必要なヘッダーファイルを読み込みます。
// <iostream>は、標準入出力（画面への表示など）を行うために必要ですが、
// このヘッダーファイル自体では直接使われていません。
// おそらく、このContactクラスを使う他のファイル（例えば、PhoneBookクラスの実装ファイルなど）で
// 必要になるため、習慣的に含められているか、過去にここで使われていた可能性があります。
#include<iostream>
// <string>は、文字列を扱うためのstd::stringクラスを使用するために必要です。
// このクラスは、可変長の文字列を安全に扱うのに便利です。
#include<string>

// Contactクラスの定義を開始します。
// このクラスは、電話帳の1件の連絡先（コンタクト）の情報を表します。
class Contact
{
	// private: の下に宣言されたメンバー（変数や関数）は、
	// そのクラスの内部からのみアクセスできます。
	// クラスの外からは直接アクセスできません。
	// これらは「属性」や「データメンバー」と呼ばれ、連絡先の詳細情報を保持します。
	private:
		// 連絡先の「名」（ファーストネーム）を格納する文字列。
		std::string first_name;
		// 連絡先の「姓」（ラストネーム）を格納する文字列。
		std::string last_name;
		// 連絡先の「ニックネーム」を格納する文字列。
		std::string nickname;
		// 連絡先の「電話番号」を格納する文字列。
		std::string phone_number;
		// 連絡先の「最も暗い秘密」を格納する文字列。（このプロジェクト特有の項目）
		std::string darkest_secret;

	// public: の下に宣言されたメンバーは、クラスの外からでもアクセスできます。
	// これらの関数が、Contactクラスの「インターフェース」（外部から使える機能）となります。
	public:
		// Contactクラスのコンストラクタです。
		// Contactオブジェクトが作成されるときに自動的に呼び出され、
		// メンバー変数の初期化などを行います。
		Contact();
		// Contactクラスのデストラクタです。
		// Contactオブジェクトが破棄されるときに自動的に呼び出され、
		// 割り当てられたリソースの解放などを行います。
		// このクラスではstd::stringが自動でメモリ管理をするため、通常は空の実装になります。
		~Contact();

		// 以下の5つの関数は「ゲッター」（Getter）と呼ばれます。
		// privateなメンバー変数の値を、外部から安全に「取得」するために使われます。
		// const std::string& の「&」は参照渡しを意味し、文字列のコピーを防いで効率的です。
		// 「const」は、この関数がメンバー変数の値を変更しないことを保証します。
		// 最後の「const」は、この関数が定数オブジェクトに対しても呼び出せることを意味します。

		// 名（ファーストネーム）を取得する関数。
		const std::string& getFirstName() const;
		// 姓（ラストネーム）を取得する関数。
		const std::string& getLastName() const;
		// ニックネームを取得する関数。
		const std::string& getNickName() const;
		// 電話番号を取得する関数。
		const std::string& getPhoneNumber() const;
		// 最も暗い秘密を取得する関数。
		const std::string& getDarkestSecret() const;

		// 以下の5つの関数は「セッター」（Setter）と呼ばれます。
		// privateなメンバー変数の値を、外部から安全に「設定」するために使われます。
		// const std::string& name の「&」は参照渡しで、引数のコピーを防ぎます。
		// 「const」は、引数の文字列を変更しないことを保証します。

		// 名（ファーストネーム）を設定する関数。
		void setFirstName(const std::string& name);
		// 姓（ラストネーム）を設定する関数。
		void setLastName(const std::string& name);
		// ニックネームを設定する関数。
		void setNickName(const std::string& name);
		// 電話番号を設定する関数。
		void setPhoneNumber(const std::string& name);
		// 最も暗い秘密を設定する関数。
		void setDarkestSecret(const std::string& name);
};

#endif // CONTACT_HPPの終わり
