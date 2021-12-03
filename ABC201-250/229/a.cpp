// 条件分岐
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S[2];
  cin >> S[0] >> S[1];

  if (((S[0][0] == '#') && (S[1][1] == '#') && (S[0][1] == '.') && (S[1][0] == '.')) ||
  ((S[0][1] == '#') && (S[1][0] == '#') && (S[0][0] == '.') && (S[1][1] == '.'))) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }

  return 0;
}
