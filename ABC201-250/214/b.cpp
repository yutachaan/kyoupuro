// AC
// a+b+c<=S, a*b*c<=Tを満たす(a, b, c)の数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int S, T;
  cin >> S >> T;

  int ans = 0;
  for (int a = 0; a <= 100; a++) {
    for (int b = 0; b <= 100; b++) {
      for (int c = 0; c <= 100; c++) {
        if ((a + b + c <= S) && (a * b * c <= T)) ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}

// 以下の方がより効率的
// #include<bits/stdc++.h>

// using namespace std;

// int main() {
//   int S, T;
//   cin >> S >> T;

//   int ans = 0;
//   for (int a = 0; a <= S; a++) {
//     for (int b = 0; a + b <= S; b++) {
//       for (int c = 0; a + b + c <= S; c++) {
//         if (a * b * c <= T) ans++;
//       }
//     }
//   }

//   cout << ans << endl;
// }
