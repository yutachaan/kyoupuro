// AC
// 空文字列Tに指定された文字列のいずれかを追加する操作を繰り返して，Sを作れるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S, T;
  cin >> S;

  // 前からだとprefixがあるため，後ろから調べる
  bool OK = true;
  int i = S.size();
  while ((i >= 5) && OK) {
    if ((i - 6 >= 0) && (S.substr(i - 6, 6) == "eraser")) i -= 6;
    else if ((i - 5 >= 0) && (S.substr(i - 5, 5) == "erase")) i -= 5;
    else if ((i - 7 >= 0) && (S.substr(i - 7, 7) == "dreamer")) i -=7;
    else if ((i - 5 >= 0) && (S.substr(i - 5, 5) == "dream")) i -=5;
    else OK = false;
  }

  if (OK) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
