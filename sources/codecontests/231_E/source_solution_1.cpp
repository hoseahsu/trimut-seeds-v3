#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 1;
const int mod = 1000 * 1000 * 1000 + 7;
int n, m, k;
vector<int> kak[maxN];
int col[maxN];
struct Node {
  vector<int> v;
  vector<int> a;
  void print() {
    cerr << "Node " << col[v[0]] << endl;
    cerr << "vertex ";
    for (int i = 0; i < v.size(); i++) cerr << v[i] << ' ';
    cerr << endl;
    cerr << "adj ";
    for (int i = 0; i < a.size(); i++) cerr << a[i] << ' ';
    cerr << endl;
  }
};
vector<Node> a;
int color = 1;
int f[maxN];
vector<int> path;
void dec(int v, int par) {
  path.push_back(v);
  f[v] = 1;
  for (int i = 0; i < kak[v].size(); i++) {
    int u = kak[v][i];
    if (!f[u])
      dec(u, v);
    else if (u != par && !col[v]) {
      Node tmp;
      for (int x = path.size() - 1; path[x] != u; x--) {
        tmp.v.push_back(path[x]);
        col[path[x]] = color;
      }
      tmp.v.push_back(u);
      col[u] = color;
      a.push_back(tmp);
      color++;
    }
  }
  path.pop_back();
}
int h[maxN];
int p[maxN][20];
int t[maxN][20];
int comp[maxN];
void dfs(int v, int c) {
  f[v] = 1;
  t[v][0] = a[v].v.size() > 1;
  comp[v] = c;
  for (int i = 1; i < 20; i++) {
    if (p[v][i - 1] == -1) break;
    p[v][i] = p[p[v][i - 1]][i - 1];
    t[v][i] = t[v][i - 1] + t[p[v][i - 1]][i - 1];
  }
  for (int i = 0; i < a[v].a.size(); i++) {
    int u = a[v].a[i];
    if (!f[u]) p[u][0] = v, h[u] = h[v] + 1, dfs(u, c);
  }
}
pair<int, int> par(int x, int t) {
  int res = 0;
  for (int i = 0; i < 20 && x != -1; i++)
    if (t & (1 << i)) res += ::t[x][i], x = p[x][i];
  return pair<int, int>(x, res);
}
pair<int, int> lca(int x, int y) {
  int res = 0;
  if (h[x] > h[y]) swap(x, y);
  pair<int, int> ans = par(y, h[y] - h[x]);
  y = ans.first, res += ans.second;
  if (x == y) return pair<int, int>(x, res);
  for (int i = 20; i >= 0; i--) {
    pair<int, int> t1 = par(x, (1 << i));
    pair<int, int> t2 = par(y, (1 << i));
    if (t1.first == t2.first) continue;
    res += t1.second + t2.second;
    x = t1.first, y = t2.first;
  }
  pair<int, int> t1 = par(x, 1);
  pair<int, int> t2 = par(y, 1);
  int l = t1.first;
  res += t1.second + t2.second;
  return pair<int, int>(l, res);
}
int p2[maxN];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    kak[x].push_back(y);
    kak[y].push_back(x);
  }
  for (int i = 0; i < n; i++)
    if (!f[i]) dec(i, -1);
  for (int i = 0; i < n; i++)
    if (!col[i]) {
      col[i] = color, color++;
      Node tmp;
      tmp.v.push_back(i);
      a.push_back(tmp);
    }
  for (int v = 0; v < n; v++)
    for (int j = 0; j < kak[v].size(); j++) {
      int u = kak[v][j];
      if (col[v] != col[u]) a[col[v] - 1].a.push_back(col[u] - 1);
    }
  n = color - 1;
  memset(f, 0, sizeof f);
  memset(p, -1, sizeof p);
  int COL = 1;
  for (int i = 0; i < n; i++)
    if (!f[i]) dfs(0, COL), COL++;
  p2[0] = 1;
  for (int i = 1; i < maxN; i++) p2[i] = (p2[i - 1] * 2) % mod;
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    x = col[x] - 1, y = col[y] - 1;
    if (comp[x] != comp[y]) {
      cout << 0 << endl;
      continue;
    }
    pair<int, int> ans = lca(x, y);
    int l = ans.first;
    int t = ans.second;
    if (a[l].v.size() > 1) t++;
    cout << p2[t] << endl;
  }
  return 0;
}
