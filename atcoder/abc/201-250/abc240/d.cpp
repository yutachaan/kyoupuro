#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int, int>;

#define endl "\n";

// <----- rep macro ----->
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define fore(e, x) for (auto &&(e): x)
#define fore2(k, v, x) for (auto &&[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin((x)), end((x))
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << "\n"
#define yesno(n) cout << ((n) ? "yes" : "no") << "\n"
#define YesNo(n) cout << ((n) ? "Yes" : "No") << "\n"

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
  int N; cin >> N;

  stack<pii> tutu; // f: ボールに書かれた数字， s: 連続している数
  int ans = 0;
  rep(i, 0, N) {
    int a; cin >> a;

    ans++;

    // 筒にボールを追加
    if (tutu.empty() || tutu.top().first != a) tutu.push(make_pair(a, 1));
    else tutu.top().second++;

    // ボールに書かれた数字と連続している数が同じなら， ボールを消す
    if (tutu.top().first == tutu.top().second) {
      tutu.pop();
      ans -= a;
    }

    cout << ans << endl;
  }

  return 0;
}
