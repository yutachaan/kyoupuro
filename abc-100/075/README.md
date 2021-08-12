# ABC 075

B: グリッド処理  

## TIL
### 8近傍の座標を探索する
```c++
for (int i = 0; i < H; i++) {
  for (int j = 0; j < W; j++) {

    for (int dx = -1; dx < 2; dx++) {
      for (int dy = -1; dy < 2; dy++) {
        if ((dx == 0) && (dy == 0)) continue;
        int xx = i + dx;
        int yy = j + dy;
        if ((xx >= 0) && (xx < H) && (yy >= 0) && (yy < W)) {
          // S[xx][yy]が近傍の座標
        }
      }
    }

  }
}
```
