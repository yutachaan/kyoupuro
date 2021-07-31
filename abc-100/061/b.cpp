// AC
// バケット法
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int n_road[N];
  for (int i = 0; i < N; i++) n_road[i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    n_road[a - 1]++;
    n_road[b - 1]++;
  }

  for (int i = 0; i < N; i++) cout << n_road[i] << endl;

  return 0;
}
