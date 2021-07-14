// AC
// 3つの整数の大小比較
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if ((a < b) && (b < c)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
