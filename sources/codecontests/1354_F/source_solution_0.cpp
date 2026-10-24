#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long to, dis, next, cost;
} edge[24050];
long long num = -1;
bool vis[10010];
long long mincost;
long long pre[10010], head[10010], cost[10010], last[10010], flow[10010], n, k,
    a[110], b[110], s, t, maxflow;
long long to[110];
void add(long long f, long long t, long long dis, long long cost) {
  edge[++num].to = t;
  edge[num].dis = dis;
  edge[num].next = head[f];
  edge[num].cost = cost;
  head[f] = num;
  edge[++num].to = f;
  edge[num].dis = 0;
  edge[num].cost = -cost;
  edge[num].next = head[t];
  head[t] = num;
}
queue<long long> q;
bool spfa(long long s, long long t) {
  memset(cost, 0x3f3f3f3f, sizeof cost);
  memset(flow, 0x3f3f3f3f, sizeof flow);
  memset(vis, 0, sizeof vis);
  q.push(s);
  vis[s] = 1;
  cost[s] = 0;
  pre[t] = -1;
  while (!q.empty()) {
    long long nowp = q.front();
    q.pop();
    vis[nowp] = 0;
    for (long long i = head[nowp]; i != -1; i = edge[i].next) {
      if (edge[i].dis > 0 && cost[edge[i].to] > cost[nowp] + edge[i].cost) {
        cost[edge[i].to] = cost[nowp] + edge[i].cost;
        pre[edge[i].to] = nowp;
        last[edge[i].to] = i;
        flow[edge[i].to] = min(flow[nowp], edge[i].dis);
        if (!vis[edge[i].to]) {
          vis[edge[i].to] = 1;
          q.push(edge[i].to);
        }
      }
    }
  }
  return pre[t] != -1;
}
void MCMF(long long s, long long t) {
  while (spfa(s, t)) {
    long long now = t;
    maxflow += flow[t];
    mincost += flow[t] * cost[t];
    while (now != s) {
      edge[last[now]].dis -= flow[t];
      edge[last[now] ^ 1].dis += flow[t];
      now = pre[now];
    }
  }
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    num = -1;
    memset(to, -1, sizeof to);
    memset(head, -1, sizeof head);
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> a[i] >> b[i];
    maxflow = mincost = 0;
    s = 0;
    t = 2 * n + 1;
    for (long long i = 1; i <= n; i++) add(s, i, 1, 0), add(i + n, t, 1, 0);
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        long long nc = 0;
        if (j <= k - 1)
          nc = a[i] + b[i] * (j - 1ll);
        else if (j != n)
          nc = b[i] * (k - 1ll);
        else
          nc = a[i] + b[i] * (k - 1ll);
        nc = 0x3f3f3f3f - nc;
        add(i, j + n, 1, nc);
      }
    }
    MCMF(s, t);
    long long nowi = -1;
    for (long long i = n * 4; i <= num; i += 2) {
      nowi++;
      if (edge[i].dis == 0) to[1 + nowi % n] = 1 + nowi / n;
    }
    cout << 2 * n - k << endl;
    for (long long i = 1; i <= k - 1; i++) cout << to[i] << " ";
    for (long long i = k; i < n; i++) cout << to[i] << " " << -to[i] << " ";
    cout << to[n];
    cout << endl;
  }
  return 0;
}
