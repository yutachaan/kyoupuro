#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

using vi  = vector<int>;
using vvi = vector<vi>;
using vl  = vector<ll>;
using vvl = vector<vl>;
using vs  = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;
using msi = map<string, int>;
using si  = set<int>;
using ss  = set<string>;

// <----- REPマクロ ----->
#define rep(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define foreach(e, x) for (auto&& (e): x)

// <----- 略記 ----->
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << endl
#define yesno(n) cout << ((n) ? "yes" : "no") << endl
#define YesNo(n) cout << ((n) ? "Yes" : "No") << endl

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

vi t;
vvi A;
vector<bool> is_syutoku;
ll ans;

void syutoku(int n) {
  // 習得済みならreturn
  if (is_syutoku[n]) return;

  // 技nの習得に必要な技をそれぞれ習得しにいく
  foreach(w, A[n]) {
    w--;
    syutoku(w);
    is_syutoku[w] = true;
  }

  // 技nの習得時間を足す
  ans += t[n];
}

int main() {
  // 入力
  int n; cin >> n;
  t.resize(n); A.resize(n);
  rep(i, 0, n) {
    cin >> t[i];

    int k; cin >> k;
    if (k == 0) A[i] = {};
    else {
      vi Ak(k);
      rep(j, 0, k) cin >> Ak[j];
      A[i] = Ak;
    }
  }

  // 習得済みならtrueを持つ
  is_syutoku.resize(n);
  rep(i, 0, n) is_syutoku[i] = false;

  syutoku(n - 1);

  cout << ans << endl;

  return 0;
}
