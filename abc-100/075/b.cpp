// AC
// グリッド処理
#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  char S[H + 2][W + 2];
  for (int i = 0; i < H + 2; i++) {
    for (int j = 0; j < W + 2; j++) S[i][j] = 'x';
  }
  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) cin >> S[i][j];
  }

  string T[H + 2][W + 2];
  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      if (S[i][j] == '.') {
        int ans = 0;

        if (S[i - 1][j - 1] == '#') ans++;
        if (S[i - 1][j] == '#') ans++;
        if (S[i - 1][j + 1] == '#') ans++;
        if (S[i][j - 1] == '#') ans++;
        if (S[i][j + 1] == '#') ans++;
        if (S[i + 1][j - 1] == '#') ans++;
        if (S[i + 1][j] == '#') ans++;
        if (S[i + 1][j + 1] == '#') ans++;

        T[i][j] = to_string(ans);
      }
      else T[i][j] = '#';
    }
  }

  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) cout << T[i][j];
    cout << endl;
  }

  return 0;
}

// 簡単なやり方
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int H, W;
//   cin >> H >> W;

//   char S[H][W];
//   for (int i = 0; i < H; i++) {
//     for (int j = 0; j < W; j++) cin >> S[i][j];
//   }

  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     if (S[i][j] == '.') {
  //       int ans = 0;

  //       for (int dx = -1; dx < 2; dx++) {
  //         for (int dy = -1; dy < 2; dy++) {
  //           if ((dx == 0) && (dy == 0)) continue;
  //           int xx = i + dx;
  //           int yy = j + dy;
  //           if ((xx >= 0) && (xx < H) && (yy >= 0) && (yy < W)) {
  //             if (S[xx][yy] == '#') ans++;
  //           }
  //         }
  //       }

  //       S[i][j] = char('0' + ans);
  //     }
  //   }
  // }

//   for (int i = 0; i < H; i++) {
//     for (int j = 0; j < W; j++) cout << S[i][j];
//     cout << endl;
//   }

//   return 0;
// }
