// AC
// 二次元座標上でのパリティ(偶数と奇数に関する性質)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int t[N + 1], x[N + 1], y[N + 1];
  t[0] = x[0] = y[0] = 0;
  for (int i = 1; i < N + 1; i++) cin >> t[i] >> x[i] >> y[i];

  bool OK = true;
  for (int i = 1; i < N + 1; i++) {
    int diff_time = t[i] - t[i - 1];
    int diff_coord = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);

    if ((diff_time < diff_coord) || (diff_coord % 2 != diff_time % 2)) {
      OK = false;
      break;
    }
  }

  if (OK) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
