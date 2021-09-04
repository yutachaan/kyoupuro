// AC
// 文字列操作
#include <bits/stdc++.h>

using namespace std;

int main() {
  string XY;
  cin >> XY;

  string X = XY.substr(0, XY.length() - 2);
  int Y = XY[XY.length() - 1] - '0';

  if ((Y >= 0) && (Y <= 2)) X += '-';
  if ((Y >= 7) && (Y <= 9)) X += '+';

  cout << X << endl;

  return 0;
}
