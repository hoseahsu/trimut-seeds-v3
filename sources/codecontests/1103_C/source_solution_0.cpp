#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 100005;
vector<int> a[maxn];
int n, m, k, lim;
int head[maxn], Next[maxn * 2], to[maxn * 2], tot = 0;
int d[maxn], fa[maxn], size[maxn];
bool vis[maxn];
void add(int x, int y) {
  to[++tot] = y;
  Next[tot] = head[x];
  head[x] = tot;
}
void dfs_tree(int x, int f) {
  size[x] = 1;
  for (int i = head[x]; i; i = Next[i]) {
    int y = to[i];
    if (y == f || vis[y]) continue;
    d[y] = d[x] + 1;
    fa[y] = x;
    vis[y] = 1;
    dfs_tree(y, x);
    size[x] += size[y];
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  lim = ceil((double)n * 1.0 / k);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  vis[1] = 1;
  d[1] = 1;
  dfs_tree(1, 0);
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] >= lim) {
      puts("PATH");
      pos = i;
      printf("%d\n", d[i]);
      while (pos) {
        printf("%d ", pos);
        pos = fa[pos];
      }
      printf("\n");
      return 0;
    }
  }
  int cnt = 0;
  puts("CYCLES");
  for (int i = 1; i <= n; i++) {
    if (size[i] == 1) {
      int p1 = 0, p2 = 0;
      for (int j = head[i]; j; j = Next[j]) {
        int y = to[j];
        if (y == fa[i]) continue;
        if (!p1)
          p1 = y;
        else {
          if (!p2) {
            p2 = y;
            break;
          }
        }
      }
      if (d[p1] < d[p2]) swap(p1, p2);
      int c1 = d[i] - d[p1] + 1, c2 = d[i] - d[p2] + 1, c3 = d[p1] - d[p2] + 2;
      if (c1 > 3 && c1 % 3 != 0) {
        cnt++;
        pos = i;
        while (pos != fa[p1]) {
          a[cnt].push_back(pos);
          pos = fa[pos];
        }
      } else if (c2 > 3 && c2 % 3 != 0) {
        cnt++;
        pos = i;
        while (pos != fa[p2]) {
          a[cnt].push_back(pos);
          pos = fa[pos];
        }
      } else if (c3 > 3 && c3 % 3 != 0) {
        cnt++;
        pos = p1;
        while (pos != fa[p2]) {
          a[cnt].push_back(pos);
          pos = fa[pos];
        }
        a[cnt].push_back(i);
      }
    }
    if (cnt == k) break;
  }
  for (int i = 1; i <= cnt; i++) {
    printf("%d\n", a[i].size());
    for (int j = 0; j < a[i].size(); j++) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
