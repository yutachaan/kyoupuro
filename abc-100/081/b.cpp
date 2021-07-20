// AC
// 「偶数なら2で割る」という操作を何回繰り返せるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N], count = 0;
  for (int i = 0; i < N; i++) cin >> A[i];

  while (true) {
    int i;
    for (i = 0; i < N; i++) {
      if (A[i] % 2 == 0) A[i] /= 2;
      else break;
    }

    if (i == N) count++;
    else break;
  }

  cout << count << endl;

  return 0;
}
