// AC
// 2つの文字列のアナグラムの大小比較
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  sort(s.begin(), s.end());                  // sを昇順に並び替える
  sort(t.begin(), t.end(), greater<char>()); // tを降順に並び替える

  if (s < t) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
