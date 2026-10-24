#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, INF = 0x7fffffff;
int n, cnt;
int a[maxn << 1], head[maxn << 1], vis[maxn << 1], pre[maxn << 1],
    bz[maxn << 1], d[maxn << 1], bj[maxn << 1];
int s, t;
vector<int> f;
struct node {
  int u, v, next;
} Node[maxn << 2];
void add(int u, int v) {
  Node[cnt].u = u;
  Node[cnt].v = v;
  Node[cnt].next = head[u];
  head[u] = cnt++;
}
void dfs1(int u, int fa) {
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = Node[i].next) {
    node e = Node[i];
    if (!vis[e.v]) {
      pre[e.v] = u;
      dfs1(e.v, u);
    } else {
      s = e.v;
      t = u;
      return;
    }
  }
}
int minn = INF;
long long res = 0;
void dfs2(int u) {
  minn = min(minn, a[u]);
  if (u == s) {
    res += (long long)minn;
    return;
  } else if (u == 0)
    return;
  bz[u] = 1;
  dfs2(pre[u]);
}
int main() {
  memset(head, -1, sizeof(head));
  cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int u;
  for (int i = 1; i <= n; i++) {
    cin >> u;
    add(i, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      minn = INF;
      d[i] = 0;
      dfs1(i, -1);
      dfs2(t);
    }
  }
  cout << res << endl;
  return 0;
}
