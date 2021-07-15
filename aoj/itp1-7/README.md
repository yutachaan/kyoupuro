# ITP 1-7

A: 授業成績の出力  
B: 1からnまでで和がxとなる組み合わせ  
C: 表の行と列それぞれの和  
D: 行列と行列の積

## TIL
### 配列の初期化
```
bool a[n] = {false};
fill(a, a + n, true);
```

### 組み合わせ
n個からr個とりさす時の組み合わせの列挙
```
bool a[n] = {false};
fill(a, a + r, true);
do {
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
} while (prev_permutation(a, a + n));
```
