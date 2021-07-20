// AC
// 1以上N以下の整数で，最も2で割れる回数が多いもの
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, ans, max_count = 0;
  cin >> N;

  // 奇数の場合2で割り切れないため偶数の場合だけ考える
  for (int i = 2; i <= N; i += 2) {
    int count = 0;
    int x = i;
    // 割り切れるたびにカウント
    while (true) {
      if (x % 2 == 0) count++;
      else break;

      x /= 2;
    }

    if (count > max_count) {
      max_count = count;
      ans = i;
    }
  }

  if (max_count == 0) cout << 1 << endl;
  else cout << ans << endl;

  return 0;
}
