#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, p_taro = 0, p_hanako = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string taro, hanako;
    cin >> taro >> hanako;

    if (taro == hanako) {
      p_taro++;
      p_hanako++;
    }
    else if (taro > hanako) p_taro += 3;
    else p_hanako += 3;
  }

  cout << p_taro << ' ' << p_hanako << endl;

  return 0;
}
