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
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define foreach(e, x) for (auto&& (e): x)

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
  int n, m, x; cin >> n >> m >> x;
  vi c(n); vvi a(n, vi(m));
  rep(i, 0, n) {
    cin >> c[i];
    rep(j, 0, m) cin >> a[i][j];
  }

  // 各参考書を買う/買わないでbit全探索
  int ans = inf;
  rep(bit, 0, 1 << n) {
    int sum = 0;     // 合計金額
    vi rikaido(m, 0);
    rep(i, 0, n) {
      if (bit & (1 << i)) {
        // i番目の参考書を買った場合
        rep(j, 0, m) rikaido[j] += a[i][j];
        sum += c[i];
      }
    }

    // 全てのアルゴリズムの理解度がx以上になっているか
    bool ok = true;
    rep(j, 0, m) if (rikaido[j] < x) ok = false;

    if (ok) chmin(ans, sum);
  }

  if (ans == inf) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
