// AC
// char型による条件分岐
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    int a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '?') break;

    if (op == '+') cout << a + b << endl;
    else if (op == '-') cout << a - b << endl;
    else if (op == '*') cout << a * b << endl;
    else if (op == '/') cout << a / b << endl;
  }

  return 0;
}
