/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 04:14:22 by kanahash          #+#    #+#             */
/*   Updated: 2025/12/14 22:08:32 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBookクラスの定義が書かれたヘッダーファイルを読み込みます。
#include "PhoneBook.hpp"
// 以下のヘッダーはPhoneBook.hppで既にインクルードされていますが、
// .cppファイルで明示的にインクルードしても問題ありません（冗長になるだけです）。
// #include <string>
// #include <iomanip>
// #include <sstream>
// エラー出力に使う std::cerr を使うために必要です。
#include <iostream>


// PhoneBookクラスのコンストラクタです。
// PhoneBookオブジェクトが作られるときに自動的に実行されます。
// ここでメンバー変数を初期化します。
// index を -1 に、num_contacts (登録されている連絡先の数) を 0 に初期化しています。
PhoneBook::PhoneBook():
	index(-1), // 次に連絡先が追加される位置（まだ使われていないので-1）
	num_contacts(0) // 登録済みの連絡先はまだ0件
{
    // コンストラクタの中で特別な処理は今のところありません。
}

// PhoneBookクラスのデストラクタです。
// PhoneBookオブジェクトが破棄されるときに自動的に実行されます。
// 動的に確保したメモリなどがあればここで解放しますが、このプログラムにはありません。
PhoneBook::~PhoneBook()
{
    // デストラクタの中で特別な処理は今のところありません。
}

// -------------------- 連絡先表示 (printContact) 関連 --------------------

// 文字列を整形するためのヘルパー関数です。
// 表示の際に文字列が10文字を超える場合に、9文字まで表示して最後に"."を付けます。
// 例: "HelloWorld" -> "HelloWorl."
std::string resize_str(const std::string& str)
{
	// もし文字列の長さが10文字より大きければ
	if(str.length() > 10)
		// 最初の9文字に"."を加えて返します。
		return(str.substr(0, 9) + ".");
	// そうでなければ、文字列をそのまま返します。
	return(str);
} 

// 電話帳に登録されている連絡先の一覧（簡略版）を表示する関数です。
void PhoneBook::printContactlist()
{
	int i; // ループ用のカウンター変数

	// ヘッダー（見出し）部分の区切り線を表示します。
	std::cout << "---------------------------------------------" << std::endl;
	// 各列の見出しを表示します。
	// std::setw(10) は、次の出力の幅を10文字に設定します。
	// std::right は、テキストを右寄せにします。
	std::cout << "|" << std::setw(10) << std::right << "Index";        // 索引番号
	std::cout << "|" << std::setw(10) << std::right << "First Name";   // 名
	std::cout << "|" << std::setw(10) << std::right << "Last Name";    // 姓
	std::cout << "|" << std::setw(10) << std::right <<"NickName";     // ニックネーム
	std::cout << "|" << std::endl;
	// ヘッダー部分の区切り線を再度表示します。
	std::cout << "---------------------------------------------" << std::endl;

	i = 0; // ループカウンターを0に初期化します。
	// 登録されている連絡先の数だけループします。
	while(i < num_contacts)
	{
		// 各連絡先の情報を整形して表示します。
		// 索引番号は1から始まるので `i + 1` とします。
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		// 名、姓、ニックネームは `resize_str` 関数で整形してから表示します。
		std::cout << "|" <<std::setw(10) << std::right << resize_str(contact_lists[i].getFirstName());
		std::cout << "|" << std::setw(10) << std::right << resize_str(contact_lists[i].getLastName());
		std::cout << "|" << std::setw(10) << std::right << resize_str(contact_lists[i].getNickName());
		std::cout << "|" << std::endl;
		i++; // 次の連絡先へ
	}
	// フッター（表の終わり）の区切り線を表示します。
	std::cout << "---------------------------------------------" << std::endl;
}

// 指定されたインデックスの連絡先の詳細情報を表示する関数です。
void PhoneBook::printContact(int index)
{
		// 連絡先の索引番号を表示します（ユーザー向けに+1）。
		std::cout << "[ " << index + 1 << " ]" << std::endl;
		// 各項目の詳細情報を表示します。
		// Contactオブジェクトのゲッター関数を使って情報を取得します。
		std::cout << "First Name : " << contact_lists[index].getFirstName() << std::endl;
		std::cout << "Last Name : " << contact_lists[index].getLastName() << std::endl;
		std::cout << "Nick Name : " << contact_lists[index].getNickName() << std::endl;
		std::cout << "Phone Number : " << contact_lists[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret : " << contact_lists[index].getDarkestSecret() << std::endl;
}

// -------------------- 連絡先検索 (searchContact) 関連 --------------------

// ユーザーから表示したい連絡先のインデックス（番号）を取得する関数です。
// ユーザーの入力が有効な数値で、かつ登録されている連絡先の範囲内であるかを検証します。
// selected_index は、取得した有効なインデックスを呼び出し元に返すための参照引数です。
bool PhoneBook::getIndexFromUser(int& selected_index)
{
	std::string input; // ユーザーの入力を受け取る文字列
	int internal_index; // 内部で使用する0始まりのインデックス
	int user_input_index; // ユーザーが入力した1始まりのインデックス

	// 有効な入力が得られるまで無限ループします。
	while(true)
	{
		// ユーザーにインデックスの入力を促します。
		std::cout << "please input the index of the contact you want to view : ";
		// ユーザーから一行の入力を読み込みます。
		if(!std::getline(std::cin, input))
		{
			// 入力読み込みエラーが発生した場合の処理です。
			std::cout << "Error reading input. Exiting search." <<std::endl;
			// もしEOF（入力の終端）に達していたら、ストリームのエラー状態をクリアします。
			// これにより、プログラムが異常終了するのを防ぎ、次の入力が可能になる場合があります。
			if(std::cin.eof())
				std::cin.clear(); // std::cin のエラーフラグをクリア
			return(false); // 検索を中断し、falseを返します。
		}
		// もし入力が空文字列だったら
		if(input.empty())
		{
			std::cout << "Input cannot be empty. Please enter an index." << std::endl;
			continue; // ループの最初に戻り、再度入力を促します。
		}
		// std::stringstream を使って、文字列を数値に変換します。
		// これにより、入力が数字のみであるかを効率的にチェックできます。
		std::stringstream ss(input);
		// ss >> user_input_index で文字列を整数に変換し、
		// ss.eof() で、変換後に文字列ストリームが終端に達しているか（余計な文字がないか）を確認します。
		if(ss >> user_input_index && ss.eof())
		{
			// ユーザー入力は1始まりなので、内部の0始まりのインデックスに変換します。
			internal_index = user_input_index - 1;
			// 変換されたインデックスが有効な範囲内（0以上、かつ登録されている連絡先の数未満）であるかをチェックします。
			if(internal_index >= 0 && internal_index < num_contacts)
			{
				// 有効なインデックスであれば、参照引数 selected_index に値を設定し、trueを返します。
				selected_index = internal_index;
				return(true);
			}
		}
		// 入力が無効な場合（数字でなかったり、範囲外だったり）のメッセージです。
		std::cout << "Invalid index. Please enter a number between 1 and " << num_contacts << "." << std::endl;
	}
}

// 連絡先を検索して表示する関数です。
bool PhoneBook::searchContact()
{
	// もし登録されている連絡先が0件だったら
	if(num_contacts == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return(true); // 検索は成功（ただし表示するものがない）としてtrueを返します。
	}
	// 連絡先の一覧を表示します。
	printContactlist();
	int selected_index; // ユーザーが選択したインデックスを格納する変数
	// ユーザーから有効なインデックスを取得します。
	// もし取得に失敗したら（例: 入力エラー）、falseを返して処理を中断します。
	if(!getIndexFromUser(selected_index))
		return(false);
	// 取得したインデックスの連絡先の詳細を表示します。
	printContact(selected_index);
	return(true); // 検索処理が成功したことを示します。
}

// -------------------- 連絡先追加 (addContact) 関連 --------------------

// 連絡先を追加する際の現在のインデックスをインクリメント（増やす）する関数です。
// 8件の連絡先を循環的に管理するために使われます。
void PhoneBook::incrementIndex()
{
	index++; // インデックスを1増やします。
	// もしインデックスが8（0-7の配列の範囲外）になったら、
	// 最初の位置（0）に戻します。これにより古い連絡先を上書きします。
	if(index > 7)
		index = 0;
}

// ユーザーから特定の情報の入力を促し、その情報を取得するヘルパー関数です。
// 空の入力は許可しません。
std::string getInfo(std::string str)
{
	std::string input; // ユーザーの入力を受け取る文字列

	// 有効な入力が得られるまで無限ループします。
	while(true)
	{
		// ユーザーに何の情報を入力してほしいか促します。（例: "First Name: "）
		std::cout << str << ": ";
		// ユーザーから一行の入力を読み込みます。
		if(!std::getline(std::cin, input))
		{
			// 入力読み込みエラーが発生した場合の処理です。
			if(std::cin.eof())
				// EOFの場合のエラーメッセージ。
				std::cerr << "End of input detected." << std::endl;
			else
			{
				// その他の入力エラーの場合のエラーメッセージと、ストリームのクリア。
				std::cerr << "Input error occured. Clearing stream." << std::endl;
				std::cin.clear(); // std::cin のエラーフラグをクリア
			}
			return(""); // 空文字列を返して、入力失敗を示します。
		}
		// もし入力が空文字列でなければ
		if(!input.empty())
			return(input); // 入力された文字列を返します。
		else
			// 入力が空だった場合のメッセージ。再度入力を促します。
			std::cout << "empty" << std::endl;
	}
}

// ユーザーから新しい連絡先の詳細情報を全て取得し、Contactオブジェクトに設定する関数です。
// 途中で入力エラーがあればfalseを返します。
bool PhoneBook::getContactDetails(Contact& contact)
{
	std::string input; // 入力された文字列を一時的に保持

	// 名（First Name）を取得します。getInfo関数を利用。
	input = getInfo("First Name");
	// もし入力が空（エラーやEOF）だったら、falseを返します。
	if(input == "")
		return(false);
	// 取得した値をContactオブジェクトに設定します。
	contact.setFirstName(input);

	// 姓（Last Name）を取得し、同様に処理します。
	input = getInfo("Last Name");
	if(input == "")
		return(false);
	contact.setLastName(input);

	// ニックネームを取得し、同様に処理します。
	input = getInfo("Nick Name");
	if(input == "")
		return(false);
	contact.setNickName(input);

	// 電話番号を取得し、同様に処理します。
	input = getInfo("Phone Number");
	if(input == "")
		return(false);
	contact.setPhoneNumber(input);

	// 最も暗い秘密を取得し、同様に処理します。
	input = getInfo("Darkest Secret");
	if(input == "")
		return(false);
	contact.setDarkestSecret(input);

	// 全ての情報の取得と設定が成功したらtrueを返します。
	return(true);
}

// 新しい連絡先を電話帳に追加する関数です。
bool PhoneBook::addContact()
{
	// 一時的なContactオブジェクトを作成します。
	// ユーザーからの入力はこのオブジェクトに一時的に格納されます。
	Contact temp_Contact;

	// ユーザーから連絡先の詳細情報を取得します。
	// もし取得に失敗したら（入力エラーなど）、falseを返して追加を中断します。
	if(!getContactDetails(temp_Contact))
		return(false);

	// もし現在登録されている連絡先の数が8件未満だったら（まだ空きがある場合）
	if(num_contacts < 8)
	{
		// 新しい連絡先を、現在の連絡先数の位置に追加します。
		// 例: num_contactsが0ならcontact_lists[0]に、1ならcontact_lists[1]に。
		contact_lists[num_contacts] = temp_Contact;
		// indexを現在の連絡先数と同じにします。
		index = num_contacts;
		// 連絡先の数を1増やします。
		num_contacts++;
	}
	// もし登録されている連絡先の数が8件に達している場合（電話帳が満杯の場合）
	else
	{
		// indexをインクリメントし、次の書き込み位置を決定します。
		// （これにより、最も古い連絡先が上書きされます。）
		incrementIndex();
		// 新しい連絡先を、計算されたindexの位置に上書きします。
		contact_lists[index] = temp_Contact;
	}
	// 連絡先の追加が成功したことを示します。
	return(true);
}
