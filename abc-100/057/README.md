# ABC 057

C:  N=AxBを満たすA, Bの組  

## TIL
### 約数列挙
```cpp
for (int i = 1; i * i <= N; i++) {
  if (N % i == 0) {
    cout << i << endl;

    // sqrt(N)より大きい約数
    if (N / i != i) cout << N / i << endl;
  }
}
```
