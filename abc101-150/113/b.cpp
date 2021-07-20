// AC
// ある値との絶対値の最小値
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, T, A, ans;
  cin >> N >> T >> A;

  double min_abs_t = 1000000000;
  for (int i = 0; i < N; i++) {
    int H;
    cin >> H;
    double abs_t = fabs(A - (T - H * 0.006));

    if (abs_t < min_abs_t) {
      min_abs_t = abs_t;
      ans = i + 1;
    }
  }

  cout << ans << endl;

  return 0;
}
