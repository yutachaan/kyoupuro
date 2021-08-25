// TLE
// Sから3桁選び，それを暗証番号とするとき，暗証番号は何通りあるか
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int N;
//   string S;
//   cin >> N >> S;

//   int ans = 0;
//   set<string> password;

//   bool a[N] = {false};
//   fill(a, a + 3, true);
//   do {
//     string s = "";
//     for (int i = 0; i < N; i++) {
//       if (a[i])  s += S[i];
//     }

//     if (password.find(s) == password.end()) {
//       password.insert(s);
//       ans++;
//     }
//   } while (prev_permutation(a, a + N));

//   cout << ans << endl;

//   return 0;
// }

// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  // v1〜v3は暗証番号の1〜3桁目
  for (int v1 = 0; v1 <= 9; v1++) {
    for (int v2 = 0; v2 <= 9; v2++) {
      for (int v3 = 0; v3 <= 9; v3++){
        int index = 0, V[3] = {v1, v2, v3};

        // v1=S[i]を満たす最も小さいiがみつかった場合，それをp1とする
        // iをp1+1以上の範囲にしぼり，v2=S[i]を満たす最も小さいiが見つかった場合，それをp2とする
        // 以後同様に繰り返す．iが見つからなかった場合はその暗証番号を作ることはできない
        for (int i = 0; i < N; i++){
            if (V[index] == S[i] - '0') index++;
        }

        if (index == 3) ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
