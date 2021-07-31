// AC
// 整数をK種類以下にするために書き換える整数の個数の最小値
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int A[N];
  for (int i = 0; i < N; i++) A[i] = 0;

  // バケット法
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    A[a - 1]++;
  }
  sort(A, A + N); // 個数が少ない物を選びたいため昇順ソート

  int ans = 0;
  for (int i = 0; i < N - K; i++) ans += A[i]; // N-K個だけ種類を減らす必要がある

  cout << ans << endl;

  return 0;
}
