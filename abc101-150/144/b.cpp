// AC
// 与えられた数が九九に含まれるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  bool OK = false;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i * j == N) OK = true;
    }
  }

  if (OK) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
