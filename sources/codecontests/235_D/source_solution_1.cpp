#include <bits/stdc++.h>
using namespace std;
int vi[3005], cir;
int ori[3005][3005];
int sccl[3005][3005];
vector<int> s[3005], scc[3005], g[3005];
stack<int> sta;
int dfs_cnt = 0, pre[3005] = {0}, sccno[3005] = {0}, scc_cnt = 0;
int dfs(int u, int fa) {
  int lowu, lowv, i;
  lowu = pre[u] = ++dfs_cnt;
  sta.push(u);
  for (i = 0; i < s[u].size(); i++) {
    int v = s[u][i];
    if (v == fa) continue;
    if (pre[v] == 0) {
      lowv = dfs(v, u);
      lowu = min(lowu, lowv);
    } else if (pre[v] < pre[u] && sccno[v] == 0) {
      lowu = min(lowu, pre[v]);
    }
  }
  if (lowu == pre[u]) {
    ++scc_cnt;
    while (sta.size()) {
      int x = sta.top();
      sta.pop();
      sccno[x] = scc_cnt;
      scc[scc_cnt].push_back(x);
      if (x == u) break;
    }
    cir = max(cir, (int)scc[scc_cnt].size());
  }
  return lowu;
}
void dfs1(int u, int add, int st) {
  ori[st][u] = add;
  for (int i = 0; i < s[u].size(); i++) {
    int v = s[u][i];
    if (vi[v] == st) continue;
    vi[v] = st;
    dfs1(v, add + 1, st);
  }
}
void dfs2(int u, int add, int st) {
  sccl[st][u] = add;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (vi[v] == st) continue;
    vi[v] = st;
    dfs2(v, add + 1, st);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      int x = sccno[i];
      int y = sccno[s[i][j]];
      if (x == y) continue;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  memset(vi, -1, sizeof(vi));
  for (int i = 0; i < n; i++) {
    vi[i] = i;
    dfs1(i, 0, i);
  }
  memset(vi, -1, sizeof(vi));
  for (int i = 1; i <= scc_cnt; i++) {
    vi[i] = i;
    dfs2(i, 0, i);
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        ans += 1;
        continue;
      }
      int x = sccl[sccno[i]][sccno[j]];
      int y = ori[i][j] - x;
      int z = cir - y;
      if (y && z)
        ans += 1.0 / (x + y + 1) + 1.0 / (x + z + 1) - 1.0 / (x + y + z);
      else
        ans += 1.0 / (x + 1);
    }
  }
  printf("%.12f\n", ans);
}
