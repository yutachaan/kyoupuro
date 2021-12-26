// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;

  string T = "oxxoxxoxxoxxoxx";

  if (T.find(S) != string::npos) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
