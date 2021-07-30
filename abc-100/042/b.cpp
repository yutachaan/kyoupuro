// AC
// 文字列配列のソート
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, L;
  cin >> N >> L;

  string S[N];
  for (int i = 0; i < N; i++) cin >> S[i];
  sort(S, S + N);

  string ans = "";
  for (int i = 0; i < N; i++) ans += S[i];

  cout << ans << endl;

  return 0;
}
