#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;
using msi = map<string, int>;
using si  = set<int>;
using ss  = set<string>;

// <----- REPマクロ ----->
#define FOR(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define RFOR(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define REP(i, n)     FOR(i, 0, n)
#define REPS(i, n)    FOR(i, 1, n + 1)
#define RREP(i, n)    RFOR(i, n, 0)
#define RREPS(i, n)   RFOR(i, n + 1, 1)
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

// <----- other ----->
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
  double a, b, c;
  int x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = 0;
  // Aピザ半分の値段とBピザ半分の値段の合計が，ABピザ1枚の値段以上なら，xとyの少ない方の数だけABピザを購入
  if ((a + b) / 2 >= c) {
    int n = min(x, y);
    x -= n; y -= n;
    ans += c * n * 2;
  }

  // 購入後，Aピザの必要枚数が足りていない場合，
  if (x > 0) {
    // Aピザ1枚よりもABピザ2枚の方が安い場合は，ABピザで埋める．そうでないなら普通にAピザを購入
    if (a > 2 * c) ans += c * x * 2;
    else ans += a * x;
  }

  // Bピザの必要枚数が足りていない場合も同様に
  if (y > 0) {
    if (b > 2 * c) ans += c * y * 2;
    else ans += b * y;
  }

  cout << ans << endl;

  return 0;
}
