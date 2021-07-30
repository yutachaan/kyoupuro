// WA
// チームメンバーの強さのうち2番目に大きい値をチームの強さとした場合のN組のチームの強さの和の最大値
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int a[3 * N];
  for (int i = 0; i < 3 * N; i++) cin >> a[i];
  sort(a, a + (3 * N));

  long long int ans = 0;
  for (int i = N; i < N + N; i += 1) ans += a[i];

  printf("%lld\n", ans);

  return 0;
}

// AC
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int N;
//   cin >> N;

//   int a[3 * N];
//   for (int i = 0; i < 3 * N; i++) cin >> a[i];
//   sort(a, a + (3 * N), greater<int>());

//   long long int ans = 0;
//   for (int i = 1; i < 2 * N; i += 2) ans += a[i];

//   printf("%lld\n", ans);

//   return 0;
// }
