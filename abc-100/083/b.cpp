// AC
// 10進法での各桁の和
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, A, B, ans = 0;
  cin >> N >> A >> B;

  for (int i = 1; i <= N; i++) {
    int x = i, sum = 0;
    while (true) {
      sum += x % 10;

      if (x < 10) break;
      x /= 10;
    }

    if ((sum >= A) && (sum <= B)) ans += i;
  }

  cout << ans << endl;

  return 0;
}
