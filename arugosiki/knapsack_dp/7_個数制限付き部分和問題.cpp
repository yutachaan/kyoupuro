#include <bits/stdc++.h>
using namespace std;

// <----- debug ----->
#ifdef LOCAL
#  include <debug_print.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

using vi  = vector<int>;
using vvi = vector<vi>;
using vl  = vector<ll>;
using vvl = vector<vl>;
using vs  = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;
using msi = map<string, int>;
using si  = set<int>;
using ss  = set<string>;

#define endl "\n";

// <----- REPマクロ ----->
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define foreach(e, x) for (auto&& (e): x)

// <----- 略記 ----->
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
  int n, m; cin >> n >> m;
  vi a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  vvi dp(n + 1, vi(m + 1, inf)); // dp[i + 1][j]: i番目の整数まで選んで総和をjにするときの，選んだa[i]の個数の最小値
  dp[0][0] = 0;

  rep(i, 0, n) rep(j, 0, m + 1) {
    if (dp[i][j] < inf) dp[i + 1][j] = 0;
    if (j >= a[i]) {
      if (dp[i][j - a[i]] < inf) dp[i + 1][j] = min(dp[i + 1][j], 1);
      if (dp[i + 1][j - a[i]] < b[i]) dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j - a[i]] + 1);
    }
  }

  YesNo(dp[n][m] < inf);

  return 0;
}
