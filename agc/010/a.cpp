// AC
// パリティ
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int A, odd = 0;
  for (int i = 0; i < N; i++) {
    cin >> A;

    if (A % 2 != 0) odd++;
  }

  // 偶数と奇数の加算の性質より，黒板に書かれている奇数の数が偶数なら必ず条件を満たす
  if (odd % 2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
