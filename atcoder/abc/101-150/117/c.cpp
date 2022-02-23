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
  int n, m; cin >> n >> m;
  vi x(m);
  fore(e, x) cin >> e;

  if (n >= m) { cout << 0 << endl; }
  else {
    sort(ALL(x));

    // 隣り合う座標間の距離を求める
    vector<pii> diff(m - 1); // f: 距離， s: index
    rep(i, 0, m - 1) diff[i] = make_pair(x[i + 1] - x[i], i + 1);

    // 距離が大きい順にソート
    sort(ALL(diff), greater<pii>());

    // 初めにコマを置く座標
    // 距離が最も広い区間[a, b]のbを選ぶ
    vi start = {0};
    rep(i, 0, n - 1) start.push_back(diff[i].second);

    // // 移動回数を求める
    int ans = 0;
    rep(i, 0, n - 1) ans += x[start[i + 1] - 1] - x[start[i]];
    ans += x[SIZE(x) - 1] - x[start[n - 1]]; // 最後のコマ

    cout << ans << endl;
  }

  return 0;
}
