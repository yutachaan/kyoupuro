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
  int h, w; cin >> h >> w;
  vs S(h);
  REP(i, 0, h) cin >> S[i];

  // 8近傍探索
  vi dx = {-1, 0, 1, -1, 1, -1, 0, 1};
  vi dy = {-1, -1, -1, 0, 0, 1, 1, 1};
  REP(i, 0, h) REP(j, 0, w) {
    if (S[i][j] == '.') {
      int count = 0;
      REP(n, 0, 8) {
        int x = j + dx[n], y = i + dy[n];
        if ((x >= 0) and(x < w) and (y >= 0) and (y < h)) {
          if (S[y][x] == '#') count++;
        }
      }
      S[i][j] = '0' + count;
    }
  }

  REP(i, 0, h) cout << S[i] << endl;

  return 0;
}
