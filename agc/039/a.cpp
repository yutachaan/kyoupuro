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

// sの編集量
ll solve(string s) {
  ll ret = 0;
  for(int i = 0; i < SIZE(s) - 1;) {
    if (s[i] == s[i + 1]) {
      int renzoku = 1, j = i + 1;
      while (j < SIZE(s) and s[i] == s[j]) {
        renzoku++; j++;
      }
      i += j - i;

      ret += renzoku / 2; // 同じ文字がrenzoku文字連続している時，renzoku/2個編集すればよい
    }
    else i++;
  }

  return ret;
}


int main() {
  string s;
  int k;
  cin >> s >> k;

  // 全部同じ文字か確かめる
  bool is_all = true;
  rep(i, 0, SIZE(s) - 1) if (s[i] != s[i + 1]) is_all = false;

  ll ans = 0;
  if (is_all) ans = SIZE(s) * k / 2;
  else {
    ans = solve(s);
    if (k != 1) ans += (solve(s + s) - solve(s)) * (k - 1);
  }

  cout << ans << endl;

  return 0;
}
