// x
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
  int n, x; cin >> n >> x;
  vi a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false)); // dp[i + 1][j]: i回ジャンプを行った時点で，座標jにいるかどうか
  dp[0][0] = true;

  rep(i, 0, n) rep(j, 0, x + 1) {
    if (dp[i][j]) {
      if (j + a[i] <= x) dp[i + 1][j + a[i]] = true;
      if (j + b[i] <= x) dp[i + 1][j + b[i]] = true;
    }
  }

  YesNo(dp[n][x]);

  return 0;
}
