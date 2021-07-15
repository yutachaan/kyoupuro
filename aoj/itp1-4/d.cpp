// AC
// 1行にN個の入力データがある場合の，それらの最小値，最大値，合計
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  int min = *min_element(a, a + n);
  int max = *max_element(a, a + n);
  long long int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];

  printf("%d %d %lld\n", min, max, sum);

  return 0;
}
