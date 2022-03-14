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
  int N; cin >> N;
  vvi koudou(N, vi(3));
  rep(i, 0, N) rep(j, 0, 3) cin >> koudou[i][j];

  vvi dp(N, vi(3, 0)); // dp[i][j]: i日目に行動j(j = 0: A, 1: B, 2: C)をしたときの， i日目までの幸福度の総和の最大値 (0-index)
  rep(j, 0, 3) dp[0][j] = koudou[0][j]; // 初日は前日の行動に影響を受けない

  rep(i, 1, N) rep(j, 0, 3) rep(k, 0, 3) {
    // 前日の行動kと違う行動をするときのみ考える
    if (j != k) chmax(dp[i][j], dp[i - 1][k] + koudou[i][j]);
  }

  int ans = 0;
  rep(j, 0, 3) chmax(ans, dp[N - 1][j]);
  cout << ans << endl;

  return 0;
}
