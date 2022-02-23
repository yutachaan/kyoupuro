#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  // 初期化
  int house[4][3][10];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 10; k++) {
        house[i][j][k] = 0;
      }
    }
  }

  // カウント
  for (int i = 0; i < n; i++) {
    int b, f, r, v;
    cin >> b >> f >> r >> v;

    house[b - 1][f - 1][r - 1] += v;
  }

  // 出力
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 10; k++) {
        cout << ' ' << house[i][j][k];
      }
      cout << endl;
    }
    if (i <= 2) cout << string(20, '#') << endl;
  }

  return 0;
}
