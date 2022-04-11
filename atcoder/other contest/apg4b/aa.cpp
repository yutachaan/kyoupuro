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
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {a = b; return true;}
  return false;
}


int main() {
  int N; cin >> N;
  map<int, int> count;
  rep(i, 0, N) {
    int A; cin >> A;

    count[A]++;
  }

  int ans_v, ans_c = 0;
  fore2(v, c, count) {
    if (c > ans_c) {
      ans_c = c;
      ans_v = v;
    }
  }

  cout << ans_v << ' ' << ans_c << endl;
}
