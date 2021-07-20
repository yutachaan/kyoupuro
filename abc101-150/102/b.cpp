// AC
// 数列内の異なる2要素の差の絶対値の最大値
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  int max = *max_element(A, A + N);
  int min = *min_element(A, A + N);

  cout << max - min << endl;

  return 0;
}
