// RE，WA(イテレータ用変数がただのintになっていた)
// 塗り絵，塗る範囲工夫
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int N, A, B, P, Q, R, S;
  cin >> N >> A >> B >> P >> Q >> R >> S;

  // 白埋め
  char ans[Q - P + 1][S - R + 1];
  for (int i = 0; i < Q - P + 1; i++) {
    for (int j = 0; j < S - R + 1; j++) ans[i][j] = '.';
  }

  long long int lower_1 = max({1 - A, 1 - B, P - A, R - B});
  long long int upper_1 = min({N - A, N - B, Q - A, S - B});
  long long int lower_2 = max({1 - A, B - N, P - A, B - S});
  long long int upper_2 = min({N - A, B - 1, Q - A, B - R});

  for (long long int k = lower_1; k <= upper_1; k++) ans[A + k - P][B + k - R] = '#';
  for (long long int k = lower_2; k <= upper_2; k++) ans[A + k - P][B - k - R] = '#';

  // 出力
  for (int i = 0; i < Q - P + 1; i++) {
    for (int j = 0; j < S - R + 1; j++) cout << ans[i][j];
    cout << endl;
  }

  return 0;
}
