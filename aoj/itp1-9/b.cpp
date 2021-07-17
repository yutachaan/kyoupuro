// AC
// 1つの単語をシャッフル(きる)
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    string S;
    cin >> S;

    if (S == "-") break;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
      int h;
      cin >> h;

      S = S.substr(h) + S.substr(0, h);
    }

    cout << S << endl;
  }

  return 0;
}
