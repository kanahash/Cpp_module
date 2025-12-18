# 📘 Exercise 04: Sed is for losers - テストケース集

**プログラム名**: `Sed_is_for_losers`  
**使用法**: `./Sed_is_for_losers <filename> <s1> <s2>`

---

## ✅ 1. Basic_Replacement（基本的な置き換え）

- **入力ファイル**: `input_basic.txt`
  ```
  Hello world! This is a test.
  world world world
  Another line with world.
  ```

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_basic.txt "world" "universe"
  ```

- **期待される出力ファイル**: `input_basic.txt.replace`
  ```
  Hello universe! This is a test.
  universe universe universe
  Another line with universe.
  ```

- **確認事項**:
  - `"world"` がすべて `"universe"` に正しく置き換えられているか
  - 行内の複数出現も対応できているか

---

## ✅ 2. No_Match（一致なし）

- **入力ファイル**: `input_no_match.txt`
  ```
  This file contains no specific words.
  Just plain text.
  ```

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_no_match.txt "nonexistent" "replacement"
  ```

- **期待される出力**:
  ```
  This file contains no specific words.
  Just plain text.
  ```

- **確認事項**:
  - 一致する文字列がないとき、元の内容がそのままコピーされるか

---

## ✅ 3. Empty_File（空のファイル）

- **入力ファイル**: `input_empty.txt`（空）

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_empty.txt "any_string" "another_string"
  ```

- **期待される出力**: 空のファイル

- **確認事項**:
  - 空のファイルが正常に処理され、空のまま出力されているか

---

## ✅ 4. Empty_S1（s1が空）

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_any.txt "" "replacement"
  ```

- **期待される出力**:
  ```
  Error: s1 cannot be an empty string.
  ```

- **確認事項**:
  - s1 が空文字列のとき、適切なエラーメッセージを出力し終了するか

---

## ✅ 5. Empty_S2（s2が空）

- **入力ファイル**: `input_delete.txt`
  ```
  This is a word to delete.
  Delete this word.
  ```

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_delete.txt "word" ""
  ```

- **期待される出力**:
  ```
  This is a  to delete.
  Delete this .
  ```

- **確認事項**:
  - s2 が空文字列でも s1 が正しく削除されるか

---

## ✅ 6. Overlapping_S1_S2（s1がs2に含まれる）

- **入力ファイル**: `input_overlap.txt`
  ```
  banana
  ```

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_overlap.txt "ana" "apple"
  ```

- **期待される出力**:
  ```
  bapplena
  ```

- **確認事項**:
  - s1 の置換後、後続の文字列も正しく評価されているか
  - 一度置換した範囲の重複をスキップしない仕様であること

---

## ✅ 7. Nonexistent_Input_File（存在しないファイル）

- **コマンド**:
  ```bash
  ./Sed_is_for_losers nonexistent_file.txt "test" "replace"
  ```

- **期待される出力**:
  ```
  Error: Could not open input file.
  ```

- **確認事項**:
  - ファイルが存在しない場合、明確なエラーメッセージが表示されるか

---

## ✅ 8. Invalid_Argument_Count（引数数の不備）

- **コマンド（少ない）**:
  ```bash
  ./Sed_is_for_losers file.txt "s1"
  ```

- **コマンド（多い）**:
  ```bash
  ./Sed_is_for_losers file.txt "s1" "s2" "extra_arg"
  ```

- **期待される出力**:
  ```
  Usage: ./Sed_is_for_losers <filename> <s1> <s2>
  ```

- **確認事項**:
  - 引数が3つでない場合に、使い方を正しく表示して終了するか

---

## ✅ 9. Case_Sensitivity（大文字・小文字の区別）

- **入力ファイル**: `input_case.txt`
  ```
  Apple apple APPLE
  ```

- **コマンド**:
  ```bash
  ./Sed_is_for_losers input_case.txt "apple" "orange"
  ```

- **期待される出力**:
  ```
  Apple orange APPLE
  ```

- **確認事項**:
  - `"apple"` のみが置き換えられ、大文字 `"Apple"` や `"APPLE"` は無視されているか（case-sensitive）

---
