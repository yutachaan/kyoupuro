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
  vi n(3);
  REP(i, 0, 3) cin >> n[i];

  int n_even = 0, n_odd = 0, ans = 0;
  REP(i, 0, 3) {
    if (n[i] % 2) n_odd++;
    else n_even++;
  }

  // 操作1を高々1回行い，偶奇を揃える
  if (n_even == 2) {
    REP(i, 0, 3) if (!(n[i] % 2)) n[i]++;
    ans++;
  }
  else if (n_odd == 2){
    REP(i, 0, 3) if (n[i] % 2) n[i]++;
    ans++;
  }

  // 一番大きい数と等しくなるように操作2を行う
  int max_abc = *max_element(ALL(n));
  REP(i, 0, 3) ans += (max_abc - n[i]) / 2;

  cout << ans << endl;

  return 0;
}
