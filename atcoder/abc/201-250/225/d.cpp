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
  int N, Q; cin >> N >> Q;

  vi ushiro(N, -1), mae(N, -1); // 電車i (0-index) の後部あるいは前部に連結している電車の番号 (連結していない場合は-1)

  rep(_, 0, Q) {
    int order; cin >> order;

    if (order == 1) {
      int x, y; cin >> x >> y;
      x--; y--;

      ushiro[x] = y;
      mae[y] = x;
    }
    else if (order == 2) {
      int x, y; cin >> x >> y;
      x--; y--;

      ushiro[x] = mae[y] = -1;
    }
    else {
      int x; cin >> x;
      x--;

      // 先頭車両になるまで前に移動
      while (mae[x] != -1) x = mae[x];

      // 最後尾車両になるまでansに番号を追加しながら後ろに移動
      vi ans;
      while (x != -1) {
        ans.push_back(x + 1);
        x = ushiro[x];
      }

      // 出力
      cout << SIZE(ans) << ' ';
      fore(e, ans) cout << e << ' ';
      cout << endl;
    }
  }
}
