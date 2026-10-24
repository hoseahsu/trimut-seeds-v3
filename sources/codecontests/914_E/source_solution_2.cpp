#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int hsh[MAX], m[1 << 20];
vector<int> toErase, tmp;
long long ans[MAX];
struct CentroidDecomp {
  vector<vector<int> > g;
  vector<int> sub, done, par;
  int n;
  CentroidDecomp() {}
  CentroidDecomp(int n) : n(n) {
    g = vector<vector<int> >(n);
    sub = vector<int>(n);
    done = vector<int>(n);
    par = vector<int>(n);
  }
  int subtree(int v) {
    sub[v] = 1;
    for (auto u : g[v])
      if (!done[u] && u != par[v]) {
        par[u] = v;
        sub[v] += subtree(u);
      }
    return sub[v];
  }
  int getCentroid(int v) {
    par[v] = -1;
    int sz = subtree(v);
    while (1) {
      pair<int, int> p = {0, -1};
      for (auto u : g[v])
        if (!done[u] && u != par[v]) p = max(p, {sub[u], u});
      if (2 * p.first > sz)
        v = p.second;
      else
        return v;
    }
  }
  void solve(int v) {
    v = getCentroid(v);
    done[v] = 1;
    m[0] = 1;
    ans[v]++;
    for (int u : g[v])
      if (!done[u]) {
        tmp.clear();
        dfs(u, v, hsh[u]);
        for (int mask : tmp) ans[v] += add(v, mask);
        for (int mask : tmp) m[mask]++, toErase.push_back(mask);
      }
    for (int u : g[v])
      if (!done[u]) {
        tmp.clear();
        dfs(u, v, hsh[u]);
        for (int mask : tmp) m[mask]--;
        dfs2(u, v, v, hsh[u]);
        for (int mask : tmp) m[mask]++;
      }
    for (int mask : toErase) m[mask] = 0;
    toErase.clear();
    for (auto u : g[v])
      if (!done[u]) solve(u);
  }
  void dfs(int v, int p, int mask) {
    tmp.push_back(mask);
    for (int u : g[v])
      if (u != p && !done[u]) dfs(u, v, mask ^ hsh[u]);
  }
  long long dfs2(int v, int p, int r, int mask) {
    long long t = add(r, mask);
    for (int u : g[v])
      if (u != p && !done[u]) t += dfs2(u, v, r, mask ^ hsh[u]);
    ans[v] += t;
    return t;
  }
  long long add(int v, int mask) {
    long long t = m[mask ^ hsh[v]];
    for (int i = 0; i < 20; i++) t += m[mask ^ hsh[v] ^ (1 << i)];
    return t;
  }
};
CentroidDecomp cd;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  string s;
  while (cin >> n) {
    cd = CentroidDecomp(n);
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      x--;
      y--;
      cd.g[x].push_back(y);
      cd.g[y].push_back(x);
    }
    cin >> s;
    for (int i = 0; i < n; i++) hsh[i] = 1 << (s[i] - 'a');
    memset(ans, 0, sizeof ans);
    cd.solve(0);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}
