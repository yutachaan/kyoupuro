#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

using vi  = vector<int>;
using vvi = vector<vi>;
using vl  = vector<ll>;
using vvl = vector<vl>;
using vs  = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;
using msi = map<string, int>;
using si  = set<int>;
using ss  = set<string>;

// <----- REPマクロ ----->
#define REP(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define RREP(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define FOREACH(e, x) for (auto&& (e): x)

// <----- 略記 ----->
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << endl
#define yesno(n) cout << ((n) ? "yes" : "no") << endl
#define YesNo(n) cout << ((n) ? "Yes" : "No") << endl

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
  int n; cin >> n;
  vvi A(2, vi(n));
  REP(i, 0, 2) REP(j, 0, n) cin >> A[i][j];

  vvi dp(2, vi(n)); // dp[i][j]: (i, j)まで移動した時のアメの個数の最大値
  dp[0][0] = A[0][0], dp[1][0] = dp[0][0] + A[1][0];
  REP(j, 1, n) dp[0][j] = dp[0][j - 1] + A[0][j];
  REP(j, 1, n) dp[1][j] = max(dp[1][j - 1], dp[0][j]) + A[1][j];

  cout << dp[1][n - 1] << endl;

  return 0;
}
