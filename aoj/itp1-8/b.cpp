// AC
// 数字の各桁の和の計算
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    string num;
    cin >> num;

    if (num == "0") break;

    int sum = 0;
    for (int i = 0; i < num.size(); i++) sum += num[i] - '0';

    cout << sum << endl;
  }

  return 0;
}
