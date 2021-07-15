// AC
// 行列と列ベクトルの積
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int A[n][m] = {0}, b[m] = {0}, c[n] = {0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (int j = 0; j < m; j++) cin >> b[j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i] += A[i][j] * b[j];
    }

    cout << c[i] << endl;
  }

  return 0;
}
