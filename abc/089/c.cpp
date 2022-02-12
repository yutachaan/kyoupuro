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


int main() {
  int n; cin >> n;
  string march = "MARCH";

  // 先頭がMARCHのいずれかなら， 先頭の文字の個数をインクリメント
  map<char, int> mp = {{'M', 0}, {'A', 0}, {'R', 0}, {'C', 0}, {'H', 0}};
  rep(i, 0, n) {
    string s; cin >> s;
    if (march.find(s[0]) != string::npos) mp[s[0]]++;
  }

  ll ans = 0;

  // MARCHの5つから3つ選ぶ組み合わせ全探索
  vector<bool> a(5, false);
  fill(begin(a), begin(a) + 3, true);
  do {
    // その組み合わせを作ることのできる場合の数を計算
    ll temp = 1;
    rep(i, 0, 5) {
      if (a[i]) temp *= mp[march[i]];
    }
    ans += temp;
  } while (prev_permutation(ALL(a)));

  cout << ans << endl;

  return 0;
}
