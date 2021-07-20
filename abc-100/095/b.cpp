// AC
// ドーナツをいくつ作れるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  int m[N], count = N;
  for (int i = 0; i < N; i++) {
    cin >> m[i];
    X -= m[i];   // 1種類につき必ず1つは作る
  }

  sort(m, m + N);
  count += X / m[0]; // 余った素で，使用する素が最も少ないドーナツを作る

  cout << count << endl;

  return 0;
}
