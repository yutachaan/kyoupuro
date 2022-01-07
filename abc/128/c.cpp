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
#define REP(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define RREP(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
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


int main() {
  // 入力
  int n, m; cin >> n >> m;
  vi k(m), p(m); vvi s;
  REP(i, 0, m) {
    cin >> k[i];
    vi temp(k[i]);
    REP(j, 0, k[i]) cin >> temp[j];
    s.push_back(temp);
  }
  REP(i, 0, m) cin >> p[i];

  // 各スイッチのon/offの状態の組み合わせを全探索
  int ans = 0;
  REP(bit, 0, 1 << n) {
    // その組み合わせで全ての電球が点灯するかどうか調べる
    bool ok = true;
    REP(i, 0, m) {
      int on = 0; // onになっているスイッチの数
      FOREACH(ss, s[i]) {
        if (bit & (1 << (ss - 1))) on++; // bitが1なら点灯しているとしてカウント
      }

      if (on % 2 != p[i]) ok = false;
    }

    if (ok) ans++;
  }

  cout << ans << endl;

  return 0;
}
