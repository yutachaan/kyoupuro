#define _GLIBCXX_DEBUG

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

// <----- rep macro ----->
#define rep(i, a, b)  for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= (int)(b); i--)
#define fore(e, x) for (auto &&(e): x)
#define fore2(k, v, x) for (auto &&[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << "\n"
#define yesno(n) cout << ((n) ? "yes" : "no") << "\n"
#define YesNo(n) cout << ((n) ? "Yes" : "No") << "\n"

// <----- function ----->
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {a = b; return true;}
  return false;
}


int main() {
  int H, W; cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  rep(i, 0, H) rep(j, 0, W) cin >> a[i][j];

  // 省く行番号と列番号を調べる
  set<int> ignore_i, ignore_j;
  rep(i, 0, H) {
    bool white = true;
    rep(j, 0, W) {
      if (a[i][j] == '#') white = false;
    }
    if (white) ignore_i.insert(i);
  }
  rep(j, 0, W) {
    bool white = true;
    rep(i, 0, H) {
      if (a[i][j] == '#') white = false;
    }
    if (white) ignore_j.insert(j);
  }

  // ignore_iとignore_jに含まれる行や列を省いて出力
  rep(i, 0, H) {
    if (ignore_i.find(i) != end(ignore_i)) continue;

    rep(j, 0, W) {
      if (ignore_j.find(j) != end(ignore_j)) continue;

      cout << a[i][j];
    }

    cout << endl;
  }
}
