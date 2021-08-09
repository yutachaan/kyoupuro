// AC
// バケット法
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int bucket[100002] = {0}; // -1〜100000
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    a++;      // a=0のとき，配列の範囲外にアクセスしてしまうため，全体を+1する

    bucket[a - 1]++;
    bucket[a]++;
    bucket[a + 1]++;
  }

  int ans = *max_element(bucket, bucket + 100000);

  cout << ans << endl;

  return 0;
}
