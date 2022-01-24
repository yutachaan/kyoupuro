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
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define foreach(e, x) for (auto&& (e): x)

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

  bool ans = false;
  if (SIZE(s) == 1) {
    if (stoi(s) == 8) ans = true;
  }
  else if (SIZE(s) == 2) {
    if (stoi(s) % 8 == 0) ans = true;
    else {
      swap(s[0], s[1]);
      if (stoi(s) % 8 == 0) ans = true;
    }
  }
  else {
    // 各数字が何個出てきたかカウント
    vi count(10, 0);
    rep(i, 0, SIZE(s)) count[s[i] - '0']++;

    // 下三桁が8の倍数ならその数字は8の倍数であることを利用
    // 3桁の8の倍数をどれか1つでもつくれるか
    for(int x = 112; x < 1000; x += 8) {
      string sx = to_string(x);

      vi count_x(10, 0);
      rep(i, 0, 3) count_x[sx[i] - '0']++;

      // 与えられた文字列に　xを構成する数字が足りているか判定
      bool ok = true;
      rep(i, 0, 10) if (count_x[i] > count[i]) ok = false;

      if (ok) {
        ans = true;
        break;
      }
    }

  }

  YesNo(ans);

  return 0;
}
