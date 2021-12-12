#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, set<int>> neighbors;
  for (int j = 0; j < M; j++) {
    int A, B;
    cin >> A >> B;

    neighbors[A].insert(B);
    neighbors[B].insert(A);
  }

  int count_2 = 0;
  bool ans = true;
  for(auto i = neighbors.begin(); i != neighbors.end(); i++) {
    // 隣人が3人以上いたらNo
    if (i->second.size() > 2) {
      ans = false;
      break;
    }
    else if (i->second.size() == 2) count_2++;
  }

  // 全員が隣人が2人いたらNo(円でないとこのパターンは成り立たない) このパターンは下のパターンに包含される
  if (count_2 == N) ans = false;

  // 隣人が2人以上おり，かつその中の2人が隣同士になりたい場合はNo (TLEしないコードがおもいつかなくて鬱) → Union-Findのissameでいける
  // 例) 1の隣に2と3がおり，2と3も隣同士になりたい場合
  // 5 4
  // 1 2
  // 1 3
  // 2 3
  // 4 5

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
