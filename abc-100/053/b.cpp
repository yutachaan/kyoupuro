// WA
// 文字列sで，先頭がA，末尾がZであるような連続した部分文字列のうち，最大の長さ
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int ans = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      int temp = 1, j;
      for (j = i + 1; j < s.size(); j++) {
        // Zがきたらbreak(次の文字もZの場合は続行)
        if ((s[j] == 'a') && (s[j + 1] != 'Z')) {
          temp++;
          break;
        }
        else temp++;
      }

      // Zが見つからずに上のforを抜けた場合は行わない
      if ((temp > ans) && (j != s.size())) {
        ans = temp;
        i += temp - 1; // 効率化
      }
    }
  }

  cout << ans << endl;

  return 0;
}

// AC
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   string s;
//   cin >> s;

//   int first_A_index = s.find('A'); // 最も先頭のAのインデックス
//   int last_Z_index = s.rfind('Z'); // 最も末尾のZのインデックス

//   cout << last_Z_index - first_A_index + 1 << endl;

//   return 0;
// }
