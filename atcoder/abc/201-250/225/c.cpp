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
  int N, M; cin >> N >> M;
  vvi B(N, vi(M));
  rep(i, 0, N) rep(j, 0, M) cin >> B[i][j];

  bool ans = true;

  // 縦方向が7ずつ増えているか
  rep(j, 0, M) rep(i, 0, N - 1) {
    if (B[i][j] + 7 != B[i + 1][j]) ans = false;
  }
  // 横方向が1ずつ増えているか
  rep(i, 0, N) rep(j, 0, M - 1) {
    if (B[i][j] + 1 != B[i][j + 1]) ans = false;
  }

  // 横がはみ出ていないか
  if (M != 1) {
    ans &= B[0][0] % 7 != 0;
    ans &= B[0][0] % 7 + M - 1 <= 7;
  }

  YesNo(ans);

  return 0;
}
