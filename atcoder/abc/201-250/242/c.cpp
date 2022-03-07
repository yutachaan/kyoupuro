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


int mod = 998244353;

int main() {
  int N; cin >> N;

  vector<vector<ll>> dp(N + 1, vector<ll>(10, 0)); //dp[n][i]: 先頭がiであるn桁の数のうち，条件を満たすものの個数
  rep(i, 1, 10) dp[1][i] = 1;

  rep(n, 2, N + 1) rep(i, 1, 10) {
    rep(j, max(1LL, i - 1), min(9LL, i + 1) + 1) {
      dp[n][j] += dp[n - 1][i];
      dp[n][j] %= mod;
    }
  }

  ll ans = 0;
  rep(i, 1, 10) ans += dp[N][i];
  ans %= mod;

  cout << ans << endl;

  return 0;
}
