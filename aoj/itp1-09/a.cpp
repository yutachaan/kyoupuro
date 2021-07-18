// AC
// 文章にある単語が何個含まれているか
#include <bits/stdc++.h>

using namespace std;

int main() {
  string W;
  cin >> W;

  int count = 0;

  while (true) {
    string T;
    cin >> T;

    if (T == "END_OF_TEXT") break;

    transform(T.begin(), T.end(), T.begin(), ::tolower); //Tを小文字化
    if (T == W) count++;
  }

  cout << count << endl;

  return 0;
}
