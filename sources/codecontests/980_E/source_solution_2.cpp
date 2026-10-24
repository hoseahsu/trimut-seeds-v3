#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int p[N], s[N], d[N], sz[N], pos[N], used[N];
vector<int> order;
vector<int> nei[N];
int query(int x) {
  int ans = 0;
  while (x > 0) {
    ans += s[x];
    x -= x & -x;
  }
  return ans;
}
void modify(int x, int v) {
  while (x <= n) {
    s[x] += v;
    x += x & -x;
  }
}
void dfs(int x) {
  order.push_back(x);
  pos[x] = order.size() - 1;
  for (int i = 0; i < nei[x].size(); i++) {
    int to = nei[x][i];
    if (to != p[x]) {
      p[to] = x;
      d[to] = d[x] + 1;
      dfs(to);
      sz[x] += sz[to];
    }
  }
  sz[x]++;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    nei[x].push_back(y);
    nei[y].push_back(x);
  }
  d[n] = 1;
  dfs(n);
  int pre = 0;
  for (int i = 0; i < order.size(); i++) {
    int now = d[order[i]];
    modify(i + 1, now - pre);
    pre = now;
  }
  int cur = n;
  m = n - m;
  while (m) {
    while (query(pos[cur] + 1) > m) {
      cur--;
    }
    int ncur = cur;
    while (!used[ncur] && ncur) {
      used[ncur] = 1;
      modify(pos[ncur] + 1, -1);
      modify(pos[ncur] + sz[ncur] + 1, 1);
      ncur = p[ncur];
      m--;
    }
    cur--;
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) printf("%d ", i);
  puts("");
  return 0;
}
