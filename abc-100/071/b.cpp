// AC
// 文字列中に現れていないアルファベット
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  sort(S.begin(), S.end());

  int alphabet = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] - 'a' == alphabet) alphabet++;
  }

  if (alphabet == 26) cout << "None" << endl;
  else cout << static_cast<char>('a' + alphabet) << endl;

  return 0;
}
