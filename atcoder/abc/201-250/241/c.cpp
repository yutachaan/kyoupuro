#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int, int>;

#define endl "\n";

// <----- rep macro ----->
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define fore(e, x) for (auto &&(e): x)
#define fore2(k, v, x) for (auto &&[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << "\n"
#define yesno(n) cout << ((n) ? "yes" : "no") << "\n"
#define YesNo(n) cout << ((n) ? "Yes" : "No") << "\n"

// <----- function ----->
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {a = b; return true;}
  return false;
}


int main() {
  int N; cin >> N;
  vs S(N);
  fore(s, S) cin >> s;

  bool ans = false;
  rep(i, 0, N) rep(j, 0, N) {
    // 下方向に6マス見て， 白のマスが2つ以内ならそれを塗り替えることで黒を6つ連続させられる
    if (i + 5 < N) {
      int white = 0;
      rep(d, 0, 6) if (S[i + d][j] == '.') white++;
      if (white <= 2) ans = true;
    }
    // 右方向に6マスで同様に
    if (j + 5 < N) {
      int white = 0;
      rep(d, 0, 6) if (S[i][j + d] == '.') white++;
      if (white <= 2) ans = true;
    }
    // 斜め右下方向に6マス
    if (i + 5 < N && j + 5 < N) {
      int white = 0;
      rep(d, 0, 6) if (S[i + d][j + d] == '.') white++;
      if (white <= 2) ans = true;
    }
    // 斜め右上方向に6マス
    if (i - 5 >= 0 && j + 5 < N) {
      int white = 0;
      rep(d, 0, 6) if (S[i - d][j + d] == '.') white++;
      if (white <= 2) ans = true;
    }
  }

  YesNo(ans);

  return 0;
}
