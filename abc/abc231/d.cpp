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

// <----- other ----->
// 4近傍
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// UnionFind
struct UnionFind {
  vi par;

  // 初期化
  UnionFind(int n): par(n, -1) {}

  int root(int x) {
    if (par[x] < 0) return x;
    return par[x] = root(par[x]);
  }

  // xとyが同じグループに属するか
  bool same(int x, int y) {
    return root(x) == root(y);
  }

  // xを含むグループとyを含むグループをmerge
  int merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return x;
    if (-par[x] < -par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return x;
  }

  int size(int x) {
    return -par[root(x)];
  }
};


int main() {
  int n, m;
  cin >> n >> m;

  UnionFind uf(n);
  vi deg(n); // 各頂点の次数

  REP(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    // 既にaとbが同じグループに属するならNo (閉路ができるため)
    if (uf.same(a, b)) {
      cout << "No" << endl;
      return 0;
    }

    uf.merge(a, b);
    deg[a]++;
    deg[b]++;
  }

  // 次数が3以上の点が1つでもあったらNo
  REP(i, 0, n) {
    if (deg[i] > 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
