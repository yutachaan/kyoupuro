// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A;
  for (int i = 0; i < N; i++) {
    int A_i;
    cin >> A_i;
    A.push_back(A_i);
  }
  sort(A.begin(), A.end());

  for (int j = 0; j < Q; j++) {
    int x;
    cin >> x;

    cout << A.size() - (lower_bound(A.begin(), A.end(), x) - A.begin()) << endl;
  }

  return 0;
}
