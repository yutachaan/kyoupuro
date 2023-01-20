// AC
#include <bits/stdc++.h>

using namespace std;

int main() {
  // 各アルファベットが前から何番目かをmapに記録
  map<char, string> X;
  for (int i = 0; i < 26; i++) {
    char x;
    cin >> x;

    if (i < 10) X[x] = '0' + to_string(i);
    else X[x] = to_string(i);
  }

  int N;
  cin >> N;

  // 文字列を，その文字列を構成するアルファベットが何番目に現れるかを順に示した数列に変換
  map<string, string> S_dict_order; // 数列と元の文字列の対応表
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;

    string s_dict_order;
    for (int j = 0; j < S.size(); j++) {
      s_dict_order += X[S[j]] + '_';
    }

    S_dict_order[s_dict_order] = S;
  }

  // 数列でsortすればよい．mapはkeyがsortされているため，順番にvalueを出力すればいい．
  for (auto itr = S_dict_order.begin(); itr != S_dict_order.end(); itr++) cout << itr->second << endl;

  return 0;
}
