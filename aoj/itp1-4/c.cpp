// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  char op;

  while (true) {
    cin >> a >> op >> b;

    if (op == '?') break;

    if (op == '+') cout << a + b << endl;
    else if (op == '-') cout << a - b << endl;
    else if (op == '*') cout << a * b << endl;
    else if (op == '/') cout << a / b << endl;
  }

  return 0;
}
