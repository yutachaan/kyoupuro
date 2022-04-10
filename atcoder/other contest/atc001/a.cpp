#define _GLIBCXX_DEBUG

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

// <----- rep macro ----->
#define rep(i, a, b)  for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= (int)(b); i--)
#define fore(e, x) for (auto &(e): x)
#define fore2(k, v, x) for (auto &[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << endl
#define yesno(n) cout << ((n) ? "yes" : "no") << endl
#define YesNo(n) cout << ((n) ? "Yes" : "No") << endl

// <----- function ----->
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {a = b; return true;}
  return false;
}


int H, W;
vs c;
vector<vector<bool>> seen; // 探索済みか

vi dx = {0, -1, 1, 0};
vi dy = {-1, 0, 0, 1};

void dfs(int y, int x) {
  seen[y][x] = true;

  // 4近傍探索
  rep(d, 0, 4) {
    int yy = y + dy[d], xx = x + dx[d];

    if (yy < 0 || yy >= H || xx < 0 || xx >= W) continue;
    if (c[yy][xx] == '#') continue;
    if (seen[yy][xx]) continue;

    dfs(yy, xx);
  }
}

int main() {
  cin >> H >> W;
  c.resize(H); seen.resize(H, vector<bool>(W));
  fore(x, c) cin >> x;

  int sy, sx, gy, gx;
  rep(y, 0, H) rep(x, 0, W) {
    if (c[y][x] == 's') {sy = y; sx = x;}
    if (c[y][x] == 'g') {gy = y; gx = x;}
  }

  dfs(sy, sx);

  YesNo(seen[gy][gx]);
}
