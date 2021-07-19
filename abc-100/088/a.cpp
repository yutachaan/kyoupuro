// AC
// 持っている硬貨で支払い可能か
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  if (N % 500 <= A) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
