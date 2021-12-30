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
  vvi c(3, vi(3));
  REP(i, 3) REP(j, 3) cin >> c[i][j];

  bool ok = true;
  REPS(a1, 100) {
    // a1が決まるとb1, b2, b3が決まる
    int b1 = c[0][0] - a1;
    int b2 = c[0][1] - a1;
    int b3 = c[0][2] - a1;

    // b1, b2, b3が決まるとa2の値が決まるので，2行目の各要素に対して計算を行い，1つでもa2の値が異なっていたらfalse
    if ((c[1][0] - b1 != c[1][1] - b2) || (c[1][1] - b2 != c[1][2] - b3) || (c[1][2] - b3 != c[1][0] - b1)) ok = false;

    // 3行目も同様に
    if ((c[2][0] - b1 != c[2][1] - b2) || (c[2][1] - b2 != c[2][2] - b3) || (c[2][2] - b3 != c[2][0] - b1)) ok = false;
  }

  YesNo(ok);

  return 0;
}
