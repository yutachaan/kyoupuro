// AC
// チェック柄の長方形の出力
#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;
  string s, t;

  while (true) {
    cin >> H >> W;

    if ((H == 0) && (W == 0)) break;

    s = "";
    t = "";
    for (int i = 0; i < W / 2; i++) {
      s += "#.";
      t += ".#";
    }

    if (W % 2 == 0) {
      for (int i = 0; i < H / 2; i++) {
        cout << s << endl;
        cout << t << endl;
      }
      if (H % 2 != 0) cout << s << endl;
    }
    else {
      for (int i = 0; i < H / 2; i++) {
        cout << s << '#' << endl;
        cout << t << '.' << endl;
      }
      if (H % 2 != 0) cout << s << '#' << endl;
    }

    cout << endl;
  }

  return 0;
}
