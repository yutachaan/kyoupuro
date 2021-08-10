// AC(解答見た)
// パリティ
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N[3];
  cin >> N[0] >> N[1] >> N[2];
  sort(N, N + 3, greater<int>());

  int odd = 0, even = 0;
  for (int i = 0; i < 3; i++) {
    if (N[i] % 2 == 0) even++;
    else odd++;
  }

  int ans = 0;

  // 3つの数字の偶奇を合わせる(2つの数字に+1をすれば必ず揃う)
  if (odd == 2) {
    for (int i = 0; i < 3; i++) {
      if (N[i] % 2 != 0) N[i]++;
    }
    ans++;
  }
  else if (even == 2) {
    for (int i = 0; i < 3; i++) {
      if (N[i] % 2 == 0) N[i]++;
    }
    ans++;
  }

  // 3つの数字の中で最大のものと同じになるまでそれぞれの数字を+2する
  ans += N[0] - ((N[1] + N[2]) / 2);

  cout << ans << endl;

  return 0;
}
