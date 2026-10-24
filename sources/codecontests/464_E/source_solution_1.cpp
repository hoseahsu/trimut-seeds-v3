#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
long long mod = 1000000007;
vector<pair<int, int> > g[100100];
int n, m, s, t;
int pw[1 << 17];
int val[(100100 * 100)], lson[(100100 * 100)], rson[(100100 * 100)], rt[100100],
    tot = 1;
bool flag;
bool vis[100100];
int pre[100100];
void add(int &p, int q, int pos, int l = 0, int r = 131071) {
  p = ++tot;
  if (r - l + 1 == 16) {
    val[p] = val[q] + (1 << (pos - l));
    if (val[p] >= (1 << 16)) {
      flag = 1;
      val[p] -= (1 << 16);
    } else
      flag = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    add(lson[p], lson[q], pos, l, mid);
    if (flag) {
      if (val[rson[q]] == pw[r - mid] - 1)
        rson[p] = 0;
      else {
        add(rson[p], rson[q], mid + 1, mid + 1, r);
        flag = 0;
      }
    } else
      rson[p] = rson[q];
  } else {
    add(rson[p], rson[q], pos, mid + 1, r);
    lson[p] = lson[q];
  }
  val[p] = (1ll * val[rson[p]] * pw[mid - l + 1] + val[lson[p]]) % mod;
}
bool smaller(int p, int q, int l = 0, int r = 131071) {
  if (val[p] == 0) return 1;
  if (val[q] == 0) return 0;
  if (r - l + 1 == 16) return val[p] < val[q];
  int mid = (l + r) >> 1;
  if (val[rson[p]] != val[rson[q]])
    return smaller(rson[p], rson[q], mid + 1, r);
  else
    return smaller(lson[p], lson[q], l, mid);
}
struct cmp {
  bool operator()(pair<int, int> x, pair<int, int> y) {
    return !smaller(x.second, y.second);
  }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    u = read();
    v = read();
    w = read();
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  s = read();
  t = read();
  pw[0] = 1;
  for (int i = 1; i < (1 << 17); i++) pw[i] = pw[i - 1] * 2 % mod;
  rt[s] = tot = 1;
  q.push(make_pair(s, rt[s]));
  while (!q.empty()) {
    int v = q.top().first;
    q.pop();
    if (vis[v]) continue;
    vis[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i].first, w = g[v][i].second;
      if (vis[u]) continue;
      int nrt = 0;
      add(nrt, rt[v], w);
      if (rt[u] == 0 || smaller(nrt, rt[u])) {
        rt[u] = nrt;
        q.push(make_pair(u, rt[u]));
        pre[u] = v;
      }
    }
  }
  if (!rt[t]) {
    puts("-1");
    return 0;
  }
  printf("%d\n", val[rt[t]]);
  vector<int> route;
  for (int i = t; i != s; i = pre[i]) route.push_back(i);
  route.push_back(s);
  printf("%d\n", route.size());
  for (int i = route.size() - 1; i >= 0; i--) printf("%d ", route[i]);
  puts("");
  return 0;
}
