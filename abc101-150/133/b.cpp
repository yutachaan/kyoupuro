// AC
// N個の点から2点を選び，それらの距離が整数となる場合の数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, D, ans = 0;
  cin >> N >> D;

  // 入力
  int coord[D][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) cin >> coord[j][i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double temp = 0;
      for (int k = 0; k < D; k++) temp += pow(coord[k][i] - coord[k][j], 2);

      temp = sqrt(temp);
      if (ceil(temp) == floor(temp)) ans++; // 整数かどうか判定
    }
  }

  cout << ans << endl;

  return 0;
}
