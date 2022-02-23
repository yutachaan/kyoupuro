#include <bits/stdc++.h>

using namespace std;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  double distance = sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2));

  printf("%lf\n", distance);

  return 0;
}
