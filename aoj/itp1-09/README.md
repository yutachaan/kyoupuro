# ITP 1-9

A: 文章にある単語が何個含まれているか  
B: 1つの単語をシャッフル(きる)  
C: 文字列の辞書順比較を用いたカードゲーム  
D: 部分文字列の出力，リバース，置換

## TIL
### string型の小文字化
```cpp
transform(S.begin(), S.end(), S.begin(), ::tolower);
```

### 文字列の置換
文字列strの3文字目から5文字を，文字列"abcde"で置換するには以下のようにする．
```cpp
str.replace(3, 5, "abcde");
```
