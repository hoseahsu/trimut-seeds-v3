#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
struct P {
  int u, v, c, val, id;
} e[50010];
vector<int> v[50010];
bool cmp(P a, P b) { return a.val < b.val; }
int a[50010], top;
bool cmpx(int x, int y) { return e[x].c < e[y].c; }
int up[50010], down[50010], cnt;
int head[50010 * 10], nxt[50010 * 22], to[50010 * 22], tot;
void add(int u, int v) {
  tot++;
  nxt[tot] = head[u];
  head[u] = tot;
  to[tot] = v;
}
stack<int> s;
int scc[50010 * 10], dfn[50010 * 10], low[50010 * 10], cnt_scc, cntx,
    in[50010 * 10];
void tarjan(int u) {
  dfn[u] = low[u] = ++cntx;
  s.push(u);
  in[u] = 1;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    cnt_scc++;
    int tmp = 0;
    while (tmp != u) {
      tmp = s.top();
      s.pop();
      scc[tmp] = cnt_scc;
      in[tmp] = 0;
    }
  }
}
bool check(int mid) {
  tot = 0;
  memset(head, 0, sizeof(head));
  for (int i = mid + 1; i <= m; i++) add(i, i + m);
  cnt = 2 * m;
  for (int i = 1; i <= n; i++) {
    top = 0;
    for (int j = 0; j < v[i].size(); j++) a[++top] = v[i][j];
    sort(a + 1, a + top + 1, cmpx);
    for (int j = 1; j <= top; j++) up[j] = ++cnt, down[j] = ++cnt;
    for (int j = 1; j <= top; j++) {
      add(down[j], a[j] + m);
      add(a[j], up[j]);
      if (j != top) {
        add(up[j], up[j + 1]);
        add(down[j + 1], down[j]);
        add(up[j], a[j + 1] + m);
        add(a[j + 1], down[j]);
      }
    }
    for (int j = 1; j <= top; j++) up[j] = ++cnt, down[j] = ++cnt;
    for (int j = 1; j <= top; j++) {
      int R = j;
      while (R < top && e[a[R + 1]].c == e[a[j]].c) R++;
      for (int k = j; k <= R; k++) {
        add(up[k], a[k]);
        add(a[k] + m, down[k]);
        if (k != R) {
          add(down[k], a[k + 1]);
          add(a[k + 1] + m, up[k]);
          add(up[k + 1], up[k]);
          add(down[k], down[k + 1]);
        }
      }
      j = R;
    }
  }
  for (int i = 1; i <= cnt; i++) dfn[i] = 0;
  cntx = cnt_scc = 0;
  for (int i = 1; i <= cnt; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= m; i++)
    if (scc[i] == scc[i + m]) return false;
  return true;
}
int ansx[50010];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++)
    e[i].u = read(), e[i].v = read(), e[i].c = read(), e[i].val = read(),
    e[i].id = i;
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= m; i++) v[e[i].u].push_back(i), v[e[i].v].push_back(i);
  int l = 0, r = m, pos = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      pos = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (pos == -1) {
    puts("No");
    return 0;
  }
  puts("Yes");
  int ans = 0;
  check(pos);
  for (int i = 1; i <= m; i++) {
    if (scc[i] < scc[i + m]) ansx[++ans] = e[i].id;
  }
  printf("%d %d\n", e[pos].val, ans);
  for (int i = 1; i <= ans; i++) printf("%d ", ansx[i]);
  puts("");
  return 0;
}
