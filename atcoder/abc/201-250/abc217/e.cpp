// TLE
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   int Q;
//   cin >> Q;

//   queue<int> A;
//   for (int i = 0; i < Q; i++) {
//     int q;
//     cin >> q;

//     if (q == 1) {
//       int x;
//       cin >> x;
//       A.push(x);
//     }
//     else if (q == 2) {
//       cout << A.front() << endl;
//       A.pop();
//     }
//     else {
//       priority_queue<int, vector<int>, greater<int>> temp;
//       while (A.empty() == false) {
//         temp.push(A.front());
//         A.pop();
//       }

//       while (temp.empty() == false) {
//         A.push(temp.top());
//         temp.pop();
//       }
//     }
//   }

//   return 0;
// }

// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int Q;
  cin >> Q;

  queue<int> A;
  priority_queue<int, vector<int>, greater<int>> temp;
  for (int i = 0; i < Q; i++) {
    int q;
    cin >> q;

    if (q == 1) {
      int x;
      cin >> x;
      A.push(x);
    }
    else if (q == 2) {
      if (temp.empty()) {
        cout << A.front() << endl;
        A.pop();
      }
      else {
        cout << temp.top() << endl;
        temp.pop();
      }
    }
    else {
      // tempにAの要素を全て移す(tempは優先度付きキューのためこれでソートになる)
      while (A.empty() == false) {
        temp.push(A.front());
        A.pop();
      }
    }
  }

  return 0;
}
