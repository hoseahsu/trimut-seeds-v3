#include <bits/stdc++.h>
using namespace std;
int com[100010], x[100010], y[100010], z[100010], visited[100010],
    config[100010];
vector<int> adj[100010];
int cc = 0;
int flag = 0;
void dfs(int v) {
  visited[v] = 1;
  com[v] = cc;
  for (int i = 0; i < adj[v].size(); i++) {
    if (!visited[adj[v][i]]) {
      dfs(adj[v][i]);
    }
  }
}
void dfs1(int v) {
  visited[v] = 1;
  for (int i = 0; i < adj[v].size(); i++) {
    int node = adj[v][i];
    if (!visited[node]) {
      config[node] = 1 - config[v];
      dfs1(node);
    } else {
      if (config[node] == config[v]) flag = 1;
    }
  }
}
long long modpow(long long a, long long b, long long c) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2) x = (x * y) % c;
    y = (y * y) % c;
    b /= 2;
  }
  return x % c;
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
    scanf("%d", &z[i]);
    if (z[i] == 1) {
      adj[x[i]].push_back(y[i]);
      adj[y[i]].push_back(x[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cc++;
      dfs(i);
    }
  }
  flag = 0;
  for (int i = 0; i < m; i++) {
    if (z[i] == 0) {
      if (com[x[i]] == com[y[i]]) {
        flag = 1;
        break;
      }
    }
  }
  if (flag) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i <= n; i++) visited[i] = 0;
  for (int i = 0; i < m; i++) {
    if (z[i] == 0) {
      int a = com[x[i]];
      int b = com[y[i]];
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  long long comp = 0;
  flag = 0;
  for (int i = 1; i <= cc; i++) {
    if (!visited[i]) {
      comp++;
      config[i] = 0;
      dfs1(i);
    }
  }
  if (flag)
    cout << "0" << endl;
  else {
    long long ans = modpow(1LL * 2, comp - 1, 1000000007);
    printf("%lld\n", ans);
  }
}
