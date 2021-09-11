// AC(解答見た)
// 2^k <= N となる最大の整数k
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int N;
  cin >> N;

  int k = log2(static_cast<long double>(N));

  cout << k << endl;

  return 0;
}
