// x
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


int main() {
  int a, n; cin >> a >> n;

  vi d(1000000, -1); d[1] = 0;
  queue<int> q; q.push(1);

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    // a倍にした場合
    ll temp = (ll) x * a;
    if (temp < 1000000){
      if (d[temp] == -1) {
        d[temp] = d[x] + 1;
        q.push(temp);
      }
    }

    // 回転させた場合
    if (x >= 10 && x % 10 != 0) {
      string sx = to_string(x);
      rotate(sx.begin(), sx.end() - 1, sx.end());
      int y = stoi(sx);

      if (d[y] == -1) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }

  cout << d[n] << endl;
}
