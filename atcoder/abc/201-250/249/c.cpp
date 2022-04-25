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
  int N, K; cin >> N >> K;
  vs S(N);
  fore(s, S) cin >> s;

  vvi apper(N, vi(26, 0)); // 文字列Siに各アルファベットが出現するか(するなら1)
  rep(i, 0, N) fore(c, S[i]) apper[i][c - 'a']++;

  int ans = 0;
  // 各文字列を選ぶか選ばないかでbit全探索
  rep(bit, 0, 1 << N) {
    vi count_alpha(26, 0); // 各アルファベットが出現する回数
    rep(i, 0, N) {
      // 選ぶ場合
      if (bit & (1 << i)) {
        rep(j, 0, 26) count_alpha[j] += apper[i][j];
      }
    }

    // K回出現したアルファベットの個数を数える
    int count = 0;
    fore(x, count_alpha) {
      if (x == K) count++;
    }

    chmax(ans, count);
  }

  cout << ans << endl;
}
