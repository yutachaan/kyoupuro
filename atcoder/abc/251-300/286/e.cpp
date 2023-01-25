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
using vs  = vector<string>;
using vb  = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

// <----- rep macro ----->
#define rep(i, a, b)  for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= (int)(b); i--)
#define fore(e, x) for (auto &e: x)
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
  int N; cin >> N;
  vi A(N); rep(i, 0, N) cin >> A[i];
  string S[N]; rep(i, 0, N) cin >> S[i];

  // 各都市間の経路を有向グラフとする
  vvi G(N);
  rep(i, 0, N) rep(j, 0, N) {
    if (S[i][j] == 'Y') G[i].push_back(j);
  }

  // 各都市についてBFSで最小直行便数を求める and その経路のうち最大価値を求める
  vvi shortest(N, vi(N, -1));    // iからjへ向かう経路のうち，最小の直行便数
  vector<vl> maxvalue(N, vl(N)); // iからjへ向かう最短経路の最大価値
  rep(i, 0, N) {
    queue<int> q; // 発見済みだが未訪問な都市

    // 都市iを始点とする
    shortest[i][i] = 0;
    maxvalue[i][i] = A[i];
    q.push(i);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      fore(v, G[u]) {
        // 未訪問の場合
        if (shortest[i][v] == -1) {
          shortest[i][v] = shortest[i][u] + 1;    // 最小直行便数を求める
          maxvalue[i][v] = maxvalue[i][u] + A[v]; // その経路の価値を最大価値とする

          q.push(v);
        }
        // すでに訪問しているが， 今辿っている経路でも直行便数が同じく最小となる場合
        else if (shortest[i][v] == shortest[i][u] + 1) {
          chmax(maxvalue[i][v], maxvalue[i][u] + A[v]); // 最大価値を更新
        }
      }
    }
  }

  int Q; cin >> Q;
  while (Q--) {
    int U, V; cin >> U >> V;
    U--; V--;

    if (shortest[U][V] == -1) cout << "Impossible" << endl;
    else cout << shortest[U][V] << ' ' << maxvalue[U][V] << endl;
  }
}
