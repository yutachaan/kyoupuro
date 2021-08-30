// AC
// 順列全探索
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int coord[N][2];
  for (int i = 0; i < N; i++) cin >> coord[i][0] >> coord[i][1];

  // 順列全探索
  int a[N];
  for (int i = 0; i < N; i++) a[i] = i;

  double sum_length = 0, f = 0;
  do {
    // 経路を記録
    int path[N], p = 0;
    for (int i = 0; i < N; i++) {
      path[p] = a[i];
      p++;
    }

    for (int i = 1; i < N; i++) {
      sum_length += sqrt(pow(coord[path[i - 1]][0] - coord[path[i]][0], 2) + pow(coord[path[i - 1]][1] - coord[path[i]][1], 2));
    }

    f++;
  } while(next_permutation(a, a + N));

  double ave_length = sum_length / f;
  printf("%f\n", ave_length);

  return 0;
}
