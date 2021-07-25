// AC
// 10進法での各桁の和
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, ans, min_sum = 1000;
  cin >> N;

  // 折り返し地点まで繰り返し
  for (int i = 1; i <= N / 2; i++) {
    int A = i, B = N - i, sum = 0;

    // AとBの各桁の和の合計を求める
    while (A > 0) {
      sum += A % 10;
      A /= 10;
    }
    while (B > 0) {
      sum += B % 10;
      B /= 10;
    }

    // 最小値の更新
    if (sum < min_sum) {
      ans = sum;
      min_sum = sum;
    }
  }

  cout << ans << endl;

  return 0;
}
