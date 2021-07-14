// AC
// 複数行の入力データの読み込み(一行のデータ数1)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, count = 0;
  while (true) {
    cin >> x;

    if (x == 0) break;

    count++;
    cout << "Case " << count << ": " << x << endl;
  }

  return 0;
}
