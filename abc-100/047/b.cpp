// AC
// 二次元のバケット法
#include <bits/stdc++.h>

using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  // 初期化
  int rectangle[W][H];
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) rectangle[i][j] = 0;
  }

  // バケット法
  for (int i = 0; i < N; i++) {
    int x, y, a;
    cin >> x >> y >> a;

    if (a == 1) {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < H; j++) rectangle[i][j]++;
      }
    }
    else if (a == 2) {
      for (int i = x; i < W; i++) {
        for (int j = 0; j < H; j++) rectangle[i][j]++;
      }
    }
    else if (a == 3) {
      for (int i = 0; i < W; i++) {
        for (int j = 0; j < y; j++) rectangle[i][j]++;
      }
    }
    else {
      for (int i = 0; i < W; i++) {
        for (int j = y; j < H; j++) rectangle[i][j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (rectangle[i][j] == 0) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
