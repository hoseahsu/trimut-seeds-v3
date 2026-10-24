#include <bits/stdc++.h>
using namespace std;
int c[2010], a[2010];
vector<int> children[2010];
bool possible;
list<int> dfs(int u) {
  list<int> l;
  for (int i = 0; i < children[u].size() and possible; i++) {
    int v = children[u][i];
    list<int> nl = dfs(v);
    l.insert(l.end(), nl.begin(), nl.end());
  }
  if (!possible) return list<int>();
  list<int>::iterator it = l.begin();
  for (int i = 0; i < c[u]; i++) {
    if (it == l.end()) {
      possible = false;
      return list<int>();
    }
    it++;
  }
  l.insert(it, u);
  return l;
}
int main() {
  int n;
  while (scanf("%d", &n) > 0) {
    int root;
    for (int i = 1; i <= n; i++) {
      int p;
      scanf("%d%d", &p, &c[i]);
      if (p)
        children[p].push_back(i);
      else
        root = i;
    }
    possible = true;
    list<int> l = dfs(root);
    if (possible) {
      printf("YES\n");
      int x = 1;
      for (auto u : l) {
        a[u] = x++;
      }
      for (int i = 1; i < n; i++) {
        printf("%d ", a[i]);
      }
      printf("%d\n", a[n]);
    } else {
      printf("NO\n");
    }
    for (int i = 1; i <= n; i++) {
      children[i].clear();
    }
  }
}
