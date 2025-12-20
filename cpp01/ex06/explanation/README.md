## 🛠️ C++ Module 01 ex06: 要点まとめ（Harl filter）

> **核心テーマ**: `switch` 文の「フォールスルー（fall-through）」特性を理解し、ログレベルに応じた段階的なフィルタリング機能を実装する。

---

### 1. 課題の目的
実行時の引数として「ログレベル」を受け取り、そのレベル以上のすべてのメッセージを表示するプログラムを作成する。

* **例**: `WARNING` を指定した場合、`WARNING` と `ERROR` のメッセージが表示される。
* **最大の制約**: `if/else` ではなく、**`switch` 文** を使用してフィルタリングを実装する必要がある。

---

### 2. switch 文と fall-through（フォールスルー）
この課題の革新的な技術ポイント。

#### ○ fall-through とは
`case` ラベルの末尾に `break` を書かない場合、次の `case` の処理がそのまま実行される性質のこと。

#### ○ ex06 での活用
`DEBUG` が選ばれたら、そのまま **「INFO → WARNING → ERROR」** と流れるように、`break` をあえて省略（または意図的に配置）する。



---

### 3. switch 文の基本と応用

#### ○ 基本シンタックス
`switch` 文は **整数型（int, char, enum）のみ** を評価できる。
* **注意**: 文字列（`std::string`）は直接渡せない。

#### ○ フォールスルー
`break` を書かないと、次の `case` の処理まで連続して実行される。

#### ○ 文字列を switch で使うための「変換」
C++ では `switch("DEBUG")` とは書けない。
そのため、ex05 で使った手法を応用して、文字列を **インデックス（数値）** に変換する。

#### ○ ex06 実装時の論理フロー
1. **引数チェック**: `argc` が 2 でない場合は即終了。
2. **インデックス化**: 入力文字列が何番目のレベルか特定する（0～3、見つからなければ -1）。
3. **スイッチ**:
    * **case 0**: `DEBUG` を表示 → 次へ流れる
    * **case 1**: `INFO` を表示 → 次へ流れる
    * **case 2**: `WARNING` を表示 → 次へ流れる
    * **case 3**: `ERROR` を表示 → 次へ流れる
    * **default**: 「Probably complaining about insignificant problems」を表示



#### ○ なぜ if-else ではなく switch なのか
一方向の連続的な処理（フィルタリング）を、フォールスルーを利用して **最も簡潔に記述できるから**。

### 4. 実装のアルゴリズム
`switch` 文は「文字列」を直接比較できないため、一度文字列を「数値（インデックス）」に変換する必要がある。

* **➀ 数値への変換**: 引数の文字列を `DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3` のように数値に変換する。
* **➁ switch文への受け渡し**: その数値を `switch` 文に渡す。
* **③ 制御**: 各 `case` で `complain()` を呼び出し、適切に `break` を制御する。



---

### 5. 実装における注意点
* **期待される出力形式**
    → 課題要件として、各レベルの前に `[ LEVEL_NAME ]` というヘッダーを表示し、最後に改行を入れるなど、フォーマットを整える必要がある。
* **デフォルトケース**
    → 引数が4つのレベル以外だった場合（または引数がない場合）、
      `[ Probably complaining about insignificant problems ]`
      と表示することが求められている。
* **FALLTHROUGHコメント**
    → 意図的に `break` を書かない箇所には、コンパイラの警告を防ぎ、可読性を高めるために `/* FALLTHROUGH */` と書くと良い。

---

### 6. テストすべき項目

| テストケース | 入力例 | 期待される挙動 |
| :--- | :--- | :--- |
| 最低レベル | `./harlFilter "DEBUG"` | DEBUG, INFO, WARNING, ERROR すべて表示 |
| 中間レベル | `./harlFilter "WARNING"` | WARNING, ERROR のみ表示 |
| 最高レベル | `./harlFilter "ERROR"` | ERROR のみ表示 |
| 無効な入力 | `./harlFilter "I am hungry"` | 「Probably complaining...」を表示 |
| 引数なし | `./harlFilter` | エラーメッセージまたはデフォルト表示 |

---

### 7. まとめ

| 項目 | 内容 |
| :--- | :--- |
| **主要技術** | switch 文、列挙型（またはインデックス変換）、fall-through |
| **設計思想** | 段階的なフィルタリング処理 |
| **ポイント** | 文字列を switch で使うための前処理 |

---

### 3. switch文の基本と応用

#### ○ 基本シンタックス
```cpp
switch (評価する変数) {
    case 値1:
        // 値1の時の処理
        break; // ここでswitchを抜ける
    case 値2:
        // 値2の時の処理
        break;
    default:
        // どのcaseにも当てはまらない時の処理
        break;
}

#### ○ フォールスルー (Fall-through)
`break` をあえて書かないことで、選択されたレベルから下の処理をすべて連続して実行させます。これが「指定レベル以上のログを表示する」フィルタリングの核心です。



```cpp
switch (index) {
    case 0: // DEBUG
        harl.complain("DEBUG");
        // breakを書かないことで、下のINFOも実行される
    case 1: // INFO
        harl.complain("INFO");
    case 2: // WARNING
        harl.complain("WARNING");
    case 3: // ERROR
        harl.complain("ERROR");
        break; // 最後は止める
}

#### ○ 文字列を switch で使うための「変換」
C++ の `switch` 文は文字列を直接評価できないため、以下のように配列とループを使って文字列を「数値（インデックス）」に変換する前処理を行います。



```cpp
std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
int index = -1;

for (int i = 0; i < 4; i++) {
    if (levels[i] == input_string) {
        index = i;
        break;
    }
}

// 変換した数値をswitchに渡す
switch (index) {
    case 0:
        // DEBUG以上の処理を実行
        /* FALLTHROUGH */
    case 1:
        // INFO以上の処理を実行
        /* FALLTHROUGH */
    case 2:
        // WARNING以上の処理を実行
        /* FALLTHROUGH */
    case 3:
        // ERRORの処理を実行
        break;
    default:
        // 該当なし：[ Probably complaining about insignificant problems ]
        break;
}
