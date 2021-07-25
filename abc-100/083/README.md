# ABC 083

B: 10進法での各桁の和  

## TIL
### 10進法での各桁の和
```cpp
int sum = 0;
while (n > 0) {
  sum += n % 10;
  n /= 10;
}
```
