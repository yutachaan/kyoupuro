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


int mod = 998244353;

int main() {
  int N; cin >> N;

  vector<vl> dp(N + 1, vl(10, 0)); // dp[i][j]: i桁目がjだった場合の， i桁の条件を満たす整数xの個数(% mod)
  rep(j, 1, 10) dp[1][j] = 1; // 1桁の場合は1個ずつ

  rep(i, 2, N + 1) rep(j, 1, 10) {
    if (j == 1) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
    else if (j == 9) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
    else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;

    dp[i][j] %= mod;
  }

  ll ans = 0;
  rep(j, 1, 10) ans += dp[N][j];
  ans %= mod;

  cout << ans << endl;
}
