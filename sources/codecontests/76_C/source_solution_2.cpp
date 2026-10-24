#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int a, b, c, d, i, j, n, m, k, ans, T;
char str[200003];
int p[22], cs[22][22], dp[1 << 22];
pair<int, int> cur[26];
int main() {
  scanf("%d%d%d", &n, &k, &T);
  scanf("%s", str);
  for (int _n((k)-1), i(0); i <= _n; i++) scanf("%d", &p[i]);
  for (int _n((k)-1), i(0); i <= _n; i++)
    for (int _n((k)-1), j(0); j <= _n; j++) scanf("%d", &cs[i][j]);
  cur[0] = make_pair(-1, -1);
  int were = 0;
  for (int i = (n - 1), _b = (0); i >= _b; i--) {
    int mask = 0, t = str[i] - 'A';
    were |= 1 << t;
    for (int _n((k)-1), j(0); j <= _n; j++) {
      if (cur[j].first == -1) break;
      dp[mask] += cs[t][cur[j].second];
      dp[mask | 1 << t] -= cs[t][cur[j].second];
      dp[mask | 1 << cur[j].second] -= cs[t][cur[j].second];
      dp[mask | (1 << t) | (1 << cur[j].second)] += cs[t][cur[j].second];
      mask |= 1 << cur[j].second;
      if (cur[j].second == t) break;
    }
    for (int _n((k)-1), j(0); j <= _n; j++) {
      if (cur[j].first == -1 || cur[j].second == t) {
        bool tt = 0;
        if (cur[j].first == -1) tt = 1;
        cur[j] = make_pair(i, t);
        for (int z = (j - 1), _b = (0); z >= _b; z--) swap(cur[z], cur[z + 1]);
        if (tt) cur[j + 1] = make_pair(-1, -1);
        break;
      }
    }
  }
  ans = 0;
  for (int _n((k)-1), i(0); i <= _n; i++) {
    for (int _n((were)-1), mask(0); mask <= _n; mask++) {
      if ((mask & were) != mask) continue;
      if (mask & 1 << i) dp[mask] += dp[mask ^ 1 << i];
    }
  }
  for (int _n((were)-1), mask(0); mask <= _n; mask++) {
    if ((mask & were) != mask) continue;
    c = dp[mask];
    for (int _n((k)-1), i(0); i <= _n; i++)
      if (mask & 1 << i) c += p[i];
    if (c <= T) ++ans;
  }
  printf("%d\n", ans);
}
