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
  int N, W; cin >> N >> W;
  vi w(N + 1), v(N + 1);
  rep(i, 1, N + 1) cin >> w[i] >> v[i]; // 1-index (0日目を考慮するため)

  vector<vector<ll>> dp(N + 1, vector<ll>(100001, infl)); // dp[i][j]: i個の品物のうち価値がjとなるようにいくつかを選んだときの， 重さの総和の最小値
  dp[0][0] = 0;

  rep(i, 1, N + 1) rep(j, 0, 100001) {
    // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
    chmin(dp[i][j], dp[i - 1][j]);                                  // i個目の品物を選ばない場合
    if (j - v[i] >= 0) chmin(dp[i][j], dp[i - 1][j - v[i]] + w[i]); // i個目の品物を選ぶ場合
  }

  // 価値が大きいところから見ていき，最初にW以下になったところが答え
  int ans = 100000;
  while (dp[N][ans] > W) ans--;
  cout << ans << endl;

  return 0;
}
