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
  // 入力
  int n; cin >> n;
  vector<vector<pii>> syougen(n);
  rep(i, 0, n) {
    int a; cin >> a;
    vector<pii> syougen_a(a);
    rep(j, 0, a) cin >> syougen_a[j].first >> syougen_a[j].second;
    syougen[i] = syougen_a;
  }

  // 各人のhonest/unkindの状態の組み合わせを全探索
  int ans = 0;
  rep(bit, 0, 1 << n) {
    vi settei(n); // 現在の組み合わせ
    rep(i, 0, n) {
      if (bit & (1 << i)) settei[i] = 1;
      else settei[i] = 0;
    }

    bool ok = true;
    rep(i, 0, n) {
      // 現在の組み合わせにおいてhonestである人の証言を検証
      if (settei[i] == 1) {
        foreach(s, syougen[i]) {
          if (settei[s.first - 1] != s.second) ok = false; // 証言と矛盾したらfalse
        }
      }
    }

    if (ok) chmax(ans, __builtin_popcount(bit));
  }

  cout << ans << endl;

  return 0;
}
