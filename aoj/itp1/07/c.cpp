#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  // 初期化
  int table[r + 1][c + 1];
  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < c + 1; j++) {
      table[i][j] = 0;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> table[i][j];          // 入力
      table[i][c] += table[i][j];  // 各行の総和を求める
    }
  }

  // 各列の総和を求める
  for (int j = 0; j < c + 1; j++) {
    for (int i = 0; i < r; i++) {
      table[r][j] += table[i][j];
    }
  }

  // 出力
  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < c; j++) {
      cout << table[i][j] << ' ';
    }
    cout << table[i][c] << endl;
  }

  return 0;
}
