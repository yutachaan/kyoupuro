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
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {a = b; return true;}
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {a = b; return true;}
  return false;
}


int main() {
  ll N, X; cin >> N >> X;
  string S; cin >> S;

  // Sにおいて， RやLの直後にUがきた場合はその操作はなかったに等しいので，R/Lを取り除く
  stack<char> st;
  fore(c, S) {
    if (c == 'U' && !st.empty() && st.top() != 'U') st.pop();
    else st.push(c);
  }

  // そのようにしてつくった文字列をTとする
  string T = "";
  while (!st.empty()) {
    T = st.top() + T;
    st.pop();
  }

  // 答えが10^18以下になるため，普通にシミュレートする
  fore(c, T) {
    if (c == 'L') X *= 2;
    else if (c == 'R') X = X * 2 + 1;
    else X /= 2;
  }

  cout << X << endl;

  return 0;
}
