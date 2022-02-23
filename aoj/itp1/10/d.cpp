#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int x[n], y[n];
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];

  double p_1 = 0, p_2 = 0, p_3 = 0, p_infinity = 0, d;

  for (int i = 0; i < n; i++) {
    d = fabs(x[i] - y[i]);
    p_1 += d;
    p_2 += pow(d, 2);
    p_3 += pow(d, 3);

    if (d > p_infinity) p_infinity = d;
  }

  p_2 = pow(p_2, 1.0 / 2);
  p_3 = pow(p_3, 1.0 / 3);

  printf("%lf\n%lf\n%lf\n%lf\n", p_1, p_2, p_3, p_infinity);

  return 0;
}
