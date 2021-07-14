// AC
// 1〜nまでで，3の倍数と3が含まれる数を出力
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      cout << ' ' << i;
      continue;
    }

    x = i;
    while (x != 0) {
      if (x % 10 == 3) {
        cout << ' ' << i;
        break;
      }
      x /= 10;
    }
  }

  cout << endl;

  return 0;
}
