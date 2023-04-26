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
  int H, W; cin >> H >> W;
  vvi A(H, vi(W)); rep(i, 0, H) rep(j, 0, W) cin >> A[i][j];

  vi p(H + W - 2); // i方向の移動回数H-1回分の0とj方向の移動回数W-1回分の1をもつ
  rep(j, H - 1, H + W - 2) p[j] = 1;
  int ans = 0;

  // pで順列全探索
  do {
    int i = 0, j = 0;
    set<int> numbers; numbers.insert(A[i][j]);
    fore(e, p) {
      if (e) j++;
      else i++;

      numbers.insert(A[i][j]);
    }

    if (SIZE(numbers) == H + W - 1) ans++;
  } while (next_permutation(ALL(p)));

  cout << ans << endl;
}
