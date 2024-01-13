// #define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = numeric_limits<int>::max() / 2;
const ll infl = numeric_limits<ll>::max()  / 2;

using vi  = vector<int>;
using vvi = vector<vi>;
using vl  = vector<ll>;
using vvl = vector<vl>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

// <----- rep macro ----->
#define rep(var, a, b)  for (auto var = (a); var < (b); var++)
#define rrep(var, a, b) for (auto var = a - 1; var >= (b); var--)
#define fore(e, x) for (auto &&e: x)
#define fore2(k, v, x) for (auto &[k, v]: x)

// <----- other macro ----->
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
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

// <----- ModInt ----->
template<int MOD> struct modint {
  ll val;
  constexpr modint(ll v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }
  constexpr int getmod() { return MOD; }
  constexpr modint operator - () const noexcept { return val ? MOD - val : 0; }
  constexpr modint operator + (const modint& r) const noexcept { return modint(*this) += r; }
  constexpr modint operator - (const modint& r) const noexcept { return modint(*this) -= r; }
  constexpr modint operator * (const modint& r) const noexcept { return modint(*this) *= r; }
  constexpr modint operator / (const modint& r) const noexcept { return modint(*this) /= r; }
  constexpr modint& operator += (const modint& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr modint& operator -= (const modint& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr modint& operator *= (const modint& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr modint& operator /= (const modint& r) noexcept {
    ll a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const modint& r) const noexcept { return this->val == r.val; }
  constexpr bool operator != (const modint& r) const noexcept { return this->val != r.val; }
  friend constexpr ostream& operator << (ostream &os, const modint<MOD>& x) noexcept { return os << x.val; }
  constexpr modint<MOD> modpow(ll n) noexcept {
      if (n == 0) return 1;
      auto t = modpow(n / 2);
      t *= t;
      if (n & 1) t *= modint(*this);
      return t;
  }
};

const int MOD = 1000000007;
using mint = modint<MOD>;


int main() {
  int N1, N2, M; cin >> N1 >> N2 >> M;
  vvi G1(N1), G2(N2);
  rep(i, 0, M) {
    int a, b; cin >> a >> b;
    a--; b--;

    // 連結成分でグラフをわけてもつために頂点番号を調整
    if (a < N1) {
      G1[a].push_back(b);
      G1[b].push_back(a);
    }
    else {
      a -= N1; b -= N1;
      G2[a].push_back(b);
      G2[b].push_back(a);
    }
  }

  // 一つ目の連結成分について頂点1を起点にBFS
  vi dist1(N1, -1); dist1[0] = 0;
  queue<int> q1; q1.push(0);
  while (!q1.empty()) {
    int v = q1.front();
    q1.pop();

    fore(u, G1[v]) {
      if (dist1[u] != -1) continue;

      dist1[u] = dist1[v] + 1;
      q1.push(u);
    }
  }

  // 二つ目の連結成分について頂点N1+N2を起点にBFS
  vi dist2(N2, -1); dist2[N2 - 1] = 0;
  queue<int> q2; q2.push(N2 - 1);
  while (!q2.empty()) {
    int v = q2.front();
    q2.pop();

    fore(u, G2[v]) {
      if (dist2[u] != -1) continue;

      dist2[u] = dist2[v] + 1;
      q2.push(u);
    }
  }

  // 頂点1から最も距離が遠い頂点までの最短距離+頂点N1+N2から最も距離が遠い頂点までの最短距離+1(新しい辺)
  int ans = *max_element(ALL(dist1)) + *max_element(ALL(dist2)) + 1;

  cout << ans << endl;
}
