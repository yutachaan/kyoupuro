#include <bits/stdc++.h>

using namespace std;

int main() {
  int S;
  cin >> S;

  int h, m, s;
  h = S / 3600;
  m = (S - h * 3600) / 60;
  s = S - h * 3600 - m * 60;

  cout << h << ":" << m << ":" << s << endl;

  return 0;
}
