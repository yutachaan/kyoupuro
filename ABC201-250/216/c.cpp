// わからなかったから解答見た
// パリティ
#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int N;
  cin >> N;

  string S;
  while (N > 0) {
    if (N % 2 == 0) {
      S += 'B';
      N /= 2;
    }
    else {
      S += 'A';
      N--;
    }
  }

  reverse(S.begin(), S.end());

  cout << S << endl;

  return 0;
}
