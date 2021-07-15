// AC
// 表の行と列それぞれの和
#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  int table[r + 1][c + 1];
  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < c + 1; j++) {
      table[i][j] = 0;
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> table[i][j];
      table[i][c] += table[i][j];
    }
  }

  for (int j = 0; j < c + 1; j++) {
    for (int i = 0; i < r; i++) {
      table[r][j] += table[i][j];
    }
  }

  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < c; j++) {
      cout << table[i][j] << ' ';
    }
    cout << table[i][c] << endl;
  }

  return 0;
}
