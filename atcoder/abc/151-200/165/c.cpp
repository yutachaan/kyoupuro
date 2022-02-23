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


int n, m, q, ans;
vvi kumi;

void dfs(vi a) {
  // aの生成が終了したら得点の計算をする
  if (SIZE(a) == n) {
    int temp = 0;
    rep(i, 0, q) {
      if (a[kumi[i][1] - 1] - a[kumi[i][0] - 1] == kumi[i][2]) temp += kumi[i][3];
    }
    chmax(ans, temp);

    return;
  }

  // 末尾の要素の値
  int last = 1;
  if (SIZE(a) >= 1) last = a[SIZE(a) - 1];

  // last以上の要素を最後尾に追加して次を呼び出す
  rep(i, last, m + 1) {
    vi a_copy;
    copy(ALL(a), back_inserter(a_copy));
    a_copy.push_back(i);

    dfs(a_copy);
  }
}

int main() {
  // 入力
  cin >> n >> m >> q;
  kumi.resize(q, vi(4));
  rep(i, 0, q) rep(j, 0, 4) cin >> kumi[i][j];

  // 空の状態からスタートしてdfs
  vi a;
  dfs(a);

  cout << ans << endl;

  return 0;
}
