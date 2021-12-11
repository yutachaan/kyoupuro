# ABC 230

A: ゼロ埋め  
B: string find  
C: 塗り絵，塗る範囲工夫

## TIL
### ゼロ埋め
全体が5桁で左側に0を埋めるには以下のようにする．
```c++
cout << setfill('0') << right << setw(5) << 123 << endl;

// 出力
00123
```

### long long int
- 問題文中に1つでもlong long int 型が必要なら，全てlong long intにする
- long long int は `ll` でいける
