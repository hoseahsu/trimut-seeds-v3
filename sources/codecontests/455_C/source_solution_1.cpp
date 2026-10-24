#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 10;
int n, m, q;
vector<int> g[N];
int parent[N], rang[N], diametr[N];
bool used[N];
pair<int, int> mx;
void dfs(int v, int prev = -1, int h = 0) {
  mx = max(mx, make_pair(h, v));
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == prev) continue;
    dfs(to, v, h + 1);
  }
}
int get_tree_diametr(int v) {
  mx = make_pair(-1, -1);
  dfs(v);
  v = mx.second;
  mx = make_pair(-1, -1);
  dfs(v);
  return mx.first;
}
void make_set(int v) {
  parent[v] = v;
  rang[v] = 0;
  diametr[v] = 0;
}
int find_set(int v) {
  if (parent[v] == v) return v;
  return parent[v] = find_set(parent[v]);
}
void union_set1(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rang[a] < rang[b]) swap(a, b);
    parent[b] = a;
    if (rang[a] == rang[b]) rang[a]++;
  }
}
void union_set2(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rang[a] < rang[b]) swap(a, b);
    parent[b] = a;
    if (rang[a] == rang[b]) rang[a]++;
    diametr[a] = max(diametr[a],
                     max(diametr[b], diametr[a] / 2 + diametr[b] / 2 +
                                         diametr[a] % 2 + diametr[b] % 2 + 1));
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) make_set(i);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
    union_set1(x, y);
  }
  for (int i = 0; i < n; ++i) {
    int s = find_set(i);
    if (used[s]) continue;
    used[s] = true;
    diametr[s] = get_tree_diametr(i);
  }
  while (q--) {
    int tp;
    scanf("%d", &tp);
    switch (tp) {
      case 1: {
        int x;
        scanf("%d", &x);
        x--;
        printf("%d\n", diametr[find_set(x)]);
        break;
      }
      case 2: {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        union_set2(x, y);
      }
    }
  }
  return 0;
}
