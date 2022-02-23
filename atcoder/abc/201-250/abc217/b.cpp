// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  set<string> contests = {"ABC", "ARC", "AGC", "AHC"};

  for (int i = 0; i < 3; i++) {
    string S;
    cin >> S;

    contests.erase(S);
  }

  cout << *contests.begin() << endl;

  return 0;
}
