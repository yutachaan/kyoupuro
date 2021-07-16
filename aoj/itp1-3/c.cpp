// AC
// 複数行の入力データの読み込み(一行のデータ数2)
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    int x, y;
    cin >> x >> y;

    if ((x == 0) && (y == 0)) break;

    if (x < y) cout << x << " " << y << endl;
    else cout << y << " " << x << endl;
  }

  return 0;
}
