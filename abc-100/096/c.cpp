// AC
// グリッド処理(4近傍)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  char s[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> s[i][j];
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // 黒いマスのうち，上下左右の隣り合うマスに黒いマスがないものがあるかを調べる
      if (s[i][j] == '#') {
        bool OK = false; // 指定された塗り方ができるか

        // 4近傍を探索
        for (int dx = -1; dx < 2; dx++) {
          for (int dy = -1; dy < 2; dy++) {
            if ((dx == dy) || (dx + dy == 0)) continue;

            int xx = i + dx;
            int yy = j + dy;
            if ((xx >= 0) && (xx < H) && (yy >= 0) && (yy < W)) {
              if (s[xx][yy] == '#') OK = true;
            }
          }
        }

        // ある場合はNo
        if (!OK) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}
