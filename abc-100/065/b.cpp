// AC
// 状態ループシミュレーション
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  bool is_loop[N]; // 通ったかどうか
  for (int i = 0; i < N; i++) is_loop[i] = false;

  int i = 0, ans = 0;
  while (true) {
    // 既に通っていたらループが発生するためbreak
    if (is_loop[i] == true) {
      ans = -1;
      break;
    }

    ans++;

    if (a[i] == 2) break;

    is_loop[i] = true;
    i = a[i] - 1;
  }

  cout << ans << endl;

  return 0;
}
