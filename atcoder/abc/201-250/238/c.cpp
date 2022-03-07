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


int mod = 998244353;

// 1からxまでの和を求める
ll f(ll x) {
  x %= mod;
  return (x * (x + 1) / 2) % mod;
}

// nの桁数を求める
int digits(ll n) {
  int ret = 0;
  while (n > 0) {
    n /= 10;
    ret++;
  }
  return ret;
}

int main() {
  ll n; cin >> n;
  int d = digits(n);

  ll ans = 0;
  if (d == 1) ans = f(n);
  else {
    ans = f(n - (stol(string(d - 1, '9'))));

    ans += f(9);
    rep(i, 1, d - 1) ans += f(stol('9' + string(i, '0')));
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
