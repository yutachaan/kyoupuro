// AC
// N=10^5の全探索アルゴリズムの改善
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int price;
  // Aピザ0.5枚の値段+Bピザ0.5枚の値段よりABピザ1枚のほうが安い場合，可能な限りABピザを買った方がいい
  if (C <= A / 2 + B / 2) {
    if (X <= Y) {
      // Bピザ1枚の値段より，ABピザ2枚をBピザ1枚としたほうが安い場合は，全てABピザにする
      if (C * 2 < B) price = Y * C * 2;
      // そうでない場合は，XとYで少ない方の枚数に合わせてABピザを購入し，余った分を通常通り購入
      else price = X * C * 2 + (Y - X) * B;
    }
    else {
      if (C * 2 < A) price = X * C * 2;
      else price = Y * C * 2 + (X - Y) * A;
    }
  }
  // それ以外の場合は通常通り購入
  else price = X * A + Y * B;

  cout << price << endl;

  return 0;
}
