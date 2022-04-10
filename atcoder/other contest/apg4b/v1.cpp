#include <bits/stdc++.h>
using namespace std;


// x番の組織について、子組織からの報告書が揃った時刻を返す
int complete_time(vector<vector<int>> &children, int x) {
  if ((int)children.at(x).size() == 0) return 0;

  int time = 0;
  for (int c: children.at(x)) time = max(time, complete_time(children, c) + 1);

  return time;
}

int main() {
  int N; cin >> N;

  vector<int> p(N); p.at(0) = -1;
  for (int i = 1; i < N; i++) cin >> p.at(i);

  vector<vector<int>> children(N); // ある組織の子組織の番号一覧
  for (int i = 1; i < N; i++) {
    int parent = p.at(i);
    children.at(parent).push_back(i);
  }

  cout << complete_time(children, 0) << endl;
}
