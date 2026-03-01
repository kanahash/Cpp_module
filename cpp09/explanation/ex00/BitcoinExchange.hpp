/* ************************************************************************** */
/* この部分は 42 という学校の共通ヘッダー（いつ、誰が作ったか）です。          */
/* ************************************************************************** */

// 二重に読み込まれるのを防ぐための「おまじない」です（インクルードガード）
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// ビットコインの価格データが入っているデフォルトのファイル名です
#define DB_FILE_NAME "data.csv"

#include <iostream>  // 入出力（画面に文字を出すなど）のため
#include <map>       // データを「日付」と「価格」のペアで保存するため
#include <string>    // 文字列を扱うため
#include <fstream>   // ファイルを読み書きするため
#include <sstream>   // 文字列を分解（パース）しやすくするため
#include <cstdlib>   // 数値変換などの便利な機能のため

/*
 * BitcoinExchange クラス
 * このクラスがビットコインの換算機本体になります。
 */
class BitcoinExchange
{
    private:
        // --- 設定値（定数） ---
        static const int MIN_YEAR = 2009;   // ビットコインが始まった2009年より前はエラーにするため
        static const int MAX_VALUE = 1000;  // 入力値の上限（課題の制約など）
        static const size_t DATE_LEN = 10;  // 日付の文字数（"YYYY-MM-DD" は10文字）

        // --- 内部データ ---
        // std::map は「辞書」のようなものです。
        // key（日付: string）を渡すと、value（価格: float）を高速に見つけ出せます。
        std::map<std::string, float> exchangeRates;

        // --- 内部で使うツール（補助関数） ---
        void loadDatabase(const std::string& dbFileName);    // データベース(data.csv)を読み込む
        bool isValidDate(const std::string& date) const;     // 日付が正しい形式かチェックする
        float getExchangeRate(const std::string& date) const; // 指定した日付の価格を探す
        void processLine(const std::string& line) const;     // 入力ファイルの1行分を処理する

    public:
        // --- 基本的なルール（コンストラクタ・デストラクタ） ---
        BitcoinExchange(const std::string& dbFileName);      // 作られた時にデータベースを読み込む
        BitcoinExchange(const BitcoinExchange &other);       // コピーして作る時用
        ~BitcoinExchange();                                  // 壊れる（終了する）時用
        BitcoinExchange& operator=(const BitcoinExchange &other); // 中身を代入する時用
    
        // --- メインの動作 ---
        // この関数に「調べたい日付と数量が書かれたファイル」を渡すと、計算結果を画面に出します
        void execute(const std::string& inputFileName);
};

#endif

/*
 * ==========================================================================
 * 【初学者向け：このコードの設計のツボ（ポイント）】
 * ==========================================================================
 *
 * 1. std::map<std::string, float> の活用（プログラムの心臓部）
 * --------------------------------------------------------------------------
 * mapは「辞書」のようなデータ構造ですが、最大の特徴は【中身を常に自動で並べ替える】ことです。
 * 日付（"YYYY-MM-DD"）をキーにすると、文字コードの順＝日付の古い順に整列されます。
 * これにより、「指定された日付がない場合、その日に最も近い過去のデータを取得する」
 * という処理（lower_bound や --upper_bound）が非常に効率的に行えます。
 */



/*
 * 2. カプセル化（Private と Public の使い分け）
 * --------------------------------------------------------------------------
 * ● Private（秘密の部屋）:
 * - exchangeRates（価格表データ）や loadDatabase（読み込み処理）など。
 * - 外部から勝手にデータを消されたり、壊されたりしないように隠して守っています。
 *
 * ● Public（受付窓口）:
 * - execute 関数など。
 * - ユーザーはこの窓口に「このファイルを処理して」と頼むだけでOK。
 * 中身がどう動いているか（どう読み込んでいるか）を知らなくても使える設計です。
 */



/*
 * 3. エラーチェックの徹底（堅牢なプログラム）
 * --------------------------------------------------------------------------
 * プログラムが途中で止まったり、間違った計算をしたりしないようガードを固めています。
 * - MIN_YEAR (2009年): ビットコイン誕生以前のデータは扱わないようにチェック。
 * - MAX_VALUE (1000):  課題の制約に基づき、大きすぎる数値はエラーとして弾く。
 * - DATE_LEN (10文字): "2023-01-01" のような正しい形式以外は処理しない。
 *
 * ユーザーがどんな「変な入力」をしても、壊れずに「Error: ...」と返せるのが良いコードです。
 */
