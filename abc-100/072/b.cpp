// AC
// 文字列の奇数文字目だけ抜き出した文字列の作成
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, ans = "";
  cin >> s;

  for (int i = 0; i < s.size(); i += 2) ans += s[i];

  cout << ans << endl;

  return 0;
}
