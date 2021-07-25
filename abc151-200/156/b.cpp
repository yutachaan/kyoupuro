// AC
// K進数で表した時の桁数
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K, ans = 0;
  cin >> N >> K;

  long long int power_K = 1; // Kの累乗

  // Kを累乗していき，Nを超えたら終了．累乗するとK進法での桁数が1増えるため，ansを加算
  while (power_K <= N) {
    power_K *= K;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
