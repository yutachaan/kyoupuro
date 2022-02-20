#include <bits/stdc++.h>
using namespace std;

// <----- debug ----->
#ifdef LOCAL
#  include <debug_print.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

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

#define endl "\n";

// <----- REPマクロ ----->
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define foreach(e, x) for (auto&& (e): x)

// <----- 略記 ----->
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
  int n, m, x; cin >> n >> m >> x;
  vi c(n);
  vvi a(n, vi(m));
  rep(i, 0, n) {
    cin >> c[i];
    rep(j, 0, m) cin >> a[i][j];
  }

  int ans = inf;
  // 各参考書を買うか買わないかでbit全探索
  rep(bit, 0, 1 << n) {
    int sum = 0;
    vi rikaido(m, 0);
    rep(i, 0, n) {
      // 買う場合
      if (bit & (1 << i)) {
        sum += c[i];
        rep(j, 0, m) rikaido[j] += a[i][j];
      }
    }

    // 全てのアルゴリズムの理解度がx以上になっているか
    bool ok = true;
    rep(j, 0, m) {
      if (rikaido[j] < x) ok = false;
    }

    if (ok) chmin(ans, sum);
  }

  if (ans == inf) ans = -1;
  cout << ans << endl;

  return 0;
}
