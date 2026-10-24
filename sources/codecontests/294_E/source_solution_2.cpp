#include <bits/stdc++.h>
using namespace std;
long long minn, n, head[5005], cnt, dis[5005], son[5005], ans, from[5005],
    to[5005], sum[5005], value[5005];
struct edge {
  long long from, to, v, next;
} e[2500005];
void add(long long x, long long y, long long z) {
  e[cnt].from = x;
  e[cnt].to = y;
  e[cnt].v = z;
  e[cnt].next = head[x];
  head[x] = cnt++;
}
void dfs(long long u, long long pre) {
  son[u] = 0, dis[u] = 0, sum[u] = 0;
  for (long long i = head[u]; i != -1; i = e[i].next) {
    if (e[i].to != pre) {
      dfs(e[i].to, u);
      sum[u] += sum[e[i].to] + dis[e[i].to] * son[u] + dis[u] * son[e[i].to] +
                son[u] * son[e[i].to] * e[i].v;
      dis[u] += dis[e[i].to] + son[e[i].to] * e[i].v;
      son[u] += son[e[i].to];
    }
  }
  son[u]++;
  sum[u] += dis[u];
}
void dfs2(long long u, long long pre) {
  minn = min(dis[u], minn);
  for (long long i = head[u]; i != -1; i = e[i].next) {
    if (e[i].to != pre) {
      dis[e[i].to] += (dis[u] - dis[e[i].to] - son[e[i].to] * e[i].v +
                       (son[u] - son[e[i].to]) * e[i].v);
      son[e[i].to] = son[u];
      dfs2(e[i].to, u);
    }
  }
}
int main() {
  ans = 999999999999999999;
  cnt = 0;
  memset(head, -1, sizeof(head));
  memset(dis, 0, sizeof(dis));
  long long x, y, z;
  scanf("%d", &n);
  for (long long i = 1; i < n; i++) {
    scanf("%lld%lld%lld", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
    from[i] = x;
    to[i] = y;
    value[i] = z;
  }
  for (long long i = 1; i < n; i++) {
    long long tot = 0;
    minn = 999999999999999999;
    dfs(from[i], to[i]);
    dfs2(from[i], to[i]);
    tot = (sum[from[i]] + (n - son[from[i]]) * minn);
    minn = 999999999999999999;
    dfs(to[i], from[i]);
    dfs2(to[i], from[i]);
    tot += (sum[to[i]] + (n - son[to[i]]) * minn);
    tot += (value[i] * son[from[i]] * son[to[i]]);
    ans = min(ans, tot);
  }
  printf("%lld\n", ans);
}
