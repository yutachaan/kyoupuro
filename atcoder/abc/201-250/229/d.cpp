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
  string S; int K; cin >> S >> K;

  vi cum(SIZE(S) + 1); // S[i]より左側に'.'が何個あるか
  cum[0] = 0;
  rep(i, 0, SIZE(S)) {
    if (S[i] == '.') cum[i + 1] = cum[i] + 1;
    else cum[i + 1] = cum[i];
  }

  int ans = 0, r = 0;
  rep(l, 0, SIZE(S)) {
    // [l, r) に含まれる'.'の数がK以下である間， rを増やす
    while (cum[r + 1] - cum[l] <= K && r < SIZE(S)) r++;

    chmax(ans, (int)(r - l));
  }

  cout << ans << endl;

  return 0;
}
