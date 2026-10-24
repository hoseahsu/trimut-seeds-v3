#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
vector<pair<int, int> > v[N];
map<pair<int, int>, int> mp;
int a[N], b[N], ans[N], now = 0;
void dfs(int x) {
  b[x] = 1;
  if (a[x] == 1) now = !now;
  for (auto i : v[x])
    if (!b[i.first]) {
      if (now == 1) ans[i.second] = !ans[i.second];
      dfs(i.first);
      if (now == 1) ans[i.second] = !ans[i.second];
    }
}
int main() {
  int n, m, i, cnt = 0, f = -1;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == 1) cnt++;
    if (a[i] == -1) f = i;
  }
  if (f == -1 && cnt % 2) {
    printf("-1");
    return 0;
  }
  memset(b, 0, sizeof b);
  for (i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (mp[make_pair(x, y)] == 0) {
      mp[make_pair(x, y)] = mp[make_pair(y, x)] = 1;
      pair<int, int> p = make_pair(x, i);
      v[y].push_back(make_pair(x, i));
      v[x].push_back(make_pair(y, i));
    }
  }
  if (cnt % 2) a[f] = 1;
  dfs(1);
  int sum = 0;
  for (i = 0; i < m; i++) sum += ans[i];
  printf("%d\n", sum);
  for (i = 0; i < m; i++)
    if (ans[i]) printf("%d ", i + 1);
  return 0;
}
