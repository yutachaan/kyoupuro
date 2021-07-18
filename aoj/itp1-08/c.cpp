// AC
// 英文に含まれる各アルファベットの数のカウント
#include <bits/stdc++.h>

using namespace std;

int main() {
  char c;
  int n_alphabet[26];

  // 初期化
  for (int i = 0; i < 26; i++) n_alphabet[i] = 0;

  // カウント
  while (cin >> c) {         // EOFまで
    if (isalpha(c)) {
      c = (char)tolower(c);
      n_alphabet[c - 'a']++;
    }
  }

  // 出力
  for (int i = 0; i < 26; i++) {
    cout << (char)('a' + i) << " : " << n_alphabet[i] << endl;
  }

  return 0;
}
