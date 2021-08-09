// AC(解説のみ見た)
// 貪欲法
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  long long int ans_plus = 0, ans_minus = 0, sum = 0;

  // 偶数番目が負の場合
  for (int i = 0; i < n; i++) {
    long long int temp = sum + a[i];
    if ((i % 2 == 0) && (temp >= 0)) {
      ans_minus += abs(1 + temp);
      sum = -1;
    }
    else if ((i % 2 != 0) && (temp <= 0)) {
      ans_minus += abs(1 - temp);
      sum = 1;
    }
    else sum += a[i];
  }

  // 偶数番目が正の場合
  sum = 0;
  for (int i = 0; i < n; i++) {
    long long int temp = sum + a[i];
    if ((i % 2 == 0) && (temp <= 0)) {
      ans_plus += abs(1 - temp);
      sum = 1;
    }
    else if ((i % 2 != 0) && (temp >= 0)) {
      ans_plus += abs(1 + temp);
      sum = -1;
    }
    else sum += a[i];
  }

  if (ans_minus < ans_plus) cout << ans_minus << endl;
  else cout << ans_plus << endl;

  return 0;
}
