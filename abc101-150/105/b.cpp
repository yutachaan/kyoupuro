// AC
// 値段の異なる商品をそれぞれ任意個かって合計Nドルにできるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  bool exist = false;
  for (int i = 0; i <= N / 4; i++) {
    for (int j = 0; j <= N / 7; j++) {
      if (i * 4 + j * 7 == N) {
        exist = true;
        break;
      }
    }
    if (exist) break;
  }

  if (exist) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
