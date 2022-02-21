// x
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
  int n; cin >> n;

  stack<pii> tutu; // f: ボールに書かれている数， s: 連続している個数
  int ans = 0;
  rep(i, 0, n) {
    int a; cin >> a;
    ans++;

    if (tutu.empty()) tutu.push(make_pair(a, 1));
    else {
      // 一番上のボールと書かれている整数が同じ場合
      if (tutu.top().first == a) {
        tutu.top().second++;

        // ボールに書かれている整数と連続している個数が同じになったら， 合計個数から連続している個数を引いて， pop
        if (tutu.top().second == tutu.top().first) {
          ans -= tutu.top().second;
          tutu.pop();
        }
      }
      else tutu.push(make_pair(a, 1)); // 異なる数字が書かれているなら普通にpush
    }

    cout << ans << endl;
  }

  return 0;
}
