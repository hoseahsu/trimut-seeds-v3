#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, l, k;
string s, ans[N];
int main() {
  scanf("%d%d%d", &n, &l, &k);
  cin >> s;
  int len = s.length();
  sort(s.begin(), s.end());
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    ans[i] += s[cnt++];
  }
  int same = 0;
  for (int i = 1; i < k; i++) {
    if (ans[i] == ans[k]) {
      same = i;
      break;
    }
  }
  if (same) {
    while (cnt < len) {
      bool flag = true;
      for (int i = same; i <= k; i++) {
        if (ans[i].size() < l) ans[i] += s[cnt++];
      }
      if (ans[k].length() == l) break;
      for (int i = 1; i < k; i++) {
        if (ans[i] == ans[k]) {
          same = i;
          flag = false;
          break;
        }
      }
      if (flag) break;
    }
  }
  while (ans[k].size() < l) ans[k] += s[cnt++];
  for (int i = 1; i <= n; i++) {
    while (ans[i].length() < l) ans[i] += s[cnt++];
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
