#include <bits/stdc++.h>
using namespace std;
int a[105][3];
vector<int> col[5], num[105], un;
int main() {
  long long n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s[0] == 'R')
      a[i][0] = 5;
    else if (s[0] == 'G')
      a[i][0] = 6;
    else if (s[0] == 'B')
      a[i][0] = 7;
    else if (s[0] == 'Y')
      a[i][0] = 8;
    else if (s[0] == 'W')
      a[i][0] = 9;
    a[i][1] = s[1] - '1';
    a[i][2] = 0;
  }
  int ans = 10;
  for (int i = 0; i < (1 << 10); i++) {
    int re = 0;
    for (int j = 0; j < 10; j++) {
      int t = (1 << j) & i;
      if (t != 0) {
        re++;
        for (int k = 0; k < n; k++) {
          if (a[k][0] == j)
            a[k][2] += 1;
          else if (a[k][1] == j)
            a[k][2] += 2;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (a[j][2] == 1)
        col[a[j][0] - 5].push_back(a[j][1]);
      else if (a[j][2] == 2)
        num[a[j][1]].push_back(a[j][0]);
      else if (a[j][2] == 0)
        un.push_back(a[j][0] * 10 + a[j][1]);
    }
    bool flag = true;
    for (int j = 0; j < 5; j++) {
      for (int k = 1; k < col[j].size(); k++) {
        if (col[j][k] != col[j][k - 1]) {
          flag = false;
          break;
        }
      }
      if (flag == false) break;
      for (int k = 1; k < num[j].size(); k++) {
        if (num[j][k] != num[j][k - 1]) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    for (int j = 1; j < un.size(); j++) {
      if (un[j] != un[j - 1]) {
        flag = false;
        break;
      }
    }
    if (flag) ans = min(ans, re);
    un.clear();
    for (int i = 0; i < 5; i++) {
      col[i].clear();
      num[i].clear();
    }
    for (int i = 0; i < n; i++) a[i][2] = 0;
  }
  cout << ans << endl;
  return 0;
}
