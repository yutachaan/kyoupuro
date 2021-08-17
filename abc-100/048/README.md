# ABC 048

B: a以上b以下の整数のうち，xで割り切れるものの個数  

## TIL
### a以上b以下の整数のうち，xで割り切れるものの個数
```cpp
if (a == 0) ans = b / x + 1;
else ans = b / x - (a - 1) / x;
```
