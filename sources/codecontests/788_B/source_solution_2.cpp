#include <bits/stdc++.h>
int n, m, cnt = 0, fa[1000010];
long long ans = 0, du[1000010];
struct node {
  int x, y;
} mp[1000010];
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    mp[i].x = x;
    mp[i].y = y;
    if (x != y) {
      du[x]++, du[y]++;
      int fx = find(x), fy = find(y);
      if (fx != fy) fa[fx] = fy;
    } else
      ++cnt;
  }
  ans = (long long)cnt * (cnt - 1);
  int k = find(mp[1].x);
  for (int i = 1; i <= m; i++)
    if (find(mp[i].x) != find(mp[i].y) || find(mp[i].x) != k) {
      printf("0\n");
      return 0;
    }
  for (int i = 1; i <= n; i++)
    if (du[i]) ans += (long long)du[i] * (du[i] - 1);
  ans >>= 1;
  ans += (long long)cnt * (m - cnt);
  printf("%I64d\n", ans);
  return 0;
}
