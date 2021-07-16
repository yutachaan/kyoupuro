// AC
// 大文字と小文字の入れ替え
#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    char c;
    scanf("%c", &c);

    if (c == '\n') break;

    if (isalpha(c)) {
      if (isupper(c)) cout << (char)tolower(c);
      else cout << (char)toupper(c);
    }
    else cout << c;
  }
  cout << endl;

  return 0;
}
