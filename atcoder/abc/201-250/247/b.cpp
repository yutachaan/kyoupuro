#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

using vi  = vector<int>;
using vvi = vector<vi>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

// <----- rep macro ----->
#define rep(i, a, b)  for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= (int)(b); i--)
#define fore(e, x) for (auto &(e): x)
#define fore2(k, v, x) for (auto &[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << endl
#define yesno(n) cout << ((n) ? "yes" : "no") << endl
#define YesNo(n) cout << ((n) ? "Yes" : "No") << endl

// <----- function ----->
template <typename T>
bool chmax(T &a, T b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <typename T>
bool chmin(T &a, T b) {
  if (a > b) {a = b; return true;}
  return false;
}


int main() {
  int N; cin >> N;
  vs s(N), t(N);
  rep(i, 0, N) cin >> s[i] >> t[i];

  // 自分以外と同じ姓/名をもつ人がいるかチェック
  vb ok_s(N, true), ok_t(N, true);
  rep(i, 0, N) {
    rep(j, 0, N) {
      if (i == j) continue;

      if (s[i] == s[j] || s[i] == t[j]) ok_s[i] = false;
      if (t[i] == s[j] || t[i] == t[j]) ok_t[i] = false;
    }
  }

  // 自分以外と同じ姓をもつ人がいる，かつ，自分以外と同じ名をもつ人がいる，という人が存在する場合false
  bool ans = true;
  rep(i, 0, N) {
    if (!ok_s[i] && !ok_t[i]) ans = false;
  }

  YesNo(ans);
}
