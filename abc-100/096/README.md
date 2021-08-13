# ABC 096

C: グリッド処理(4近傍)  

## TIL
### 4近傍の座標の探索
```c++
for (int i = 0; i < H; i++) {
  for (int j = 0; j < W; j++) {

    for (int dx = -1; dx < 2; dx++) {
      for (int dy = -1; dy < 2; dy++) {
        if ((dx == dy) || (dx + dy == 0)) continue;

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
