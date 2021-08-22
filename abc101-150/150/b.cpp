// AC
// 文字列中にABCがいくつ含まれるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 0; i < N - 2; i++) {
    if (S[i] == 'A') {
      if ((S[i + 1] == 'B') && (S[i + 2] == 'C')) {
        ans++;
        i += 2;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
