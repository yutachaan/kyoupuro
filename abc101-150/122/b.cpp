// AC
// Sの部分文字列のなかでACGTのみを含むものの最大の長さ
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  S += ' ';

  int ans = 0, len = 0;
  for (int i = 0; i < S.size() + 1; i++) {
    if ((S[i] == 'A') || (S[i] == 'C') || (S[i] == 'G') || (S[i] == 'T')) len++;
    else {
      if (len > ans) ans = len;
      len = 0;
    }
  }

  cout << ans << endl;

  return 0;
}
