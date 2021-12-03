// ゼロ埋め
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  if (N >= 42) cout << "AGC" << setfill('0') << right << setw(3) << N + 1 << endl;
  else cout << "AGC" << setfill('0') << right << setw(3) << N << endl;

  return 0;
}
