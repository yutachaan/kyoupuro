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


int h, w;
vs field;
vector<vector<bool>> seen; // 探索済みか

vi dx = {0, -1, 1, 0};
vi dy = {-1, 0, 0, 1};

void dfs(int y, int x) {
  seen[y][x] = true;

  // 4近傍探索
  rep(d, 0, 4) {
    int yy = y + dy[d], xx = x + dx[d];
    if (yy >= 0 and yy < h and xx >= 0 and xx < w) {
      if (seen[yy][xx]) continue;

      if (field[yy][xx] == '#') continue;

      dfs(yy, xx);
    }
  }
}

int main() {
  cin >> h >> w;
  field.resize(h);
  foreach(e, field) cin >> e;

  // 始点と終点の座標を調べる
  int sy, sx, gy, gx;
  rep(y, 0, h) rep(x, 0, w) {
    if (field[y][x] == 's') {
      sy = y; sx = x;
    }
    if (field[y][x] == 'g') {
      gy = y; gx = x;
    }
  }

  // sを始点としてDFS
  seen.resize(h, vector<bool>(w, false));
  dfs(sy, sx);

  // gが探索済みかどうか
  YesNo(seen[gy][gx]);
}
