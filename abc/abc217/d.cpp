// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int L, Q;
  cin >> L >> Q;

  set<int> cut = {0}; // 切った場所(昇順)．0は便宜上．
  for (int i = 0; i < Q; i++) {
    int c, x;
    cin >> c >> x;

    if (c == 1) cut.insert(x);
    else {
      if (x < *cut.begin()) cout << *cut.begin() << endl;            // 一番左の切った場所よりもxが左に位置していた場合
      else if (x > *cut.rbegin()) cout << L - *cut.rbegin() << endl; // 一番右の切った場所よりもxが右に位置していた場合
      else {                                                         // 2つの切った場所に挟まれていた場合
        auto itr = cut.lower_bound(x);   // xに最も近い，xよりも右側の切った場所のイレテータ
        cout << *itr - *(--itr) << endl;
      }
    }
  }

  return 0;
}
