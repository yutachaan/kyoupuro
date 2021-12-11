// AC
// 指数計算
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  long long int ans = pow(32, A - B);

  cout << ans << endl;

  return 0;
}
