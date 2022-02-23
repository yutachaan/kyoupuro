// x
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


struct Edge {
  int to;     // 辺の行き先
  int weight; // 辺の長さ
  Edge(int t, int w): to(t), weight(w) { }
};

vector<vector<Edge>> G;
vi ans; // 1 (黒確定)，0 (白確定)，-1 (未訪問)

void dfs(int v, int c = 0, int p = -1) {
  ans[v] = c;
  foreach(e, G[v]) {
    if (e.to == p) continue; // 辺を逆に辿らないようにする

    if (e.weight % 2 == 0) dfs(e.to, c, v); // 辺の長さが偶数なら同じ色
    else dfs(e.to, 1 - c, v);               // 辺の長さが奇数なら違う色
  }
}

int main() {
  int n; cin >> n;
  G.resize(n, vector<Edge>());
  rep(i, 0, n - 1) {
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    G[u].push_back(Edge(v, w));
		G[v].push_back(Edge(u, w));
  }

  ans.resize(n, -1);
  dfs(0);

  foreach(e, ans) cout << e << endl;

  return 0;
}
