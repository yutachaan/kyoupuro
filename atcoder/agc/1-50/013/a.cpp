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
  vi a(n);
  fore(e, a) cin >> e;

  int i = 0, ans = 0;
  while (i < n) {
    // 単調非減少とした場合にiからどれだけ長くできるか
    int zouka = i;
    while (a[zouka] <= a[zouka + 1] && zouka < n) zouka++;

    // 単調非増加とした場合にiからどれだけ長くできるか
    int gensyou = i;
    while (a[gensyou] >= a[gensyou + 1] && gensyou < n) gensyou++;

    // より長くできたほうの分だけiを増やす
    i += max(zouka, gensyou) - i + 1;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
