// AC
// mapを用いたバケット法
#include <bits/stdc++.h>

using namespace std;

int main() {
  map<string ,int> point;

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    point[s]++;
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    string t;
    cin >> t;

    point[t]--;
  }

  int max_point = 0;
  for (const auto& [word, p] : point){
    if (max_point < p) max_point = p;
  }

  cout << max_point << endl;

  return 0;
}
