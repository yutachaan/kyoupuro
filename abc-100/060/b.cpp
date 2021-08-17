// WA(1)
// Aの倍数 % B == Cとなるか判定
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (A == 1) {
    cout << "YES" << endl;
    return 0;
  }

  for (long long int i = A; ; i += A) {
    if (i % B == C) {
      cout << "YES" << endl;
      break;
    }
    else if ((i % B == 1) || (i % B == 0)) {
      cout << "NO" << endl;
      break;
    }
  }

  return 0;
}

// AC
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int A, B, C;
//   cin >> A >> B >> C;

//   bool OK = false;
//   for (int i = A; i <= A * B; i += A) {
//     if (i % B == C) OK = true;
//   }

//   if (OK) cout << "YES" << endl;
//   else cout << "NO" << endl;

//   return 0;
// }
