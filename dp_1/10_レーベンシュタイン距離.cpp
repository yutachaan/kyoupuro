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
  string s, t; cin >> s >> t;

  vvi dp(SIZE(s) + 1, vi(SIZE(t) + 1, inf)); // dp[i + 1][j + 1]: sのi文字目までをtのj文字目までへ変換するときの操作の最小回数
  dp[0][0] = 0;

  rep(i, -1, SIZE(s)) rep(j, -1, SIZE(t)) {
    if (i == -1 and j == -1) continue;
    if (i >= 0 and j >= 0) {
      if (s[i] == t[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
      else dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
    }
    if (i >= 0) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + 1);
    if (j >= 0) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
  }

  cout << dp[SIZE(s)][SIZE(t)] << endl;

  return 0;
}
