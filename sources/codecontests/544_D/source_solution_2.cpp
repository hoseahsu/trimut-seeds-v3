#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 2;
const int maxE = 6010;
const int maxV = 3010;
struct EDGE {
  int v, nxt;
  EDGE() {}
  EDGE(int vv, int xx) { v = vv, nxt = xx; }
};
EDGE edg[maxE];
int EH[maxV], etot;
void addEdge(int u, int v) {
  edg[etot] = EDGE(v, EH[u]);
  EH[u] = etot++;
}
void initG() {
  memset(EH, -1, sizeof(EH));
  etot = 0;
}
int n, m;
int dist[maxV][maxV];
void bfs(int s) {
  for (int i = 1; i <= n; i++) dist[s][i] = inf;
  dist[s][s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int p = EH[u]; ~p; p = edg[p].nxt) {
      int v = edg[p].v;
      if (dist[s][v] == inf) {
        dist[s][v] = dist[s][u] + 1;
        que.push(v);
      }
    }
  }
}
int main() {
  int u, v;
  int s1, t1, l1, s2, t2, l2;
  while (~scanf("%d%d", &n, &m)) {
    initG();
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      addEdge(u, v);
      addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    int ans = dist[s1][t1] + dist[s2][t2];
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
      puts("-1");
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int a1 = dist[s1][i] + dist[i][j] + dist[j][t1];
        int a2 = dist[s1][j] + dist[i][j] + dist[i][t1];
        int b1 = dist[s2][i] + dist[i][j] + dist[j][t2];
        int b2 = dist[s2][j] + dist[i][j] + dist[i][t2];
        int a = min(a1, a2);
        int b = min(b1, b2);
        if (a > l1 || b > l2) continue;
        int tmp = a + b - dist[i][j];
        if (tmp < ans) ans = tmp;
      }
    }
    printf("%d\n", m - ans);
  }
  return 0;
}
