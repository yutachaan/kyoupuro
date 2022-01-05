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
  string s; cin >> s;
  vi n(4);
  REP(i, 0, 4) n[i] = s[i] - '0';

  vector<char> op(3); // 演算子
  // bit全探索
  for (int bit = 0; bit < (1 << 3); bit++) {
    int temp = n[0]; // 演算結果
    REP(i, 0, 3) {
      if (bit & (1 << i)) {
        temp += n[i + 1];
        op[i] = '+';
      }
      else {
        temp -= n[i + 1];
        op[i] = '-';
      }
    }

    if (temp == 7) break;
  }

  // 出力
  cout << n[0];
  REP(i, 0, 3) cout << op[i] << n[i + 1];
  cout << "=7" << endl;

  return 0;
}
