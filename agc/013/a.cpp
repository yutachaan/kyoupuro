// AC
// 配列Aを，単調増加か単調減少になるようないくつかの数列にわけるとき，最小で何個にわければよいか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = 0;
  for (int i = 0; i < N;) {
    // 広義単調増加の数列としてわける場合の数列の長さを調べる
    int j = i + 1;
    while (A[j - 1] <= A[j]) j++;

    // 広義単調減少の数列としてわける場合の数列の長さを調べる
    int k = i + 1;
    while (A[k - 1] >= A[k]) k++;

    // より数列の長さが長い方法でわける
    if (j > k) i += j - i;
    else i += k - i;

    ans++;
  }

  cout << ans << endl;

  return 0;
}
