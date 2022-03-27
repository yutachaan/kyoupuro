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
  int N, K; cin >> N >> K;
  vi A(N), B(N);
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) cin >> B[i];

  vector<bool> dpA(N, false), dpB(N, false); // dpA[i]: X_0, ... X_i - 1 まで考慮した時， X_i = A_i としてよいか
  dpA[0] = true, dpB[0] = true;

  rep(i, 1, N) {
    if (dpA[i - 1]) {
      if (abs(A[i - 1] - A[i]) <= K) dpA[i] = true;
      if (abs(A[i - 1] - B[i]) <= K) dpB[i] = true;
    }
    if (dpB[i - 1]) {
      if (abs(B[i - 1] - A[i]) <= K) dpA[i] = true;
      if (abs(B[i - 1] - B[i]) <= K) dpB[i] = true;
    }
  }

  YesNo(dpA[N - 1] || dpB[N - 1]);
}
