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
  vi a(N);
  rep(i, 0, N) cin >> a[i];

  // 4の倍数の個数と， 4の倍数ではないが2の倍数の個数をカウント
  int mul4 = 0, mul2 = 0;
  rep(i, 0, N) {
    if (a[i] % 4 == 0) mul4++;
    else if (a[i] % 2 == 0) mul2++;
  }

  // 4の倍数が N // 2個以上あればクリア
  // 4の倍数が足りなくても， 2の倍数がN - 2 * 4の倍数の個数 以上あればクリア
  YesNo((mul4 >= N / 2) || (mul2 >= N - 2 * mul4));

  return 0;
}
