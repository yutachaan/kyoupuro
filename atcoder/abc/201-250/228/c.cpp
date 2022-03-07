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
  int N, K; cin >> N >> K;

  // 3日目までの得点の合計
  vi P(N);
  rep(i, 0, N) {
    int P1, P2, P3; cin >> P1 >> P2 >> P3;
    P[i] = P1 + P2 + P3;
  }

  vi Pcopy(N);
  copy(ALL(P), back_inserter(Pcopy));
  sort(ALL(Pcopy), greater<int>());

  // 一人だけ300点をとって，他が全員0点の場合に， K位以内に入れば良い
  fore(p, P) YesNo(p + 300 >= Pcopy[K - 1]);

  return 0;
}

