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
  vi x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  set<pii> st;
  rep(i, 0, n) rep(j, i + 1, n) {
    int dx = x[j] - x[i], dy = y[j] - y[i];            // 街iから街jの， x座標とy座標のdiff
    int xx = dx / gcd(dx, dy), yy = dy / gcd(dx, dy);  // dxとdyの最大公約数で割る(答えを最小化するため)

    st.insert(make_pair(xx, yy));
    st.insert(make_pair(-xx, -yy)); // 逆の移動
  }

  cout << SIZE(st) << endl;

  return 0;
}
