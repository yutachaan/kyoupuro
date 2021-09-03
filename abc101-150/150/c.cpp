// AC
// 与えられた大きさNの順列が，大きさNのすべての順列の中で何番目に小さいか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int P[N], Q[N];
  for (int i = 0; i < N; i++) cin >> P[i];
  for (int i = 0; i < N; i++) cin >> Q[i];

  // 順列全探索
  int temp[N], a, b, count = 0;
  for (int i = 0; i < N; i++) temp[i] = i + 1;
  do {
    bool P_OK = true, Q_OK = true; // tempとP(Q)が等しいかどうか
    count++;                       // 何番目の順列か
    for (int i = 0; i < N; i++) {
      if (P[i] != temp[i]) P_OK = false;
      if (Q[i] != temp[i]) Q_OK = false;
    }

    if (P_OK) a = count;
    if (Q_OK) b = count;
  } while(next_permutation(temp, temp + N));

  cout << abs(a - b) << endl;

  return 0;
}
