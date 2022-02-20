#include <bits/stdc++.h>
using namespace std;

// <----- debug ----->
#ifdef LOCAL
#  include <debug_print.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

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

#define endl "\n";

// <----- REPマクロ ----->
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define foreach(e, x) for (auto&& (e): x)

// <----- 略記 ----->
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


bool is_prime(ll n) {
  if (n == 1) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;

  // 青木くんが選べる数字のどれを足しても合成数になるような数字を高橋くんが選択した場合，高橋くんが勝てる
  rep(i, a, b + 1) {
    bool takahashi = true;
    rep(j, c, d + 1) {
      if (is_prime(i + j)) takahashi = false;
    }

    if (takahashi) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }

  cout << "Aoki" << endl;

  return 0;
}
