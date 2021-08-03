// AC
// N=AxBを満たすA, Bの組
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int N;
  cin >> N;

  int ans = 100;
  // 約数列挙の流れでやればよい
  for (long long int A = 1; A * A <= N; A++) {
    if (N % A == 0) {
      // 明らかにAのほうが桁数が小さいため，Bについてのみ考える
      int B = N / A;
      int len_B = to_string(B).size();

      if (len_B < ans) ans = len_B;
    }
  }
  cout << ans << endl;

  return 0;
}
