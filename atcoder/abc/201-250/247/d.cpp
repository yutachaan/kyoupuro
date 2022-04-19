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
  int Q; cin >> Q;

  queue<pair<ll, ll>> q; // xとcのpair
  rep(_, 0, Q) {
    int order; cin >> order;

    if (order == 1) {
      ll x, c; cin >> x >> c;

      if (!q.empty() && x == q.front().first) q.front().second += c;
      else q.push(pair<ll, ll>(x, c));
    }
    else {
      ll c; cin >> c;

      ll ans = 0;
      while (c > 0) {
        if (q.front().second < c) {
          ans += q.front().second * q.front().first;
          c -= q.front().second;
          q.pop();
        }
        else {
          ans += c * q.front().first;
          q.front().second -= c;
          break;
        }
      }

      cout << ans << endl;
    }
  }

}
