#include <bits/stdc++.h>
using namespace std;
int ra() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
string ch;
int pos[100], next_pos, last_pos, len, orz;
int ans[100][100], cnt;
int main() {
  cin >> ch;
  char chans;
  for (int i = 0; i <= 26; i++) {
    if (pos[ch[i]]) next_pos = i + 1, last_pos = pos[ch[i]], chans = ch[i];
    pos[ch[i]] = i + 1;
  }
  len = next_pos - last_pos - 1;
  if (len == 0) {
    cout << "Impossible";
    return 0;
  }
  orz = len / 2 + (len % 2);
  ans[2][13 - orz] = ch[last_pos - 2];
  ans[1][13 - orz + (len % 2)] = chans;
  int x = 1, y = 13 - orz + (len % 2);
  for (;;) {
    ++cnt;
    if (y + cnt <= 13)
      ans[1][y + cnt] = ch[last_pos + cnt - 1];
    else
      break;
  }
  int tot = 0;
  cnt--;
  for (;;) {
    if (13 - tot == 13 - orz)
      break;
    else
      ans[2][13 - tot] = ch[last_pos + cnt];
    cnt++;
    tot++;
  }
  tot = 0;
  for (;;) {
    tot--;
    cnt++;
    if (y + tot >= 1)
      ans[1][y + tot] = ch[last_pos + cnt];
    else {
      tot = 0;
      for (; last_pos + cnt <= 26; cnt++) ans[2][++tot] = ch[last_pos + cnt];
      break;
    }
  }
  tot = 13 - orz, cnt = 0;
  for (;;) {
    cnt++;
    tot--;
    if (tot >= 0 && last_pos - cnt - 2 >= 0)
      ans[2][tot] = ch[last_pos - cnt - 2];
    else {
      if (ans[1][1] < (int)'A' || ans[1][1] > (int)'Z') {
        tot = 0;
        for (; cnt <= last_pos; cnt++, tot++) ans[1][tot] = ch[last_pos - cnt];
      }
      break;
    }
  }
  for (int i = 1; i <= 2; i++, cout << endl)
    for (int j = 1; j <= 13; j++) cout << (char)ans[i][j];
  return 0;
}
