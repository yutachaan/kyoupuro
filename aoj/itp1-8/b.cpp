// AC
// 数字の各桁の和の計算
#include <bits/stdc++.h>

using namespace std;

int main() {
  string num;
  int sum;

  while (true) {
    cin >> num;

    if (num == "0") break;

    sum = 0;
    for (int i = 0; i < num.size(); i++) sum += num[i] - '0';

    cout << sum << endl;
  }

  return 0;
}
