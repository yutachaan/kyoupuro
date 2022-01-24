// x
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

ll f(ll a, ll b, ll x) {
  return (a * x) / b - a * (x / b);
}

int main() {
  ll a, b, n; cin >> a >> b >> n;

  ll ans = f(a, b, n);
  if (b - 1 < n) chmax(ans, f(a, b, b - 1));

  cout << ans << endl;

  return 0;
}
