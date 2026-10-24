#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
const int N = 100000 + 10;
struct data {
  int to, next;
} tu[N * 2];
int head[N];
int ip;
int dfn[N], low[N];
int sccno[N];
int step;
int scc_cnt;
void init() {
  ip = 0;
  memset(head, -1, sizeof(head));
}
void add(int u, int v) { tu[ip].to = v, tu[ip].next = head[u], head[u] = ip++; }
vector<int> scc[N];
stack<int> S;
void dfs(int u) {
  dfn[u] = low[u] = ++step;
  S.push(u);
  for (int i = head[u]; i != -1; i = tu[i].next) {
    int v = tu[i].to;
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (!sccno[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    scc_cnt += 1;
    scc[scc_cnt].clear();
    while (1) {
      int x = S.top();
      S.pop();
      if (sccno[x] != scc_cnt) scc[scc_cnt].push_back(x);
      sccno[x] = scc_cnt;
      if (x == u) break;
    }
  }
}
void tarjan(int n) {
  memset(sccno, 0, sizeof(sccno));
  memset(dfn, 0, sizeof(dfn));
  step = scc_cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
}
int u[100000 + 10];
bool ou[100000 + 10];
int main() {
  init();
  int n, m, h;
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &u[i]);
  }
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if ((u[a] + 1) % (h) == u[b]) {
      add(a, b);
    }
    if ((u[b] + 1) % (h) == u[a]) {
      add(b, a);
    }
  }
  tarjan(n);
  memset(ou, true, sizeof(ou));
  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; j != -1; j = tu[j].next) {
      if (sccno[i] != sccno[tu[j].to]) {
        ou[sccno[i]] = false;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= scc_cnt; ++i) {
    if (ou[i]) {
      if (ans == 0 || scc[ans].size() > scc[i].size()) {
        ans = i;
      }
    }
  }
  printf("%d\n", int(scc[ans].size()));
  for (auto i : scc[ans]) {
    printf("%d ", i);
  }
  return 0;
}
