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
  int N; cin >> N;
  vi p(N + 1);
  rep(i, 1, N + 1) cin >> p[i]; // 1-index (0問目を考慮するため)

  vector<vector<bool>> dp(N + 1, vector<bool>(10001, false)); // dp[i][j]: i問目まで解いた時j点をとることが可能か
  dp[0][0] = true;

  rep(i, 1, N + 1) rep(j, 0, 10001) {
    dp[i][j] = dp[i - 1][j];                           // i問目を解かなかった場合
    if (j - p[i] >= 0) dp[i][j] = dp[i][j] | dp[i - 1][j - p[i]]; // i問目を解いた場合
  }

  int ans = 0;
  rep(j, 0, 10001) if (dp[N][j]) ans++;
  cout << ans << endl;

  return 0;
}
