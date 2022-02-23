#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int A[n][m], b[m], c[n];

  // 入力
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (int j = 0; j < m; j++) cin >> b[j];

  for (int i = 0; i < n; i++) {
    c[i] = 0;                      // 初期化
    for (int j = 0; j < m; j++) {
      c[i] += A[i][j] * b[j];      // 演算
    }

    cout << c[i] << endl;          // 出力
  }

  return 0;
}
