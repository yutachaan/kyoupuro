// AC
// map 最大値
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  map<string, int> vote;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;

    if (vote.count(S) == 0) vote.insert({S, 1});
    else vote[S]++;
  }

  int ans_votes = 0;
  string ans;
  for(auto i = vote.begin(); i != vote.end(); i++) {
    if (i->second > ans_votes) {
      ans_votes = i->second;
      ans = i->first;
    }
  }

  cout << ans << endl;

  return 0;
}
