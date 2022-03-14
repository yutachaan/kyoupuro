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

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0)); // dp[i][j]: i個の品物のうち重さがjを越えないようにいくつかを選んだときの， 品物の価値の総和の最大値

  rep(i, 1, N + 1) rep(j, 1, W + 1) {
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])
    chmax(dp[i][j], dp[i - 1][j]);                                  // i個目の品物を選ばない場合
    if (j - w[i] >= 0) chmax(dp[i][j], dp[i - 1][j - w[i]] + v[i]); // i個目の品物を選ぶ場合
  }

  cout << dp[N][W] << endl;

  return 0;
}
