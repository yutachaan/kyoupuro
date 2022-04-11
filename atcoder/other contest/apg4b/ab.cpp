#include <bits/stdc++.h>
using namespace std;


struct Clock {
  int hour;
  int minute;
  int second;

  // メンバ変数に代入
  void set(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
  }

  // メンバ変数が表す時刻の文字列を"HH:MM:SS"形式で返す
  string to_str() {
    ostringstream H, M, S;
    H << setfill('0') << setw(2) << hour;
    M << setfill('0') << setw(2) << minute;
    S << setfill('0') << setw(2) << second;

    string ret = H.str() + ':' + M.str() + ':' + S.str();

    return ret;
  }

  void shift(int diff_second) {
    int now = hour * 3600 + minute * 60 + second;
    int next = now + diff_second;

    if (next < 0) next += 86400;

    hour = next / 3600 % 24;
    minute = next % 3600 / 60;
    second = next % 3600 % 60;
  }
};

int main() {
  int hour, minute, second, diff_second; cin >> hour >> minute >> second >> diff_second;

  Clock clock;

  // 時刻を設定する
  clock.set(hour, minute, second);

  // 時刻を出力
  cout << clock.to_str() << endl;

  // 時計を進める(戻す)
  clock.shift(diff_second);

  // 変更後の時刻を出力
  cout << clock.to_str() << endl;
}
