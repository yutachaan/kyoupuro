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
  int N, X; cin >> N >> X;
  vi a(N), b(N);
  rep(i, 0, N) cin >> a[i] >> b[i];

  vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false)); // dp[i + 1][j]: i回目のジャンプの後に座標jにいることが可能か
  dp[0][0] = true;

  rep(i, 0, N) rep(j, 0, X + 1) {
    // 前のジャンプで座標jにいる場合
    if (dp[i][j]) {
      if (j + a[i] <= X) dp[i + 1][j + a[i]] = true;
      if (j + b[i] <= X) dp[i + 1][j + b[i]] = true;
    }
  }

  YesNo(dp[N][X]);

  return 0;
}
