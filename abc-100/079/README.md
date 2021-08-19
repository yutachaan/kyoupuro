# ABC 079

C: bit全探索  

## TIL
### bit全探索
```cpp
for (int bit = 0; bit < (1 << n); bit++) {
  for (int i = 0; i < n; i++) {
    if (bit & (1 << i)) {
      // i番目のbitが1の場合の処理
    }
    else {
      // i番目のbitが0の場合の処理
    }
  }
}
```

例
```cpp
for (int bit = 0; bit < (1 << 3); bit++) {
  for (int i = 0; i < 3; i++) {
    if (bit & (1 << i)) {
      cout << 1;
    }
    else {
      cout << 0;
    }
  }
  cout << endl;
}
```

```
000
100
010
110
001
101
011
111
```
