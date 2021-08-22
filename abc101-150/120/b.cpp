// AC
// AとBの公約数のうち，K番目に大きいもの
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  if (A > B) swap(A, B); // Aのほうが小さくなるようにする

  vector<int> divisor;
  for (int i = 1; i <= A; i++) {
    if ((A % i == 0) && (B % i == 0)) divisor.push_back(i);
  }

  cout << divisor[divisor.size() - K] << endl;

  return 0;
}
