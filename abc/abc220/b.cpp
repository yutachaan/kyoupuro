// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int K;
  string A, B;
  cin >> K >> A >> B;

  long long int d_A = 0, d_B = 0;
  for (int i = A.size() - 1; i >= 0; i--) d_A += (A[i] - '0') * pow(K, A.size() - 1 - i);
  for (int i = B.size() - 1; i >= 0; i--) d_B += (B[i] - '0') * pow(K, B.size() - 1 - i);

  long long int ans = d_A * d_B;
  printf("%lld\n", ans);

  return 0;
}
