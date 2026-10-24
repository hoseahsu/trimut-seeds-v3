#include <bits/stdc++.h>
using namespace std;
const double g = 10.0, eps = 1e-12;
const int N = 100000 + 10, maxn = 200000 + 10, inf = 0x3f3f3f3f,
          INF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int> > v[N];
int dfn[N], low[N];
int ind, iscut[N], n, m;
vector<int> ans;
struct edge {
  int u, v, id;
};
stack<edge> s;
int bcccnt, bccno[N], ed[N];
vector<int> bcc[N], bb[N];
void tarjan(int u, int f) {
  dfn[u] = low[u] = ++ind;
  int ch = 0;
  for (int i = 0; i < v[u].size(); i++) {
    int x = v[u][i].first;
    if (x == f) continue;
    edge e = {u, x, v[u][i].second};
    if (!dfn[x]) {
      s.push(e);
      ch++;
      tarjan(x, u);
      low[u] = min(low[u], low[x]);
      if (low[x] >= dfn[u]) {
        iscut[u] = 1;
        bcccnt++;
        bcc[bcccnt].clear();
        while (1) {
          edge now = s.top();
          s.pop();
          ed[bcccnt]++;
          bb[bcccnt].push_back(now.id);
          if (bccno[now.u] != bcccnt) {
            bcc[bcccnt].push_back(now.u);
            bccno[now.u] = bcccnt;
          }
          if (bccno[now.v] != bcccnt) {
            bcc[bcccnt].push_back(now.v);
            bccno[now.v] = bcccnt;
          }
          if (now.u == u && now.v == x) break;
        }
      }
    } else if (dfn[x] < dfn[u]) {
      s.push(e);
      low[u] = min(low[u], dfn[x]);
    }
  }
  if (f < 0 && ch == 1) iscut[u] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(make_pair(b, i)), v[b].push_back(make_pair(a, i));
  }
  ind = 0;
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, -1);
  memset(dfn, 0, sizeof dfn);
  for (int i = 1; i <= bcccnt; i++) {
    if (ed[i] == bcc[i].size() && ed[i]) {
      for (int j = 0; j < bb[i].size(); j++) ans.push_back(bb[i][j]);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
