// AC
// キャストと浮動小数点数の桁数指定出力
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int d = a / b;
  int r = a % b;
  double f = static_cast<double>(a) / static_cast<double>(b);

  printf("%d\n%d\n%.5lf\n", d, r, f);

  return 0;
}
