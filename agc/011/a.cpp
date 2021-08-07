// AC
// 空港バスの最小発車本数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;

  int T[N];
  for (int i = 0; i < N; i++) cin >> T[i];
  sort(T, T + N);

  int ans = 0;
  long long int t_bottom, t_top, c_ride;
  for (int i = 0; i < N; i++) {
    t_bottom = T[i];   // バスの発車時間の範囲の下端
    t_top = T[i] + K;  // バスの発車時刻の範囲の上端
    c_ride = 1;        // 現在の乗車人数

    // 乗せられるだけ乗せる
    while (c_ride < C) {
      // 発車時刻の範囲に到着時刻が収まっている場合，乗客を乗せる
      if (T[i + 1] <= t_top) {
        t_bottom = T[i + 1]; // 下端を更新(範囲が狭くなる)
        c_ride++;
        i++;
      }
      else break;
    }

    ans++;
  }

  cout << ans << endl;

  return 0;
}


