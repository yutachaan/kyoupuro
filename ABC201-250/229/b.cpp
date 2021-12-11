// AC
// 繰り上がりがあるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  string A, B;
  cin >> A >> B;

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  for (int i = 0; i < min(A.size(), B.size()); i++) {
    if ((A[i] - '0') + (B[i] - '0') >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
  }

  cout << "Easy" << endl;

  return 0;
}
