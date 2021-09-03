// AC
// 自己ループと二重辺を含まないN頂点M辺の無向グラフについて，頂点1を始点として全ての頂点を1度だけ訪れるパスは何通りあるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  // 入力
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> edge;
  for (int j = 0; j < M; j++) {
    int v1, v2;
    cin >> v1 >> v2;

    edge.push_back({v1, v2});
    edge.push_back({v2, v1});
  }

  // 順列全探索(全てのパスの順番について検証する)
  int a[N], ans = 0;
  for (int i = 0; i < N; i++) a[i] = i + 1;
  do {
    // 始点は1のみのため，a[0]が1の場合のみ考える
    if (a[0] == 1) {
      int p[N]; // 順列を保存する配列
      for (int i = 0; i < N; i++) p[i] = a[i];

      bool OK = true; // 与えられた辺でそのようなパスがつくれるか
      for (int i = 1; i < N; i++) {
        pair<int, int> e = {p[i - 1], p[i]};
        int j;
        for (j = 0; j < M * 2; j++) {
          if (edge[j] == e) break;
        }

        if (j == M * 2) OK = false;
      }

      if (OK) ans++;
    }
  } while(next_permutation(a, a + N));

  cout << ans << endl;

  return 0;
}
