#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const long long MOD = 1e9 + 7;
int n, m, p[2][N], clr[N], vis[N];
vector<vector<int> > g;
vector<pair<int, int> > e;
vector<int> node;
int find(int i, int u) { return u == p[i][u] ? u : p[i][u] = find(i, p[i][u]); }
long long pow(long long b, long long p) {
  if (p == 0) return 1;
  if (p == 1) return b;
  if (p & 1) return (b * pow(b, p - 1ll) % MOD) % MOD;
  long long r = pow(b, p / 2) % MOD;
  return (r * r) % MOD;
}
bool is_bipartit(int u, int c) {
  clr[u] = c;
  bool f = 1;
  for (int i = 0; i < g[u].size(); i++) {
    if (clr[g[u][i]] == -1)
      f &= is_bipartit(g[u][i], c ^ 1);
    else if (clr[g[u][i]] == c) {
      f = 0;
      return f;
    }
  }
  return f;
}
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int i = 0; i < g[u].size(); i++) dfs(g[u][i]);
}
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) p[0][i] = i;
  g.resize(n);
  int a, b, c;
  while (m--) {
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    if (c == 1) {
      a = find(0, a), b = find(0, b);
      if (a != b) p[0][a] = b;
    } else
      e.push_back(make_pair(a, b));
  }
  for (int i = 0; i < n; i++)
    if (i == p[0][i]) {
      node.push_back(i);
      p[1][i] = i;
    }
  for (int i = 0; i < e.size(); i++) {
    a = find(0, e[i].first), b = find(0, e[i].second);
    if (a == b) {
      puts("0");
      return 0;
    }
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(clr, -1, sizeof(clr));
  bool f = 1;
  for (int i = 0; i < node.size(); i++)
    if (clr[node[i]] == -1) f &= is_bipartit(node[i], 0);
  int comp = 0;
  for (int i = 0; i < node.size(); i++) {
    if (!vis[node[i]]) {
      dfs(node[i]);
      comp++;
    }
  }
  if (f)
    printf("%lld\n", pow(2ll, (long long)comp - 1ll));
  else
    puts("0");
  return 0;
}
