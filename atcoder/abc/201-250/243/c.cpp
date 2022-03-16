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
  map<int, vector<pii>> pos;
  rep(i, 0, N) {
    int x, y; cin >> x >> y;
    pos[y].push_back(make_pair(x, i));
  }
  string S; cin >> S;

  fore2(k, v, pos) {
    if (SIZE(v) < 2) continue;

    // Yesとなるのは， xi < xj かつ s[xi] == R かつ s[xj] == Lのときのみ
    sort(ALL(v));
    int ir = inf; rep(i, 0, SIZE(v)) if (S[v[i].second] == 'R') {ir = i; break;};
    int il = -inf; rrep(i, SIZE(v), 0) if (S[v[i].second] == 'L') {il = i; break;};

    if (ir < il) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}
