#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct node {
  int from, to, cost;
} edge[maxn];
bool flag[maxn];
int fa[maxn];
bool cmp(node a, node b) { return a.cost > b.cost; }
int find(int num) { return fa[num] == num ? num : fa[num] = find(fa[num]); }
int main() {
  int n, m, i, res;
  scanf("%d%d", &n, &m);
  for (i = res = 0; i < m; i++)
    scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].cost);
  sort(edge, edge + m, cmp);
  for (i = 0; i <= n; i++) fa[i] = i;
  for (i = 0; i < m; i++) {
    int sa = find(edge[i].from), sb = find(edge[i].to);
    if (sa != sb && (!flag[sa] || !flag[sb])) {
      flag[sa] = flag[sa] || flag[sb];
      fa[sb] = sa;
      res += edge[i].cost;
    } else if (sa == sb && !flag[sa]) {
      flag[sa] = true;
      res += edge[i].cost;
    }
  }
  printf("%d\n", res);
  return 0;
}
