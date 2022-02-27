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
  int n; cin >> n;
  vs s(n);
  fore(e, s) cin >> e;

  bool ans = false;
  // あるマスを基準として， 縦方向6マスまたは横方向6マスまたは斜め方向6マスに白いマスが4つ以上あるなら，true
  rep(i, 0, n) rep(j, 0, n) {
    // 下に6マス
    if (i + 5 < n) {
      int c = 0;
      rep(k, 0, 6) if (s[i + k][j] == '#') c++;
      if (c >= 4) ans = true;
    }
    // 右に6マス
    if (j + 5 < n) {
      int c = 0;
      rep(k, 0, 6) if (s[i][j + k] == '#') c++;
      if (c >= 4) ans = true;
    }
    // 右下に6マス
    if (i + 5 < n && j + 5 < n) {
      int c = 0;
      rep(k, 0, 6) if (s[i + k][j + k] == '#') c++;
      if (c >= 4) ans = true;
    }
    // 右上に6マス
    if (i - 5 >= 0 && j + 5 < n) {
      int c = 0;
      rep(k, 0, 6) if (s[i - k][j + k] == '#') c++;
      if (c >= 4) ans = true;
    }
  }

  YesNo(ans);

  return 0;
}
