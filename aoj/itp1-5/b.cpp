// AC
// 枠の出力
#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;

  while (true) {
    cin >> H >> W;

    if ((H == 0) && (W == 0)) break;

    cout << string(W, '#') << endl;
    for (int i = 0; i < H - 2; i++) cout << '#' << string(W - 2, '.') << '#' << endl;
    cout << string(W, '#') << endl << endl;
  }

  return 0;
}
