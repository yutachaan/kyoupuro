// AC
// 区間の重なり(二人ともスイッチを押していた秒数)
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int ans = min(B, D) - max(A, C);

  // 0以下の場合は同時に押していた秒数は0
  cout << max(0, ans) << endl;

  return 0;
}
