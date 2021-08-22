// AC
// N以下の正の奇数のうち，約数の個数が奇数のものの個数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i += 2) {
    int count = 0;

    // 約数を調べる
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        count++;
        if (i / j != j) count++; // sqrt(i)より大きい約数
      }
    }

    if (count == 8) ans++;
  }

  cout << ans << endl;

  return 0;
}
