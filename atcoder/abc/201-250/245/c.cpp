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
  vi A(N), B(N);
  fore(x, A) cin >> x;
  fore(x, B) cin >> x;

  vb dpA(N, false); // dpA[i]: (X1, ..., Xi) まで考慮した時， Xi = Aiとしてよいか
  vb dpB(N, false); // dpB[i]: (X1, ..., Xi) まで考慮した時， Xi = ABiとしてよいか
  dpA[0] = true; dpB[0] = true;

  rep(i, 1, N) {
    dpA[i] = (dpA[i - 1] && abs(A[i] - A[i - 1]) <= K) || (dpB[i - 1] && abs(A[i] - B[i - 1]) <= K);
    dpB[i] = (dpA[i - 1] && abs(B[i] - A[i - 1]) <= K) || (dpB[i - 1] && abs(B[i] - B[i - 1]) <= K);
  }

  YesNo(dpA[N - 1] || dpB[N - 1]);
}
