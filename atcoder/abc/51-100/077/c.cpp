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


int main() {
  int n; cin >> n;
  vi a(n), b(n), c(n);
  fore(e, a) cin >> e;
  fore(e, b) cin >> e;
  fore(e, c) cin >> e;

  sort(ALL(a));
  sort(ALL(c));

  ll ans = 0;
  rep(i, 0, n) {
    ll ue = lower_bound(ALL(a), b[i]) - begin(a);         // b[i]より小さい上部のパーツの個数
    ll sita = n - (upper_bound(ALL(c), b[i]) - begin(c)); // b[i]より大きい下部のパーツの個数

    ans += ue * sita;
  }

  cout << ans << endl;

  return 0;
}
