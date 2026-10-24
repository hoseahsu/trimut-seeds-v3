#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int first[maxn], nxt[maxn << 1], vv[maxn << 1];
bool vis[maxn];
int mark[maxn];
int edge[maxn];
void dfs(int n, int fa) {
  vis[n] = true;
  for (int e = first[n]; e; e = nxt[e])
    if (vv[e] != fa && !vis[vv[e]]) dfs(vv[e], n);
  int top = 0;
  for (int e = first[n]; e; e = nxt[e])
    if (vv[e] != fa && mark[vv[e]] != 1) edge[top++] = vv[e];
  if (top & 1)
    edge[top++] = fa, mark[n] = 1;
  else
    mark[n] = 2;
  for (int i = 0; i < top; i += 2) {
    printf("%d %d %d\n", edge[i], n, edge[i + 1]);
    if (mark[edge[i]] == 2) mark[edge[i]] = 1;
    if (mark[edge[i + 1]] == 2) mark[edge[i + 1]] = 1;
  }
}
int main() {
  int e = 1;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    nxt[e] = first[u], vv[e] = v, first[u] = e++;
    nxt[e] = first[v], vv[e] = u, first[v] = e++;
  }
  if (m & 1)
    puts("No solution");
  else
    dfs(1, 0);
}
