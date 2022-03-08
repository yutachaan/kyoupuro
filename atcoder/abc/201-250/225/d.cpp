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
  int N, Q; cin >> N >> Q;

  vi front(N + 1, -1), back(N + 1, -1); // 電車iの前の電車と後ろの電車
  rep(i, 0, Q) {
    int c, x, y; cin >> c;

    if (c == 1) {
      cin >> x >> y;
      back[x] = y;
      front[y] = x;
    }
    else if (c == 2) {
      cin >> x >> y;
      back[x] = -1;
      front[y] = -1;
    }
    else {
      cin >> x;

      // 先頭まで戻る
      while (front[x] != -1) x = front[x];

      // つながっている電車を配列に入れていく
      vi ans = {x};
      while (back[x] != -1) {
        x = back[x];
        ans.push_back(x);
      }

      cout << SIZE(ans) << ' ';
      fore(e, ans) cout << e << ' ';
      cout << endl;
    }
  }

  return 0;
}
