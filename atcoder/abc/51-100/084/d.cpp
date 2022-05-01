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


int N = 100010;

// 1 以上 N 以下の整数が素数かどうかを返す
vb eratosthenes(int n) {
  vb isprime(n + 1, true);
  isprime[1] = false;

  rep(p, 2, n + 1) {
    if (!isprime[p]) continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (int q = p * 2; q <= n; q += p) isprime[q] = false;
  }

  return isprime;
}

int main() {
  int Q; cin >> Q;

  // iが素数かどうかを格納
  vb isprime(N + 1);
  isprime = eratosthenes(N);

  // cumsum_2017[i]: [0, i) までで2017に似た数の累積和
  vi cumsum_2017(N, 0);
  for (int i = 3; i < N; i += 2) {
    if (isprime[i - 2] && isprime[(i - 1) / 2]) cumsum_2017[i] = cumsum_2017[i - 2] + 1;
    else cumsum_2017[i] = cumsum_2017[i - 2];
  }

  // 累積和をもとに解を求める
  rep(_, 0, Q) {
    int l, r; cin >> l >> r;

    cout << cumsum_2017[r + 2] - cumsum_2017[l] << endl;
  }
}
