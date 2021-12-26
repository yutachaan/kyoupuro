// WA(下はACコード)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N];
  long long int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  long long int X;
  cin >> X;

  long long int ans = (X / sum) * N + 1;
  X %= sum;
  for (int i = 0; i < N; i++) {
    if (X - A[i] < 0) break;

    X -= A[i];
    ans++;
  }

  cout << ans << endl;

  return 0;
}
