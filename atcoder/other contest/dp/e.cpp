#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

using vi  = vector<int>;
using vvi = vector<vi>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

// <----- rep macro ----->
#define rep(i, a, b)  for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= (int)(b); i--)
#define fore(e, x) for (auto &(e): x)
#define fore2(k, v, x) for (auto &[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << endl
#define yesno(n) cout << ((n) ? "yes" : "no") << endl
#define YesNo(n) cout << ((n) ? "Yes" : "No") << endl

// <----- function ----->
template <typename T>
bool chmax(T &a, T b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <typename T>
bool chmin(T &a, T b) {
  if (a > b) {a = b; return true;}
  return false;
}


int main() {
  int N, W; cin >> N >> W;
  vi w(N + 1), v(N + 1);
  rep(i, 1, N + 1) cin >> w[i] >> v[i]; // 1-index (0日目を考慮するため)

  vector<vl> dp(N + 1, vl(100001, infl)); // dp[i][j]: i個目の品物までのうちいくつかを選んで価値の総和をjとするときの，選んだ品物の重さの総和の最小値
  rep(i, 0, N + 1) dp[i][0] = 0;

  rep(i, 1, N + 1) rep(j, 1, 100001) {
    // i個目の品物を選ばない場合
    dp[i][j] = dp[i - 1][j];

    // i個目の品物を選ぶ場合
    if (j - v[i] >= 0) chmin(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
  }

  // 重さがW以下となる最大のjが答え
  int ans = 0;
  rep(j, 0, 100001) {
    if (dp[N][j] <= W) ans = j;
  }

  cout << ans << endl;
}
