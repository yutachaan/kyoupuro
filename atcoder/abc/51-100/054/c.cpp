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
  int n, m; cin >> n >> m;
  vvi G(n);
  rep(i, 0, m) {
    int a, b; cin >> a >> b;
    a--; b--; // 0-index
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vi p(n);
  rep(i, 0, n) p[i] = i;
  int ans = 0;
  do {
    if (p[0] != 0) continue; // 始点が0でないならcontinue

    // 次の点との間に辺があるか調べる
    bool ok = true;
    rep(i, 0, n - 1) {
      if (find(ALL(G[p[i]]), p[i + 1]) == G[p[i]].end()) ok = false;
    }

    if (ok) ans++; // 全ての点がつながっていたらok
  } while (next_permutation(ALL(p)));

  cout << ans << endl;

  return 0;
}
