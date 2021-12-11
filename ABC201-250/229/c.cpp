// AC
// ソート
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, W;
  cin >> N >> W;

  vector<pair<int, int>> AB;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    AB.push_back({A, B});
  }
  sort(AB.begin(), AB.end(), greater<pair<int, int>>());

  long long int ans = 0, i = 0;
  while ((W > 0) && (i < N)) {
    if (AB[i].second == 0) i++;

    ans += AB[i].first;
    AB[i].second--;
    W--;
  }

  cout << ans << endl;

  return 0;
}
