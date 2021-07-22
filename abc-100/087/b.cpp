// AC
// 所持している500円玉，100円玉，50円玉でX円をつくる場合の数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, X, ans = 0;
  cin >> A >> B >> C >> X;

  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      for (int k = 0; k <= C; k++) {
        if (i * 500 + j * 100 + k * 50 == X) ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
