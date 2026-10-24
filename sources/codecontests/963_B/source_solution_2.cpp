#include <bits/stdc++.h>
std::vector<int> node[262144];
int w[262144];
std::vector<int> sta;
void dfs1(int u) {
  w[u] = 1;
  for (auto v : node[u]) dfs1(v), w[u] += w[v];
}
void dfs2(int u) {
  for (auto v : node[u])
    if (!(w[v] & 1)) dfs2(v);
  printf("%d\n", u);
  for (auto v : node[u])
    if (w[v] & 1) dfs2(v);
}
int main() {
  int n, k, p;
  scanf("%d", &n);
  if (!(n & 1)) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p);
    if (p)
      node[p].push_back(i);
    else
      k = i;
  }
  dfs1(k);
  dfs2(k);
  return 0;
}
