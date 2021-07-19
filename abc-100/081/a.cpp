// AC
// 3桁の数字に1がいくつ含まれるか
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int count = 0;
  cin >> s;

  for (int i = 0; i < 3; i++) {
    if (s[i] == '1') count++;
  }

  cout << count << endl;

  return 0;
}
