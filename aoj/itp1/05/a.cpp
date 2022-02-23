#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    int H, W;
    cin >> H >> W;

    if ((H == 0) && (W == 0)) break;

    for (int i = 0; i < H; i++) cout << string(W, '#') << endl;
    cout << endl;
  }

  return 0;
}
