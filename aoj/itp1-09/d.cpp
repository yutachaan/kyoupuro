#include <bits/stdc++.h>

using namespace std;

int main() {
  string str;
  int q;
  cin >> str;
  cin >> q;

  for (int i = 0; i < q; i++) {
    string command;
    int a, b;
    cin >> command >> a >> b;

    if (command == "print") cout << str.substr(a, b - a + 1) << endl;
    else if (command == "reverse") {
      string temp  =  str.substr(a, b - a + 1);          // 逆順にする部分
      reverse(temp.begin(), temp.end());
      str = str.substr(0, a) + temp + str.substr(b + 1);
    }
    else if (command == "replace") {
      string p;
      cin >> p;

      str.replace(a, b - a + 1, p);
    }
  }

  return 0;
}
