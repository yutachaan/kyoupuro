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
  int A, B, C, D, E, F, X; cin >> A >> B >> C >> D >> E >> F >> X;

  // シミュレーション
  int t_ta = 0, t_ao = 0, d_ta = 0, d_ao = 0;
  while (X - t_ta > 0) {
    d_ta += min(X - t_ta, A) * B;
    t_ta += min(X - t_ta, A) + C;
  }
  while (X - t_ao > 0) {
    d_ao += min(X - t_ao, D) * E;
    t_ao += min(X - t_ao, D) + F;
  }

  if (d_ta > d_ao) cout << "Takahashi" << endl;
  else if (d_ta < d_ao) cout << "Aoki" << endl;
  else cout << "Draw" << endl;
}
