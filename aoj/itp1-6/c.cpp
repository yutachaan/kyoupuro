// AC
// 三次元配列を用いた公舎の入居者数の管理
#include <bits/stdc++.h>

using namespace std;

int main() {
  int house[4][3][10] = {0};
  int n, b, f, r, v;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> b >> f >> r >> v;

    house[b - 1][f - 1][r - 1] += v;
  }

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
