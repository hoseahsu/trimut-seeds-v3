#include <bits/stdc++.h>
using namespace std;
int fa[100004];
set<int> v[100004];
vector<int> op;
int maxi, point;
void dfs1(int u, int dep) {
  if (dep > maxi) {
    maxi = dep;
    point = u;
  }
  for (auto it : v[u]) {
    dfs1(it, dep + 1);
  }
}
void dfs2(int u) {
  if (u == 0) return;
  if (v[fa[u]].size() == 1)
    dfs2(fa[u]);
  else {
    v[fa[u]].erase(u);
    int x = *v[fa[u]].begin();
    fa[u] = x;
    v[x].insert(u);
    op.push_back(u);
    dfs2(u);
  }
}
int main() {
  int n;
  cin >> n;
  fa[0] = -1;
  for (int i = 0; i < n - 1; ++i) {
    int p;
    scanf("%d", &p);
    v[p].insert(i + 1);
    fa[i + 1] = p;
  }
  maxi = 1;
  point = 0;
  dfs1(0, 1);
  dfs2(point);
  int u = 0;
  while (v[u].size()) {
    printf("%d ", u);
    u = *v[u].begin();
  }
  printf("%d\n", u);
  printf("%d\n", n - maxi);
  for (int i = op.size() - 1; i >= 0; --i) {
    printf("%d ", op[i]);
  }
}
