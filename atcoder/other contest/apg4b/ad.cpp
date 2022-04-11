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


// 変数名とその値を保存
map<char, int> mp_i;
map<char, vi> mp_vec;

// 数字または変数を数値化
int num(char c) {
  if (isdigit(c)) return c - '0'; // 数字ならそのまま返す
  else return mp_i[c];            // 変数ならmapから読み込んで返す
}

// int式を読み込む
int cin_int() {
  // 最初の1つ
  char c; cin >> c;
  int ret = num(c);

  // 以降の文字
  while (true) {
    cin >> c;
    if (c == ';') break;

    if (c == '+') {
      cin >> c;
      ret += num(c);
    }
    else {
      cin >> c;
      ret -= num(c);
    }
  }

  return ret;
}

// 変数またはvectorを表す文字列をvector化
vi vec(char c) {
  vi ret;
  if (c == '[') {
    while(true) {
      cin >> c;
      ret.push_back(num(c));

      cin >> c;
      if (c == ']') break;
    }
  }
  else ret = mp_vec[c];

  return ret;
}

// vec式を読み込む
vi cin_vec() {
  // 最初の1つ
  char c; cin >> c;
  vi a = vec(c);

  // 以降の文字
  while (true) {
    cin >> c;
    if (c == ';') break;

    if (c == '+') {
      cin >> c;
      vi b = vec(c);

      rep(i, 0, SIZE(a)) a[i] += b[i];
    }
    else {
      cin >> c;
      vi b = vec(c);

      rep(i, 0, SIZE(a)) a[i] -= b[i];
    }
  }

  return a;
}

int main() {
  int N; cin >> N;

  rep(i, 0, N) {
    string command; cin >> command;

    if (command == "int") {
      char v, _; cin >> v >> _; // v: 変数名, _: =

      mp_i[v] = cin_int();
    }
    else if (command == "print_int") {
      cout << cin_int() << endl;
    }
    else if (command == "vec") {
      char v, _; cin >> v >> _; // v: 変数名, _: =

      mp_vec[v] = cin_vec();
    }
    else if (command == "print_vec") {
      vi a = cin_vec();

      cout << "[ ";
      fore(x, a) cout << x << ' ';
      cout << "]" << endl;
    }
  }
}
