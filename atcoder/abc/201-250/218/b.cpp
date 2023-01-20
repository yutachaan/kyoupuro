// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  string alphabet = "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < 26; i++) {
    int P;
    cin >> P;

    cout << alphabet[P - 1];
  }

  cout << endl;

  return 0;
}
