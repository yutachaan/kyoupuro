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
  int n; cin >> n;
  mii mp;
  rep(i, 0, n) {
    int a; cin >> a;
    mp[a]++;
  }

  // 2本以上ある棒と4本以上ある棒をそれぞれ記録
  vl bou_2, bou_4;
  foreach(e, mp) {
    if (e.second >= 2) bou_2.push_back(e.first);
    if (e.second >= 4) bou_4.push_back(e.first);
  }

  sort(ALL(bou_2), greater<ll>());
  sort(ALL(bou_4), greater<ll>());

  ll ans = 0; // 2本以上ある棒が1種類以下なら長方形は作れない
  if (SIZE(bou_2) >= 2) {
    ans = bou_2[0] * bou_2[1];
    if (SIZE(bou_4) >= 1) chmax(ans, bou_4[0] * bou_4[0]);
  }

  cout << ans << endl;

  return 0;
}
