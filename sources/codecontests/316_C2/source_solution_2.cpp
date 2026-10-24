#include <bits/stdc++.h>
using namespace std;
int ans[1005];
struct MincostFlow {
  int n, src, snk;
  struct edge {
    int c;
    int f;
    int u;
    int v;
    int w;
    edge(int u = 0, int v = 0, int c = 0, int f = 0, int w = 0)
        : u(u), v(v), c(c), f(f), w(w) {}
  };
  vector<vector<int> > G;
  vector<edge> e;
  MincostFlow(int n = 0, int src = 0, int snk = 0) : n(n), src(src), snk(snk) {
    e.clear();
    G.assign(n + 1, vector<int>());
  }
  void AddEdge(int u, int v, int c, int w, int id = 0) {
    ans[id] = e.size();
    G[u].push_back(e.size());
    e.push_back(edge(u, v, c, 0, w));
    G[v].push_back(e.size());
    e.push_back(edge(v, u, 0, 0, -w));
  }
  vector<int> d, head, par;
  vector<bool> inQueue;
  bool mnm(int &a, int b) {
    if (a > b)
      a = b;
    else
      return 0;
    return 1;
  }
  bool ford_bellman() {
    queue<int> q;
    q.push(src);
    d.assign(n + 1, 1e9 + 7);
    par.assign(n + 1, 0);
    head.assign(n + 1, 0);
    inQueue.assign(n + 1, 0);
    d[src] = 0;
    inQueue[src] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inQueue[u] = 0;
      for (int id : G[u])
        if (e[id].c > e[id].f && mnm(d[e[id].v], d[u] + e[id].w)) {
          if (!inQueue[e[id].v]) inQueue[e[id].v] = 1, q.push(e[id].v);
          par[e[id].v] = u;
          head[e[id].v] = id;
        }
    }
    return d[snk] != 1e9 + 7;
  }
  long long minCost;
  void mxm() {
    int delta = 1e9 + 7;
    for (int u = snk; u != src; u = par[u]) {
      int id = head[u];
      delta = min(delta, e[id].c - e[id].f);
    }
    for (int u = snk; u != src; u = par[u]) {
      int id = head[u];
      e[id].f += delta;
      e[id ^ 1].f -= delta;
      minCost += 1ll * delta * e[id].w;
    }
  }
  long long MinCost() {
    minCost = 0;
    while (ford_bellman()) mxm();
    return minCost;
  }
};
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int a[n][m];
  int s = n * m, t = n * m + 1;
  MincostFlow mcf(t + 1, s, t);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) & 1) {
        mcf.AddEdge(i * m + j, t, 1, 0);
        continue;
      }
      mcf.AddEdge(s, i * m + j, 1, 0);
      if (i) {
        mcf.AddEdge(i * m + j, (i - 1) * m + j, 1, a[i][j] != a[i - 1][j]);
      }
      if (j) {
        mcf.AddEdge(i * m + j, i * m + j - 1, 1, a[i][j] != a[i][j - 1]);
      }
      if (i < n - 1) {
        mcf.AddEdge(i * m + j, (i + 1) * m + j, 1, a[i][j] != a[i + 1][j]);
      }
      if (j < m - 1) {
        mcf.AddEdge(i * m + j, i * m + j + 1, 1, a[i][j] != a[i][j + 1]);
      }
    }
  }
  cout << mcf.MinCost() << endl;
  return 0;
}
