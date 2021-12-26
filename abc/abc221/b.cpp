// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  if (S == T) {
    cout << "Yes" << endl;
    return 0;
  }

  for (int i = 1; i < S.size(); i++) {
    string swap_S = S;
    swap_S[i - 1] = S[i];
    swap_S[i] = S[i - 1];

    if (swap_S == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
