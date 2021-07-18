// AC
// 1からnまでで和がxとなる組み合わせ
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    int n, x;
    cin >> n >> x;

    if ((n == 0) && (x == 0)) break;

    int count = 0;
    bool a[n];
    for (int i = 0; i < n; i++) a[i] = false;

    // 組み合わせ
    fill(a, a + 3, true);
    do {
      int temp = 0;
      for (int i = 0; i < n; i++) {
        if (a[i]) temp += i + 1;
      }

      if (temp == x) count++;
    } while (prev_permutation(a, a + n));

    cout << count << endl;
  }

  return 0;
}
