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
  friend constexpr modint<MOD> modpow(const modint<MOD> &a, ll n) noexcept {
      if (n == 0) return 1;
      auto t = modpow(a, n / 2);
      t = t * t;
      if (n & 1) t = t * a;
      return t;
  }
};

const int MOD = 1000000007;
using mint = modint<MOD>;


int main() {
  int N, Q; cin >> N >> Q;

  vi d(N + 1); // 累計降雪量の階差
  while (Q--) {
    int L, R, X; cin >> L >> R >> X;
    L--; R--;

    d[L] += X;
    d[R + 1] -= X;
  }

  rep(i, 1, N) {
    if (d[i] > 0) cout << '<';
    else if (d[i] < 0) cout << '>';
    else cout << '=';
  }
  cout << endl;
}
