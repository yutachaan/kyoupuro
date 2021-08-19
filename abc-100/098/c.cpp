// AC
// 累積和
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int n_W[N + 1] = {0}, n_E[N + 1] = {0}; // i人目よりも左にW, Eが何人いるか
  for (int i = 1; i < N + 1; i++) {
    if (S[i - 1] == 'W') {
      n_W[i] = n_W[i - 1] + 1;
      n_E[i] = n_E[i - 1];
    }
    else {
      n_E[i] = n_E[i - 1] + 1;
      n_W[i] = n_W[i - 1];
    }
  }

  int ans = 310000;
  for (int i = 0; i < N; i++) {
    // i人目より左にいるWを向いている人数 + i人目より右にいるEを向いている人数が，向いている方向を変えなければならない
    int count = n_W[i] + (n_E[N] - n_E[i + 1]);

    if (count < ans) ans = count;
  }

  cout << ans << endl;

  return 0;
}
