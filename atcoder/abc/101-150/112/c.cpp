#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;
using msi = map<string, int>;
using si  = set<int>;
using ss  = set<string>;

// <----- REPマクロ ----->
#define FOR(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define RFOR(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define REP(i, n)     FOR(i, 0, n)
#define REPS(i, n)    FOR(i, 1, n + 1)
#define RREP(i, n)    RFOR(i, n, 0)
#define RREPS(i, n)   RFOR(i, n + 1, 1)
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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
  int n;
  cin >> n;

  // 入力(hが0の点は無視)
  vvi xyh;
  REP(i, n) {
    int x, y, h;
    cin >> x >> y >> h;

    if (h != 0) xyh.push_back({x, y, h});
  }

  // hが0ではない点が1つしかんない場合はそこが頂点なので出力して終了
  if (SIZE(xyh) == 1) {
    printf("%d %d %d\n", xyh[0][0], xyh[0][1], xyh[0][2]);
    return 0;
  }

  // それ以外の場合
  // cx, cyを全探索
  REP(cx, 101) REP(cy, 101) {
    // 1個目の情報からH(暫定)を求める
    ll h = xyh[0][2] + abs(xyh[0][0] - cx) + abs(xyh[0][1] - cy);

    // 他の点から求めたHが上で求めたHと違った場合はbreak
    bool ok = true;
    REP(i, SIZE(xyh)) {
      ll temp_h = xyh[i][2] + abs(xyh[i][0] - cx) + abs(xyh[i][1] - cy);
      if (temp_h != h) {
        ok = false;
        break;
      }
    }

    if (ok) {
      printf("%lld %lld %lld\n", cx, cy, h);
      return 0;
    }
  }

  return 0;
}
