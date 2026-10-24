#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<int> a[MAXN];
int n, m, k, c, ans;
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    for (int i = 1; i <= m; ++i) a[i].clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c);
      a[c].push_back(i);
    }
    ans = 0;
    for (int c = 1; c <= m; ++c) {
      const vector<int> &d = a[c];
      if (d.empty()) continue;
      int cost = 0, s = 0, t = 1;
      for (s = 0; s < d.size(); ++s) {
        for (t = max(s + 1, t); t < d.size() && cost + d[t] - d[t - 1] - 1 <= k;
             ++t)
          cost += d[t] - d[t - 1] - 1;
        ans = max(ans, t - s);
        if (s + 1 < t) cost -= d[s + 1] - d[s] - 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
