// AC
// 工夫した全探索
#include <bits/stdc++.h>

using namespace std;

int main() {
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cin >> c[i][j];
  }

  for (int a0 = 0; a0 <= 100; a0++) {
    for (int a1 = 0; a1 <= 100; a1++) {
      for (int a2 = 0; a2 <= 100; a2++) {
        int b0 = c[0][0] - a0;
        int b1 = c[0][1] - a0;
        int b2 = c[0][2] - a0;

        if ((b0 == c[1][0] - a1) && (b0 == c[2][0] - a2) && 
        (b1 == c[1][1] - a1) && (b1 == c[2][1] - a2) && 
        (b2 == c[1][2] - a1) && (b2 == c[2][2] - a2)) {
          cout << "Yes" << endl;

          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
