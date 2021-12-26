// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S1, S2, S3, T;
  cin >> S1 >> S2 >> S3 >> T;

  string ans;
  for (int i = 0; i < T.size(); i++) {
    if (T[i] == '1') ans += S1;
    else if (T[i] == '2') ans += S2;
    else ans += S3;
  }

  cout << ans << endl;

  return 0;
}
