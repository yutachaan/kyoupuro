// AC
// 配列の降順ソート
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, p_alice = 0, p_bob = 0;
  cin >> N;

  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N, greater<int>());

  for (int i = 0; i < N; i += 2) p_alice += a[i];
  for (int i = 1; i < N; i += 2) p_bob += a[i];

  cout << p_alice - p_bob << endl;

  return 0;
}
