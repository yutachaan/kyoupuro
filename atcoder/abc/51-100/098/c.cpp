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
  int n; cin >> n;
  string s; cin >> s;

  vi se(n), sw(n); // se[i]: iよりも東にいる，東を向いている人数， sw[i]: iよりも西にいる西を向いている人数
  REP(i, 0, n) se[i] = sw[i] = 0;
  RREP(i, n - 1, 0) {
    if (s[i + 1] == 'E') se[i] = se[i + 1] + 1;
    else se[i] = se[i + 1];
  }
  REP(i, 1, n) {
    if (s[i - 1] == 'W') sw[i] = sw[i - 1] + 1;
    else sw[i] = sw[i - 1];
  }

  int ans = inf;
  REP(i, 0, n) chmin(ans, se[i] + sw[i]);

  cout << ans << endl;

  return 0;
}
