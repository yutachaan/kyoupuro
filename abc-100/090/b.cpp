// AC
// 回文数判定(5桁固定)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, ans = 0;
  cin >> A >> B;

  for (int i = A; i <= B; i++) {
    string si = to_string(i);

    // 1文字目と5文字目，2文字目と4文字目が同じなら回文数
    if ((si[0] == si[4]) && (si[1] == si[3])) ans++;
  }

  cout << ans << endl;

  return 0;
}
