#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) break;

    int s[n], sum = 0;
    double m, sd, rss = 0;

    for (int i = 0; i < n; i++) {
      cin >> s[i];
      sum += s[i]; // 合計
    }

    m = sum / static_cast<double>(n);                    // 平均
    for (int i = 0; i < n; i++) rss += pow(s[i] - m, 2); // 残差平方和
    sd = sqrt(rss / static_cast<double>(n));             // 標準偏差

    printf("%lf\n", sd);
  }

  return 0;
}
