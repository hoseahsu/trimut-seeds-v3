#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  stack<string> strs;
  while (n--) {
    string str;
    cin >> str;
    strs.push(str);
  }
  string now = strs.top();
  strs.pop();
  int cal1 = 0, cal2 = 0, res = 0, cnt = 0;
  char ch1 = now.front(), ch2 = now.back(), last = '$';
  for (int i = 0; i != (int)now.size(); ++i) {
    if (now[i] == ch1)
      ++cal1;
    else
      break;
  }
  for (int i = now.size() - 1; ~i; --i) {
    if (now[i] == ch2)
      ++cal2;
    else
      break;
  }
  for (const auto& ch : now) {
    if (ch != last) cnt = 0;
    res = max(res, ++cnt);
    last = ch;
  }
  bool check = res == (int)now.size();
  while (!strs.empty()) {
    now = strs.top();
    strs.pop();
    if (check) {
      int tmp1 = 0, tmp2 = 0, tmp = 0;
      for (int i = 0; i != (int)now.size(); ++i) {
        if (now[i] == ch1)
          ++tmp1;
        else
          break;
      }
      cal1 = tmp1 + (tmp1 + 1) * res;
      for (int i = now.size() - 1; ~i; --i) {
        if (now[i] == ch1)
          ++tmp2;
        else
          break;
      }
      cal2 = tmp2 + (tmp2 + 1) * res;
      cnt = 0;
      for (const auto& ch : now) {
        if (ch != ch1)
          cnt = 0;
        else
          tmp = max(tmp, ++cnt);
      }
      res = max(res, tmp + (tmp + 1) * res);
      check = tmp == (int)now.size();
    } else if (ch1 == ch2) {
      if (~now.find(ch1)) res = max(res, cal1 + cal2 + 1);
    } else {
      if (~now.find(ch1)) res = max(res, cal1 + 1);
      if (~now.find(ch2)) res = max(res, cal2 + 1);
    }
  }
  cout << res << endl;
}
