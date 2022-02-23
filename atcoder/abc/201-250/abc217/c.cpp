// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int Q[N];
  for (int i = 0; i < N; i++) {
    int P;
    cin >> P;

    Q[P - 1] = i + 1;
  }

  for (int i = 0; i < N - 1; i++) cout << Q[i] << ' ';
  cout << Q[N - 1] << endl;

  return 0;
}
