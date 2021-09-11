// AC
// 文字列SがHello,World!と完全に等しいか判定
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;

  if (S == "Hello,World!") cout << "AC" << endl;
  else cout << "WA" << endl;

  return 0;
}
