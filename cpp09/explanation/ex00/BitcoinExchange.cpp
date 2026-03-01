/* ************************************************************************** */
/*   BitcoinExchange.cpp 実装部分                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// --- 補助ツール：うるう年の判定 ---
// 2月が29日まである年かどうかを判定します
static bool isLeap(int year)
{
    return((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// --- 1. データベースの読み込み ---
// data.csv を読み込んで、map（辞書）に「日付」と「価格」を保存します
void BitcoinExchange::loadDatabase(const std::string& dbFileName)
{
    std::ifstream file(dbFileName.c_str()); // ファイルを開く

    if(!file.is_open()) // ファイルが開けなかったらエラーを投げる
    {
        throw std::runtime_error("could not open database file: " + dbFileName);
    }

    std::string line;
    std::getline(file,line); // 最初の1行目（ヘッダー: date,exchange_rate）を読み飛ばす

    while(std::getline(file, line)) // 1行ずつ読み込む
    {
        if(line.empty()) continue; // 空行は無視

        size_t commaPos = line.find(','); // カンマの位置を探す
        if(commaPos == std::string::npos)
        {
            std::cerr << "Warning: skipping malformed DB line: " << line << std::endl;
            continue;
        }
        // カンマを境に「日付」と「価格」に切り分ける
        std::string dateStr = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);

        try
        {
            float rate = std::atof(rateStr.c_str()); // 文字列を数値に変換
            if(rate < 0)
            {
                std::cerr << "Warning: skipping negative rate in DB line: " << line << std::endl;
                continue;
            }
            exchangeRates[dateStr] = rate; // 辞書(map)に保存！
        }
        catch(const std::exception& e)
        {
            std::cerr << "Warning: skipping non-numeric rate in DB line: " << line << std::endl;
        }
    }
}

// --- 2. 日付のバリデーション（チェック） ---
// 入力された日付がカレンダーとして正しいか（13月とか32日になってないか）を確認します
bool BitcoinExchange::isValidDate(const std::string& date) const
{
    int year, month, day;

    // 基本形 "YYYY-MM-DD" (10文字) かどうか
    if(date.length() != DATE_LEN || date[4] != '-' || date[7] != '-')
    {
        return(false);
    }
    
    // 数字として分解できるか
    if(std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        return(false);
    }

    // 年月日の範囲チェック
    if(year < MIN_YEAR || year > 9999 || month > 12 || month < 1 || day < 1 || day > 31)
    {
            return(false);
    }
    
    // 各月の最終日チェック（2月、4月、6月など）
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    if(month == 2)
    {
        // 2月の場合はうるう年を考慮する
        int maxDay = isLeap(year) ? 29 : 28;
        if(day > maxDay) return(false);
    }
    else if(day > daysInMonth[month])
    {
        return(false);
    }
    return(true);
}

// --- 3. 最も近い日付の価格を探す（重要！） ---
// もし 2011-01-03 のデータがなければ、その直近の過去（2011-01-02など）を探します
float BitcoinExchange::getExchangeRate(const std::string& date) const
{
    // upper_bound は「指定した日付より後の、最初の要素」を指すイテレータを返します
    std::map<std::string, float>::const_iterator it = exchangeRates.upper_bound(date);

    // もし最初から指定日より未来しかなければ、データなし(0)を返す
    if(it == exchangeRates.begin())
        return(0.0f);
    
    // 「一歩戻る」ことで、指定日と同じ、あるいは直近の過去の日付にたどり着きます
    it--;

    return(it->second);
}

// --- 4. 入力ファイルの1行ごとの処理 ---
void BitcoinExchange::processLine(const std::string& line) const
{
    float value;
    size_t commaPos = line.find(","); // 入力が CSV (カンマ区切り) 前提

    if(commaPos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string dateStr = line.substr(0, commaPos);
    std::string valueStr = line.substr(commaPos + 1);
    std::stringstream ss(valueStr);

    // 日付が正しいか？
    if(!isValidDate(dateStr))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    // 数量が正しい数値か？（正の数、かつ100万以内か）
    if(!(ss >> value) || !(ss.eof()))
    {
        std::cerr << "Error: not a valid number." << std::endl;
        return;
    }
    if(value < 0.0f) {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if(value > 1000000.0f) {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }

    // レートを取得して計算
    float rate = getExchangeRate(dateStr);
    
    // 最初の日付より前を指定された場合のエラー処理
    if(rate == 0.0f && !exchangeRates.empty())
    {
        if(dateStr < exchangeRates.begin()->first)
        {
            std::cerr << "Error: no exchange rate available for date or earlier: " << dateStr << std::endl;
            return;
        }
    }

    float result = value * rate; // 計算（数量 × レート）
    std::cout << dateStr << " => " << value << " = " << result << std::endl;
}

// --- コンストラクタ / デストラクタ ---
BitcoinExchange::BitcoinExchange(const std::string& dbFileName)
{
    loadDatabase(dbFileName); // インスタンス化された瞬間にDBを読み込む
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : exchangeRates(other.exchangeRates) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
        this->exchangeRates = other.exchangeRates;
    return(*this);
}

// --- メイン実行関数 ---
void BitcoinExchange::execute(const std::string& inputFileName)
{
    std::ifstream file(inputFileName.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    if(!std::getline(file, line)) return; // ヘッダー行を読み飛ばす

    while(std::getline(file, line)) // 入力ファイルの各行に対して処理を実行
    {
        processLine(line);
    }
}

/*
 * ==========================================================================
 * 【初学者向け：getExchangeRate 内の "upper_bound" のトリック解説】
 * ==========================================================================
 *
 * このプログラムでは「指定された日付」がデータベースにない場合、
 * 「その日より前の、最も近い日のレート」を使う必要があります。
 *
 * 例：探したい日 = 2011-01-03
 * DBにあるデータ:
 * 2011-01-01  =>  0.3
 * 2011-01-02  =>  0.4  <-- これが欲しい！
 * 2011-01-05  =>  0.8
 *
 * --- 手順 ---
 * 1. upper_bound("2011-01-03") を実行
 * -> これは「2011-01-03 より後の、最初のデータ」を見つけます。
 * -> つまり、イテレータ(it)は "2011-01-05" を指します。
 *
 * 2. it-- を実行
 * -> イテレータを一つ前に戻します。
 * -> すると、it は "2011-01-02" を指すようになります。これで解決！
 */



/*
 * --- 注意点（ガード処理） ---
 * ・もし upper_bound が map の一番最初 (begin) を指してしまったら？
 * -> それは「指定された日が、DBにあるどの日付よりも古い」ということです。
 * -> その場合は「一歩戻る」ことができないため、エラーとして処理します。
 *
 * このように std::map の「自動ソート（整列）」と「二分探索（高速検索）」を
 * 組み合わせることで、膨大なデータの中から一瞬で正しいレートを見つけています。
 */
