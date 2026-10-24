#include <bits/stdc++.h>
using namespace std;
struct edge {
  int pre, next;
} pool[200005];
int N, Q;
int tot = 0;
double ans = 0;
int f[100005];
int head[100005];
double p[100005];
double sum[100005];
inline int read_int() {
  register int ret = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = (ret << 1) + (ret << 3) + int(c - 48);
    c = getchar();
  }
  return ret * f;
}
inline void add_edge(int u, int v) {
  pool[++tot].pre = head[u];
  pool[tot].next = v;
  head[u] = tot;
  pool[++tot].pre = head[v];
  pool[tot].next = u;
  head[v] = tot;
}
inline void init() {
  N = read_int();
  p[0] = 1.0;
  for (register int i = 1; i <= N; i++) scanf("%lf", &p[i]);
  for (register int i = 1; i < N; i++) {
    int u = read_int() + 1, v = read_int() + 1;
    add_edge(u, v);
  }
  Q = read_int();
}
void dfs(int u, int father) {
  f[u] = father;
  ans += p[father] * (1.0 - p[u]);
  for (register int i = head[u]; i; i = pool[i].pre) {
    int v = pool[i].next;
    if (v == father) continue;
    dfs(v, u);
    sum[u] += 1.0 - p[v];
  }
}
inline void calc() {
  while (Q--) {
    int u = read_int() + 1;
    double pro;
    scanf("%lf", &pro);
    ans -= p[f[u]] * (1.0 - p[u]);
    ans -= p[u] * sum[u];
    sum[f[u]] -= 1.0 - p[u];
    p[u] = pro;
    ans += p[f[u]] * (1.0 - p[u]);
    ans += p[u] * sum[u];
    sum[f[u]] += (1.0 - p[u]);
    printf("%.5lf\n", ans);
  }
}
int main() {
  init();
  dfs(1, 0);
  calc();
  return 0;
}
