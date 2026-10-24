#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int head[maxn], nxt[maxn], v[maxn], color[maxn];
int vis[maxn], n, m;
vector<int> judge[2];
vector<int> step[2];
int ans[2];
int cnt;
void init() {
  cnt = 0;
  memset(ans, 0, sizeof(0));
  memset(head, -1, sizeof(head));
  memset(nxt, -1, sizeof(nxt));
}
void add_edge(int x, int y, int c) {
  nxt[cnt] = head[x];
  head[x] = cnt;
  v[cnt] = y;
  color[cnt] = c;
  cnt++;
}
int dfs(int x, int ju, int c) {
  vis[x] = ju;
  judge[ju].push_back(x);
  for (int i = head[x]; i != -1; i = nxt[i]) {
    if (vis[v[i]] != -1) {
      if ((vis[x] ^ vis[v[i]]) != (c ^ color[i])) return 0;
      continue;
    }
    int tmp = dfs(v[i], c ^ color[i] ^ vis[x], c);
    if (tmp == 0) return 0;
  }
  return 1;
}
int deal(int color) {
  memset(vis, -1, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (vis[i] == -1) {
      judge[0].clear();
      judge[1].clear();
      int tmp = dfs(i, 0, color);
      if (tmp == 0) return 10000000;
      if (judge[0].size() < judge[1].size()) {
        ans[color] += judge[0].size();
        step[color].insert(step[color].end(), judge[0].begin(), judge[0].end());
      } else {
        ans[color] += judge[1].size();
        step[color].insert(step[color].end(), judge[1].begin(), judge[1].end());
      }
    }
  }
  return ans[color];
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    scanf("%d %d %c", &a, &b, &c);
    if (c == 'R') {
      add_edge(a, b, 1);
      add_edge(b, a, 1);
    } else {
      add_edge(a, b, 0);
      add_edge(b, a, 0);
    }
  }
  int tmp1 = deal(0);
  int tmp2 = deal(1);
  if (tmp1 == 10000000 && tmp2 == 10000000) {
    printf("-1\n");
    return 0;
  }
  if (tmp1 < tmp2) {
    printf("%d\n", ans[0]);
    for (int i = 0; i < step[0].size(); i++) printf("%d ", step[0][i]);
  } else {
    printf("%d\n", ans[1]);
    for (int i = 0; i < step[1].size(); i++) printf("%d ", step[1][i]);
  }
  return 0;
}
