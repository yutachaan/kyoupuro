// AC
// 同姓同名の人がいるかどうか
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  string name[N];
  for (int i = 0; i < N; i++) {
    string S, T;
    cin >> S >> T;

    name[i] = S + ' ' + T;
  }

  bool ans = false;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (name[i] == name[j]) ans = true;
    }
  }

  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
