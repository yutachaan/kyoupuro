// AC
// i18nの規則で文字列を変換
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int length = s.size();

  cout << s[0] + to_string(length - 2) + s[length - 1] << endl;

  return 0;
}
