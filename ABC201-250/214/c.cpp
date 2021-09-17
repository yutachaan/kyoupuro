// WA(全部)
// 動的計画法的な
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int N;
//   cin >> N;

//   int S[N], T[N];
//   for (int i = 0; i < N; i++) cin >> S[i];
//   for (int i = 0; i < N; i++) cin >> T[i];

//   long long int get_jewel[N]; // 宝石を取得した時刻の最小値
//   for (int i = 0; i < N; i++) get_jewel[i] = 100000000000;
//   for (int i = 0; i < N; i++) {
//     if (T[i] < get_jewel[i]) {
//       get_jewel[i] = T[i];

//       int sum_S = T[i] + S[i], j = (i + 1) % N;
//       for (int count = 0; count < N; count++) {
//         if (sum_S < get_jewel[j % N]) get_jewel[j % N] = sum_S;
//         else break;

//         sum_S += S[j % N];
//         j++;
//       }
//     }
//   }

//   for (int i = 0; i < N; i++) cout << get_jewel[i] << endl;

//   return 0;
// }

// AC(https://atcoder.jp/contests/abc214/editorial/2438)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int S[N], T[N];
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < N; i++) cin >> T[i];

  int ans[N];
  for (int i = 0; i < N; i++) ans[i] = T[i];
  for (int i = 0; i < 2 * N; i++) ans[(i + 1) % N] = min(ans[(i + 1) % N], ans[i % N] + S[i % N]);

  for (int i = 0; i < N; i++) cout << ans[i] << endl;

  return 0;
}
