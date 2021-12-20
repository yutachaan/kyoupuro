#include <bits/stdc++.h>
using namespace std;

// <----- alias ----->
using ll = long long;

const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

using vi  = vector<int>;
using vvi = vector<vi>;
using vs  = vector<string>;
using pii = pair<int, int>;
using mii = map<int, int>;
using msi = map<string, int>;

// <----- REPマクロ ----->
#define FOR(i, a, b)  for (ll i = (a); i < (ll)(b); i++)
#define RFOR(i, a, b) for (ll i = (a) - 1; i >= (b); i--)
#define REP(i, n)     FOR(i, 0, n)
#define REPS(i, n)    FOR(i, 1, n + 1)
#define RREP(i, n)    RFOR(i, n, 0)
#define RREPS(i, n)   RFOR(i, n + 1, 1)
#define FOREACH(e, x) for (auto&& (e): x)

// <----- 略記 ----->
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ll((x).size())

#define YESNO(n) cout << ((n) ? "YES" : "NO") << endl
#define yesno(n) cout << ((n) ? "yes" : "no") << endl
#define YesNo(n) cout << ((n) ? "Yes" : "No") << endl

// <----- function ----->
template <class T> bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <class T> bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}

// <----- other ----->
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
    int h, w;
    cin >> h >> w;

    vs c(h);
    REP(i, h) cin >> c[i];

    vvi f(h + 1, vi(w + 1));
    for (int i = h - 1; i >= 0; i--) {
        for (int j = w - 1; j >= 0; j--) {
            if (c[i][j] == '#') continue;
            f[i][j] = max(f[i + 1][j], f[i][j + 1]) + 1;
        }
    }

    cout << f[0][0] << endl;

    return 0;
}
