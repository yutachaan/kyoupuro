// AC
// リング状の文字列sに文字列pが含まれるか判定
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, p;
  cin >> s;
  cin >> p;

  // 循環なし(リングではない)の場合に含まれるか判定
  if (s.find(p) != string::npos) cout << "Yes" << endl;

  // 循環する場合に含まれるか判定
  else {
    int i;
    for (i = 0; i < s.size(); i++) {
      int start = i % s.size();                  // 初めのインデックス
      int end = (i + (p.size() - 1)) % s.size(); // 終わりのインデックス

      if (s.substr(start, s.size() - 1) + s.substr(0, end + 1) == p) {
        cout << "Yes" << endl;
        break;
      }
    }

    // 見つからずにfor文を抜けた場合No
    if (i == s.size()) cout << "No" << endl;
  }

  return 0;
}
