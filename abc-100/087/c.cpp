// AC
// 累積和
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  // 入力
  int A[2][N];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) cin >> A[i][j];
  }

  int cumSum_1[N]; // 1行目の累積和
  cumSum_1[0] = A[0][0];
  for (int j = 1; j < N; j++) cumSum_1[j] = cumSum_1[j - 1] + A[0][j];

  int ans = 0;
  for (int j = 0; j < N; j++) {
    // 1行目のj列目までの累積和と2行目のj列目からN列目までの累積和の和が，右下にたどり着いた時の値のため，それを求める
    int cumSum = cumSum_1[j]; // 右下に辿り着いた時の値
    for (int jj = j; jj < N; jj++) cumSum += A[1][jj];

    if (cumSum > ans) ans = cumSum;
  }

  cout << ans << endl;

  return 0;
}
