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


// 3次正方行列
struct Matrix { double p[3][3] = {{0, 0, 0}, {0, 0, 0}}; };

// 行列の乗算
Matrix Mul(Matrix A, Matrix B) {
  Matrix ret;
  rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) ret.p[i][j] += A.p[i][k] * B.p[k][j];

  return ret;
}

// 行列の累乗(繰り返し二乗法)
Matrix Power(Matrix A, ll n) {
  Matrix ret; ret.p[0][0] = ret.p[1][1] = ret.p[2][2] = 1;
  while (n > 0) {
    if (n & 1) ret = Mul(ret, A);
    A = Mul(A, A);
    n >>= 1;
  }

  return ret;
}

int main() {
  int Q; cin >> Q;

  while (Q--) {
    double X, Y, Z; cin >> X >> Y >> Z;
    int T; cin >> T;

    // 漸化式を行列に直して解く
    Matrix A;
    A.p[0][0] = 1 - X; A.p[0][1] = Y;
    A.p[1][1] = 1 - Y; A.p[1][2] = Z;
    A.p[2][0] = X; A.p[2][2] = 1 - Z;

    Matrix ApT = Power(A, T);

    double a = ApT.p[0][0] + ApT.p[0][1] + ApT.p[0][2];
    double b = ApT.p[1][0] + ApT.p[1][1] + ApT.p[1][2];
    double c = ApT.p[2][0] + ApT.p[2][1] + ApT.p[2][2];

    printf("%.8lf %.8lf %.8lf\n", a, b, c);
  }
}
