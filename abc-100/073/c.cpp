// AC
// mapを用いたバケット法
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, int> bucket;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;

    if (bucket[A] == 0) {
      bucket[A] = 1;
      ans++;
    }
    else {
      bucket[A] = 0;
      ans--;
    }
  }

  cout << ans << endl;

  return 0;
}
