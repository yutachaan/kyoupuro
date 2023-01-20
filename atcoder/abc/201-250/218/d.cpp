#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int x[N], y[N];
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // 4頂点のうち，左上の点と右下の点を決めれば，条件を満たす長方形は一意に定まる
      if ((i != j) && (x[i] < x[j]) && (y[i] > y[j])) {
        bool exist_bottom_left = false, exist_top_right = false;
        for (int k = 0; k < N; k++) {
          if ((x[k] == x[i]) && (y[k] == y[j])) exist_bottom_left = true;
          else if ((x[k] == x[j]) && (y[k] == y[i])) exist_top_right = true;
        }

        if (exist_bottom_left && exist_top_right) ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
