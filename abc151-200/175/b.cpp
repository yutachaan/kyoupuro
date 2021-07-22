// AC
// 与えられた辺で三角形を作ることができる場合の数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;

  // 入力
  int L[N];
  for (int i = 0; i < N; i++) cin >> L[i];
  sort(L, L + N); // 三角形の成立条件を簡潔にするためソート

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        if ((L[k] < L[i] + L[j]) && (L[j] != L[k]) && (L[i] != L[j])) ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
