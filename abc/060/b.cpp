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
  int a, b, c; cin >> a >> b >> c;

  if (a == 1) {
    cout << "YES" << endl;
    return 0;
  }

  si all_r; // bで割った余りの集合
  REP(i, 0, b) all_r.insert(i);

  for (int i = 1; ; i++) {
    int r = ((a * i) % b);
    if (r == c) {
      cout << "YES" << endl;
      return 0;
    }
    // 余りがループし始めたら存在しない
    else if (all_r.find(r) != all_r.end()) all_r.erase(r);
    else {
      cout << "NO" << endl;
      return 0;
    }
  }

  return 0;
}
