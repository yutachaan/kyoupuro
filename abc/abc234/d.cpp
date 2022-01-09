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
    // 入力
    int n, k; cin >> n >> k;
    vi p(n);
    rep(i, 0, n) cin >> p[i];

    // この優先度付きキューの大きさは常にkとする(すると， O(klogk)で求められるはずなので，間に合う)
    priority_queue<int, vi, greater<int>> p_sentou_sorted;
    rep(i, 0, k) p_sentou_sorted.push(p[i]);

    // i=kのときの答えを出力
    cout << p_sentou_sorted.top() << endl;

    // i=k+1以降
    rep(i, k, n) {
        p_sentou_sorted.push(p[i]);            // 次に見る要素を追加
        p_sentou_sorted.pop();                 // 一番小さい要素を削除
        cout << p_sentou_sorted.top() << endl; // 削除後，一番小さい要素を表示
    }

    return 0;
}
