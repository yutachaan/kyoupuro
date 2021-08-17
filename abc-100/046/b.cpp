// AC
// N個のボールをK色のペンキのいずれかで塗る時の場合の数(隣合ったボールは違う色とする)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // 1つ目のボールの色はK通り．以降は色が被らないように選ぶため，K-1通り
  int ans = K * pow(K - 1, N - 1);

  cout << ans << endl;

  return 0;
}
