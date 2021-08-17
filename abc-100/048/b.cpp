// AC
// a以上b以下の整数のうち，xで割り切れるものの個数
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int a, b, x;
  cin >> a >> b >> x;

  long long int ans = 0;
  if (a == 0) ans = b / x + 1;
  else ans = b / x - (a - 1) / x;

  cout << ans << endl;

  return 0;
}
