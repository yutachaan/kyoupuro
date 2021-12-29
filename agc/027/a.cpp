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
  int n, x;
  cin >> n >> x;

  vi a(n);
  REP(i, n) cin >> a[i];
  sort(ALL(a));

  int ans = 0;
  REP(i, n - 1) {
    // 最後から2番目の人までは，希望量を渡せるなら渡す．渡せないならbreak
    if (x - a[i] >= 0) {
      x -= a[i];
      ans++;
    }
    else break;
  }

  // 最後の人に全部押し付けずに希望量だけ与えられるかどうか
  if (x  - a[n - 1] == 0) ans++;

  cout << ans << endl;

  return 0;
}
