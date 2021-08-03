// AC(解法のみ見た https://img.atcoder.jp/abc112/editorial.pdf)
// ピラミッドの中心座標と高さを求める
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int x[N], y[N], h[N];
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];

  for (int X = 0; X <= 100; X++) {
    for (int Y = 0; Y <= 100; Y++) {
      int H;
      for (int i = 0; i < N; i++) {
        // h[i] >= 1を満たすi番目の情報と，X，YからHを定める
        if (h[i] >= 1) {
          H = h[i] + abs(x[i] - X) + abs(y[i] - Y);
          break;
        }
      }

      // 各情報が条件を満たすか調べる
      bool isOK = true;
      for (int i = 0; i < N; i++) {
        if (max(H - abs(x[i] - X) - abs(y[i] - Y), 0) != h[i]) isOK = false;
      }

      // 全ての情報が条件を満たした場合，そのときの中心座標と高さを出力
      if (isOK) {
        printf("%d %d %d\n", X, Y, H);
        return 0;
      }
    }
  }
}
