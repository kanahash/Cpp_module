/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:30:27 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/19 23:34:16 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string> // std::string クラスを使用するために必要
#include <iostream> // 標準入出力 (std::cout, std::cerr, std::endl) を使用するために必要
#include <fstream> // ファイルストリーム (std::ifstream, std::ofstream, std::fstream) を使用するために必要

// ファイルをオープンする関数
// Receive_inputfile: 入力ファイル名
// Receive_outputfile: 出力ファイル名
// inputfile: 入力ファイルストリームへのポインタ
// outputfile: 出力ファイルストリームへのポインタ
int open_file(std::string Receive_inputfile, std::string Receive_outputfile, std::ifstream *inputfile, std::ofstream *outputfile)
{
	// 入力ファイルを読み込みモードで開く
	// std::string を Cスタイルの文字列 (const char*) に変換するために .c_str() を使用
	(*inputfile).open(Receive_inputfile.c_str(), std::fstream::in);
	// 出力ファイルを書き込みモードで開く
	(*outputfile).open(Receive_outputfile.c_str(), std::fstream::out);

	// ファイルが正常に開かれたかを確認
	// 注意: !inputfile や !outputfile はポインタがNULLかどうかのチェックであり、
	// ストリームが正常に開かれたかのチェックとしては不適切です。
	// 正しくは !(*inputfile).is_open() または !(*inputfile) のように、
	// ストリームオブジェクト自体の状態をチェックすべきです。
	if(!inputfile || !outputfile)
	{
		// ファイルオープン失敗時のエラーメッセージを標準エラー出力に表示
		std::cerr << "Failed to open files!!!" << std::endl;
		// 開こうとしたファイルを閉じる（既に開かれていれば閉じる）
		(*inputfile).close();
		(*outputfile).close();
		// エラーを示す1を返して終了
		return(1);
	}
	// 成功を示す0を返して終了
	return(0);
}

// 文字列を置換する関数
// line: 置換対象の元の文字列
// to_find: 検索する文字列
// to_replace: 置換する文字列
// 戻り値: 置換後の新しい文字列
std::string replace(const std::string& line, const std::string& to_find, const std::string& to_replace)
{
	std::string replaced_line; // 置換後の文字列を格納する変数
	std::string::size_type found; // 見つかった文字列の開始位置を格納する変数
	size_t end_last_found = 0; // 前回見つかった文字列の直後の位置（次の検索開始位置）

	// lineの中から to_find の最初の出現を検索
	found = line.find(to_find);
	// to_find が見つからなかった場合 (std::string::npos は「見つからない」を示す特別な値)
	if(found == std::string::npos)
		return(line); // 元の行をそのまま返す

	// to_find が見つかっている間、ループを続ける
	while(found != std::string::npos)
	{
		// 前回見つかった文字列の終わり (end_last_found) から
		// 現在見つかった文字列の開始位置 (found) までの部分を replaced_line に追加
		replaced_line.append(line, end_last_found, found - end_last_found);
		// 置き換え文字列 (to_replace) を replaced_line に追加
		replaced_line += to_replace;
		// 次の検索開始位置を、現在見つかった文字列の終わり (found + to_findの長さ) に更新
		end_last_found = found + to_find.length();
		// 更新された開始位置から、次の to_find を検索
		found = line.find(to_find, end_last_found);
	}
	// ループ終了後（全ての to_find が置換された後）、
	// 最後の to_find の終わり (end_last_found) から line の最後までを replaced_line に追加
	replaced_line.append(line, end_last_found, line.length() - end_last_found);
	return(replaced_line); // 完成した置換後の文字列を返す
}

// ファイルを読み込み、文字列を置換して新しいファイルに書き出す関数
// av: コマンドライン引数の配列 (s1 と s2 を取得するため)
// inputfile: 入力ファイルストリームへのポインタ
// outputfile: 出力ファイルストリームへのポインタ
void read_and_replace(char **av, std::ifstream *inputfile, std::ofstream *outputfile)
{
	std::string to_find; // 検索する文字列 s1
	std::string to_replace; // 置換する文字列 s2
	std::string line; // 入力ファイルから読み込んだ1行を格納する変数
	std::string replaced_line; // 置換後の行を格納する変数

	// コマンドライン引数から検索文字列 (av[2]) と置換文字列 (av[3]) を取得
	to_find = *(av + 2); // av[2] と同じ意味
	to_replace = *(av + 3); // av[3] と同じ意味

	// 入力ファイルから1行ずつ読み込む (ファイル終端に達するかエラーが発生するまで)
	while(std::getline(*inputfile, line))
	{
		// 読み込んだ行に対して文字列置換を実行
		replaced_line = replace(line, to_find, to_replace);

		// 入力ファイルが終端に達していない場合（つまり、まだ次の行がある場合）
		if(!(*inputfile).eof())
			// 置換後の行と改行文字を出力ファイルに書き込む
			*outputfile << replaced_line << std::endl;
		else
			// 入力ファイルが終端に達している場合（最後の行の場合）
			// 置換後の行のみを書き込み、余分な改行文字を追加しない
			*outputfile << replaced_line;
	}
}

// プログラムのエントリーポイント
// ac: コマンドライン引数の数
// av: コマンドライン引数の配列
int main(int ac, char **av)
{
	std::string Receive_inputfile; // 入力ファイル名を格納する変数
	std::string Receive_outputfile; // 出力ファイル名を格納する変数
	std::ifstream inputfile; // 入力ファイルストリームオブジェクト
	std::ofstream outputfile; // 出力ファイルストリームオブジェクト

	// 引数の数が4つ (プログラム名 + 入力ファイル名 + s1 + s2) ではない場合
	if(ac != 4)
		// エラーメッセージを標準出力に表示し、0を返してプログラムを終了
		// (std::cout << ... , 0) はカンマ演算子を使った表現で、メッセージを出力後0を返す
		return(std::cout << "Wrong number of arguments" << std::endl, 0);

	// 最初の引数 (av[1]) を入力ファイル名として取得
	Receive_inputfile = av[1];
	// 出力ファイル名を生成
	// 例: input.txt -> input.txt.replace
	// ここは以前のコメントで指摘した通り、av[1]を二重に追加する間違いを修正済みです。
	Receive_outputfile = Receive_inputfile + ".replace";

	// open_file 関数を呼び出してファイルを開く
	// open_file が1を返した場合（ファイルオープン失敗）
	if(open_file(Receive_inputfile, Receive_outputfile, &inputfile, &outputfile))
		return(1); // エラーを示す1を返してプログラムを終了

	// ファイルの読み込み、文字列置換、書き出しを実行
	read_and_replace(av, &inputfile, &outputfile);

	// 入力ファイルをクローズ
	inputfile.close();
	// 出力ファイルをクローズ
	outputfile.close();

	// 正常終了を示す0を返してプログラムを終了
	return(0);
}

