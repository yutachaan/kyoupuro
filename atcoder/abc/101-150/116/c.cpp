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


int main() {
  int n; cin >> n;
  vi h(n);
  rep(i, 0, n) cin >> h[i];

  // 全ての花の高さが0になるまで水やり操作の逆を繰り返す
  int ans = 0;
  while (true) {
    // 全て0になっていたらbreak
    bool ok = true;
    rep(i, 0, n) if (h[i] != 0) ok = false;
    if (ok) break;

    // 最初に現れる，0が含まれない区間の左端のインデックスを探す
    int l = -1;
    rep(i, 0, n) {
      if (h[i] != 0) {
        l = i;
        break;
      }
    }

    // lから始めて，0が含まれない区間の右端までh[i]の値を-1する
    rep(i, l, n) {
      if (h[i] == 0) break;
      else h[i]--;
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}
