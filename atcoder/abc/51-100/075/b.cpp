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
#define fore(e, x) for (auto &&(e): x)
#define fore2(k, v, x) for (auto &&[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << "\n"
#define yesno(n) cout << ((n) ? "yes" : "no") << "\n"
#define YesNo(n) cout << ((n) ? "Yes" : "No") << "\n"

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


vi dx = {-1, 0, 1, -1, 1, -1, 0, 1};
vi dy = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  int H, W; cin >> H >> W;
  vs S(H);
  rep(i, 0, H) cin >> S[i];

  rep(y, 0, H) rep(x, 0, W) {
    if (S[y][x] == '#') continue;

    // 8近傍探索
    int count = 0;
    rep(d, 0, 8) {
      int yy = y + dy[d], xx = x + dx[d];
      if (yy < 0 || yy >= H || xx < 0 || x >= W) continue;

      if (S[yy][xx] == '#') count++;
    }

    S[y][x] = count + '0';
  }

  rep(i, 0, H) cout << S[i] << endl;
}
