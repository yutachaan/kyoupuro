// AC
// Sの各文字を並べ替えて作ることが可能な文字列を辞書順にすべて列挙したとき、前からK番目にくる文字列
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;

  set<string> s;
  int a[S.size()];
  for (int i = 0; i < S.size(); i++) a[i] = i;
  do {
    string temp;
    for (int i = 0; i < S.size(); i++) temp += S[a[i]];

    s.insert(temp);
  } while(next_permutation(a, a + S.size()));

  auto itr = s.begin();
  for (int i = 1; i < K; i++) itr++;
  cout << *itr << endl;

  return 0;
}

// 簡潔な方法
// #include<bits/stdc++.h>

// using namespace std;

// int main(){
//   string S;
//   int K;
//   cin >> S >> K;

//   sort(S.begin(),S.end());
//   for (int i = 1; i < K; i++) {
//     next_permutation(S.begin(),S.end());
//   }

//   cout << S << endl;

//   return 0;
// }
