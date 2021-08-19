// AC
// bit全探索
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;

  char pat[8][3] = {{'+', '+', '+'}, {'+', '+', '-'}, {'+', '-', '+'}, {'+', '-', '-'},
                   {'-', '+', '+'}, {'-', '+', '-'}, {'-', '-', '+'}, {'-', '-', '-'}};

  for (int i = 0; i < 8; i++) {
    int ans = S[0] - '0';

    for (int j = 0; j < 3; j++) {
      if (pat[i][j] == '+') ans += S[j + 1] - '0';
      else ans -= S[j + 1] - '0';
    }

    if (ans == 7) {
      cout << S[0] << pat[i][0] << S[1] << pat[i][1] << S[2] << pat[i][2] << S[3] << "=7" << endl;
      break;
    }
  }

  return 0;
}

// 模範
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   string S;
//   cin >> S;

//   for (int msk = 0; msk < (1 << 3); msk++) {
//     int sm = S[0] - '0';
//     for (int i = 0; i < 3; i++) {
//       if (msk & (1 << i)) sm += S[i + 1] - '0';
//       else sm -= S[i + 1] - '0';
//     }

//     if (sm == 7) {
//       cout << S[0];
//       for (int i = 0; i < 3; i++) {
//         if (msk & (1 << i)) cout << '+';
//         else cout << '-';
//         cout << S[i + 1];
//       }
//       cout << "=7" << endl;

//       return 0;
//     }
//   }

//   return 0;
// }
