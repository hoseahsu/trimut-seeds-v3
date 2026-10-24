#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
int n, K;
struct edge {
  int nxt, to;
  edge() {}
  edge(int jzp, int zzz) { nxt = jzp, to = zzz; }
} e[201000 << 1];
int head[201000], ecnt = 1;
inline void addedge(int from, int to) {
  e[++ecnt] = edge(head[from], to);
  head[from] = ecnt;
}
int que[201000], front, rear;
int dep[201000], pre[201000];
inline int BFS1(int s) {
  memset(dep, 0x3f, sizeof(dep));
  front = rear = 0;
  que[++rear] = s;
  dep[s] = 0;
  while (front < rear) {
    int cur = que[++front];
    for (int i = head[cur]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (dep[to] <= dep[cur] + 1) continue;
      dep[to] = dep[cur] + 1;
      que[++rear] = to;
    }
  }
  int mx = 0, mxp = 0;
  for (int i = 1; i <= n; ++i)
    if (dep[i] > mx) mx = dep[i], mxp = i;
  return mxp;
}
int h[201000], htot;
bool inh[201000];
inline void BFS2(int s) {
  memset(dep, 0x3f, sizeof(dep));
  front = rear = 0;
  que[++rear] = s;
  dep[s] = 0;
  while (front < rear) {
    int cur = que[++front];
    for (int i = head[cur]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (dep[to] <= dep[cur] + 1) continue;
      dep[to] = dep[cur] + 1;
      que[++rear] = to;
      pre[to] = cur;
    }
  }
  int mx = 0, mxp = 0;
  for (int i = 1; i <= n; ++i)
    if (dep[i] > mx) mx = dep[i], mxp = i;
  int np = mxp;
  while (np) {
    h[++htot] = np;
    inh[np] = true;
    np = pre[np];
  }
}
int dis[2][201000];
inline void BFS3(int s, int t) {
  memset(dis[t], 0x3f, sizeof(dis[t]));
  front = rear = 0;
  que[++rear] = s;
  dis[t][s] = 0;
  while (front < rear) {
    int cur = que[++front];
    for (int i = head[cur]; i; i = e[i].nxt) {
      int to = e[i].to;
      if (dis[t][to] < 201000) continue;
      dis[t][to] = dis[t][cur] + 1;
      que[++rear] = to;
    }
  }
}
int col[201000];
int depcol[201000];
void dfs_dep(int cur, int faa, int nwd) {
  if (col[cur]) depcol[nwd] = col[cur];
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (to == faa) continue;
    dfs_dep(to, cur, nwd + 1);
  }
}
void dfs_ans(int cur, int faa, int nwd) {
  col[cur] = depcol[nwd];
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (to == faa) continue;
    dfs_ans(to, cur, nwd + 1);
  }
}
inline void Failed() {
  puts("No");
  exit(0);
}
int main() {
  read(n), read(K);
  for (int i = 1; i < n; ++i) {
    int u, v;
    read(u), read(v);
    addedge(u, v), addedge(v, u);
  }
  int S = BFS1(1);
  BFS2(S);
  BFS3(h[1], 0);
  BFS3(h[htot], 1);
  if (K > 2) {
    for (int i = 1; i <= n; ++i) {
      if (!inh[i] && min(dis[0][i], dis[1][i]) >= K - 1) {
        Failed();
      }
    }
  }
  for (int i = 1, c = 1; i <= htot; ++i) {
    col[h[i]] = c;
    if ((++c) > K) c = 1;
  }
  int midl = htot >> 1, midr = midl + 1;
  dfs_dep(h[midl], h[midr], 0);
  dfs_ans(h[midl], h[midr], 0);
  memset(depcol, 0, sizeof(depcol));
  dfs_dep(h[midr], h[midl], 0);
  dfs_ans(h[midr], h[midl], 0);
  puts("Yes");
  for (int i = 1; i <= n; ++i) printf("%d ", col[i]);
  puts("");
  return 0;
}
