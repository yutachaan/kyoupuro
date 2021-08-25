// AC
// ビット全探索の応用
#include <bits/stdc++.h>

using namespace std;

int main() {
  // 入力
  int N, M;
  cin >> N >> M;

  int k[M];
  vector<vector<int>> switches;
  for (int i = 0; i < M; i++) {
    cin >> k[i];

    vector<int> s(k[i]);
    for (int j = 0; j < k[i]; j++) cin >> s[j];
    switches.push_back(s);
  }

  int p[M];
  for (int i = 0; i < M; i++) cin >> p[i];

  // ビット全探索
  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    vector<int> condition(N); // onなら1，offなら0
    for (int h = 0; h < N; h++) {
      if (bit & (1 << h)) condition[h] = 1;
      else condition[h] = 0;
    }

    // 各電球について，条件を満たしているか調べる
    int OK = 0;
    for (int i = 0; i < M; i++) {
      // 電球iに繋がっているスイッチのうち，onになっている数を数える
      int n_on = 0;
      for (int j = 0; j < k[i]; j++) {
        if (condition[switches[i][j] - 1]) n_on++;
      }

      if (n_on % 2 == p[i]) OK++;
    }

    // すべての電球について条件が成り立つ場合
    if (OK == M) ans++;
  }

  cout << ans << endl;

  return 0;
}
