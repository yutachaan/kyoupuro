// AC
// 行列と行列の積
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, l;
  cin >> n >> m >> l;

  long long int A[n][m], B[m][l], C[n][l];

  // 初期化
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      cin >> B[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      C[i][j] = 0;                    // 初期化
      for (int k = 0; k < m; k++) {
        C[i][j] += A[i][k] * B[k][j]; // 演算
      }
    }
  }

  // 出力
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l - 1; j++) {
      cout << C[i][j] << ' ';
    }
    cout << C[i][l - 1] << endl;
  }

  return 0;
}
