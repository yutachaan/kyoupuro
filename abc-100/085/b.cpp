// AC
// 被りなしで何個あるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int d[N];
  for (int i = 0; i < N; i++) cin >> d[i];
  sort(d, d + N);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (d[i] != d[i - 1]) ans++;
  }

  cout << ans << endl;

  return 0;
}
