// WA(67行目の初期化を忘れていたためREになってた)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  string S[N], T[N];
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < N; i++) cin >> T[i];

  for (int count = 0; count < 4; count++) {
    // S, Tそれぞれについて，#が現れる最初の行，列を調べる
    int xx_S = N, yy_S = N, xx_T = N, yy_T = N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (S[i][j] == '#') {
          if (i < xx_S) xx_S = i;
          if (j < yy_S) yy_S = j;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (T[i][j] == '#') {
          if (i < xx_T) xx_T = i;
          if (j < yy_T) yy_T = j;
        }
      }
    }

    // #の図形を可能な限り左上に詰めた新しいグリッドを作る(これが平行移動にあたる)
    string S2[N];
    for (int i = 0; i < N; i++) S2[i] = string(N, '.');

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (S[i][j] == '#') S2[i - xx_S][j - yy_S] = '#';
      }
    }

    string T2[N];
    for (int i = 0; i < N; i++) T2[i] = string(N, '.');

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (T[i][j] == '#') T2[i - xx_T][j - yy_T] = '#';
      }
    }

    // 一致するか調べる
    bool ok = true;
    for (int i = 0; i < N; i++) {
      if (S2[i] != T2[i]) ok = false;
    }

    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }

    // 90度右に回転させる(Sだけでいい)
    string S_temp[N];
    for (int i = 0; i < N; i++) S_temp[i] = string(N, ' ');

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) S_temp[j][N - i - 1] = S[i][j];
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) S[i][j] = S_temp[i][j];
    }
  }

  cout << "No" << endl;

  return 0;
}
