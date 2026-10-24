#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int fa[201000];
bool done[201000];
struct node {
  int x, y, w;
} way[201000];
inline int read() {
  int x = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
inline bool cmp(node a, node b) { return a.w > b.w; }
void pre() {
  m = read(), n = read();
  for (register int i = 1; i <= n; i++)
    way[i].x = read(), way[i].y = read(), way[i].w = read();
  for (register int i = 1; i <= m; i++) fa[i] = i;
  sort(way + 1, way + n + 1, cmp);
}
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
void work() {
  for (register int i = 1; i <= n; i++) {
    int fx = find(way[i].x), fy = find(way[i].y);
    if (fx == fy && done[fx])
      continue;
    else if (fx != fy && done[fx] && done[fy])
      continue;
    if (fx == fy)
      done[fx] = true;
    else if (done[fx] || done[fy])
      done[fx] = done[fy] = true;
    (fx < fy) ? fa[fy] = fx : fa[fx] = fy;
    ans += way[i].w;
  }
  printf("%d\n", ans);
}
int main() {
  pre();
  work();
  return 0;
}
