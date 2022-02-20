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
  string s; cin >> s;
  map<char, int> mp;
  foreach(c, s) mp[c]++;

  // 下3桁が8の倍数なら，8の倍数なので，下3桁を8の倍数にできるか検証
  bool ans = false;
  for (int x = 0; x < 1000; x += 8) {
    // xを適切に0埋め
    ostringstream sout;
    sout << setfill('0') << setw(min(SIZE(s), 3LL)) << x;
    string sx = sout.str();

    map<char, int> mp2;
    foreach(c, sx) mp2[c]++;

    // sxの各数字の出現個数がsの各数字の出現個数以下ならok
    bool ok = true;
    foreach(c, mp2) {
      if (mp[c.first] < c.second) ok = false;
    }

    if (ok) ans = true;
  }

  YesNo(ans);

  return 0;
}
