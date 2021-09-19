# ABC 219

A: 条件分岐  
B: 条件分岐と文字列  
C: 新しいアルファベット順による文字列の配列のソート  

## TIL
### mapの全てのkeyとvalueを出力
keyは `itr→first` ，valueは `itr->second` で取得できる．

なお，mapはkeyでsortされた状態となっている．

```cpp
for (auto itr = a.begin(); itr != a.end(); itr++) {
	cout << itr->first << " " << itr->second << endl;
}
```
