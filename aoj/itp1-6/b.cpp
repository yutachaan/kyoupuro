// AC
// 二次元配列を用いた不足しているトランプカードの発見
#include <bits/stdc++.h>

using namespace std;

int main() {
  int trump[4][13] = {0};
  int n, rank;
  char pattern;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> pattern >> rank;

    if (pattern == 'S') trump[0][rank - 1] = 1;
    else if (pattern == 'H') trump[1][rank - 1] = 1;
    else if (pattern == 'C') trump[2][rank - 1] = 1;
    else if (pattern == 'D') trump[3][rank - 1] = 1;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      if (trump[i][j] == 0) {
        if (i == 0) cout << "S " << j + 1 << endl;
        else if (i == 1) cout << "H " << j + 1 << endl;
        else if (i == 2) cout << "C " << j + 1 << endl;
        else if (i == 3) cout << "D " << j + 1 << endl;
      }
    }
  }

  return 0;
}
