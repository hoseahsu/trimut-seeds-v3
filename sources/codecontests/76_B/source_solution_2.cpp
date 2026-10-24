#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int n, m;
int botva[100100], y2[100100];
multiset<int> ans[100100];
int main() {
  int y3, y4;
  scanf("%d %d %d %d", &n, &m, &y3, &y4);
  if (m == 0) {
    cout << n << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) scanf("%d", &botva[i]);
  for (int i = 0; i < m; i++) scanf("%d", &y2[i]);
  for (int i = 0; i < n; i++) {
    int t1 = lower_bound(y2, y2 + m, botva[i]) - y2, t2 = t1 - 1;
    if (t2 < 0) {
      ans[t1].insert(abs(botva[i] - y2[t1]));
      continue;
    }
    if (t1 >= m || botva[i] - y2[t2] < y2[t1] - botva[i]) {
      ans[t2].insert(abs(botva[i] - y2[t2]));
      continue;
    }
    if (botva[i] - y2[t2] > y2[t1] - botva[i]) {
      ans[t1].insert(abs(botva[i] - y2[t1]));
      continue;
    }
    if (ans[t2].empty() || (*ans[t2].begin() == abs(botva[i] - y2[t2])))
      ans[t2].insert(abs(botva[i] - y2[t2]));
    else
      ans[t1].insert(abs(botva[i] - y2[t1]));
  }
  int ans1 = 0;
  for (int i = 0; i < m; i++) {
    int ans2 = 0;
    for (multiset<int>::iterator it = ans[i].begin();
         it != ans[i].end() && (*it == *ans[i].begin()); it++)
      ans2++;
    ans1 += ans[i].size() - ans2;
  }
  cout << ans1 << endl;
  return 0;
}
