#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, C;
  cin >> a >> b >> C;

  double S, L, h, c;

  S = a * b * sin(C / 180.0 * M_PI) / 2;                               // 面積
  c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C / 180.0 * M_PI)); // 辺c長さ
  L = a + b + c;                                                       // 周の長さ
  h = 2 * S / a;                                                       // aを底辺とした時の高さ

  printf("%lf\n%lf\n%lf\n", S, L, h);

  return 0;
}
