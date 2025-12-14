/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_explanation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:35:34 by kanahash          #+#    #+#             */
/*   Updated: 2025/07/24 01:35:41 by kanahash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp" // Harlクラスの定義が含まれるヘッダーファイルをインクルード

// プログラムのエントリポイント（ここから実行が開始される）
int main() {
    // Harlクラスのオブジェクトを生成する
    // これにより、Harlのコンストラクタが呼び出される
    Harl harl;

    // --- デバッグレベルのテスト ---
    std::cout << "--- Testing DEBUG level ---" << std::endl;
    // harlオブジェクトのcomplainメソッドを呼び出し、"DEBUG"レベルで不満を言わせる
    harl.complain("DEBUG");

    // --- 情報レベルのテスト ---
    // 改行を出力し、テストケースの区切りを視覚的に分かりやすくする
    std::cout << "\n--- Testing INFO level ---" << std::endl;
    // harlオブジェクトのcomplainメソッドを呼び出し、"INFO"レベルで不満を言わせる
    harl.complain("INFO");

    // --- 警告レベルのテスト ---
    std::cout << "\n--- Testing WARNING level ---" << std::endl;
    // harlオブジェクトのcomplainメソッドを呼び出し、"WARNING"レベルで不満を言わせる
    harl.complain("WARNING");

    // --- エラーレベルのテスト ---
    std::cout << "\n--- Testing ERROR level ---" << std::endl;
    // harlオブジェクトのcomplainメソッドを呼び出し、"ERROR"レベルで不満を言わせる
    harl.complain("ERROR");

    // --- 未知のレベルのテスト ---
    std::cout << "\n--- Testing an unknown level ---" << std::endl;
    // 存在しないレベル（"UNKNOWN"）をcomplainメソッドに渡し、
    // 無効な入力に対するHarlの挙動を確認する
    harl.complain("UNKNOWN");

    // プログラムが正常終了したことを示す
    return 0;
}
