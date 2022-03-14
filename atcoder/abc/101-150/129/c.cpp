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


ll mod = 1000000007;

int main() {
  int N, M; cin >> N >> M;
  vi a(M);
  rep(i, 0, M) cin >> a[i];

  vi dp(N + 1, 0); // dp[i]: i段目にたどりつくまでの移動方法 (% mod)
  dp[0] = 1;

  rep(i, 0, M) dp[a[i]] = -1; // 壊れているところはいけないので-1

  rep(i, 1, N + 1) {
    if (dp[i] == -1) continue;

    // dp[i] = dp[i - 1] + dp[i - 2]
    // ただし， dp[i - 1]やdp[i - 2]が-1の場合は足さない
    if (dp[i - 1] != -1) dp[i] += dp[i - 1];
    if (i >= 2 && dp[i - 2] != -1) dp[i] += dp[i - 2];

    dp[i] %= mod;
  }


  cout << dp[N] << endl;

  return 0;
}
