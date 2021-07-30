// AC
// 配列のソート
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, x;
  cin >> N >> x;

  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    // お菓子を全て配るか，N人全員に希望の数配り終わったら終了
    if (x <= 0) break;

    x -= a[i];
    ans++;
  }

  if (x == 0) cout << ans << endl; // ジャストで配り終えた場合
  else cout << ans - 1 << endl;    // 希望以下の個数しかもらえなかったか，希望以上の個数を押し付けられた子供がいた場合

  return 0;
}
