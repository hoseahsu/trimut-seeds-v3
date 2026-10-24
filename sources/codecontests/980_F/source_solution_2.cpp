#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline char Sc() {
  static const int LEN = 100000;
  static char Buf[LEN], *OP = Buf, *ED = Buf;
  if (OP == ED) {
    ED = (OP = Buf) + fread(Buf, 1, LEN, stdin);
    if (OP == ED) return -1;
  }
  return *OP++;
}
template <class T>
inline void Rd(T &x) {
  static char c;
  for (x = 0, c = Sc(); c < 48; c = Sc())
    ;
  for (; c > 47; c = Sc()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int n, m;
int head[500005], tot;
struct Edge {
  int nxt, to;
} G[500005 * 6];
void addedge(int x, int y) {
  G[tot] = (Edge){head[x], y};
  head[x] = tot++;
}
int Q1[500005], st[500005], ed[500005], col[500005];
struct Tarjan {
  int dfn[500005], low[500005], co, vis[500005], Stk[500005], stk, T, T1;
  void Solve(int x, int fa) {
    dfn[x] = low[x] = ++T;
    vis[x] = 1;
    Stk[++stk] = x;
    for (int i = head[x]; i != -1; i = G[i].nxt) {
      int y = G[i].to;
      if (y == fa) continue;
      if (!dfn[y]) {
        Solve(y, x);
        low[x] = min(low[x], low[y]);
      } else if (vis[y])
        low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
      int j;
      co++;
      st[co] = T1 + 1;
      do {
        j = Stk[stk--];
        col[j] = co;
        vis[j] = 0;
        Q1[++T1] = j;
      } while (x != j);
      ed[co] = T1;
    }
  }
  void solve() { Solve(1, 0); }
} Tarjan;
int dp[500005][2], W[500005][2];
struct BFS {
  int Q[500005], vis[500005], fa[500005], dis[500005];
  void solve() {
    int L = 1, R = 1;
    Q[R++] = 1;
    vis[1] = 1;
    while (L < R) {
      int x = Q[L++];
      for (int i = head[x]; i != -1; i = G[i].nxt) {
        int y = G[i].to;
        if (vis[y]) continue;
        fa[y] = x;
        vis[y] = 1;
        Q[R++] = y;
      }
    }
    dis[0] = -1;
    for (int i = n; i > 1; i--) {
      int x = Q[i], v = dis[x] + 1, y = fa[x];
      if (col[x] != col[y]) {
        if (v > dp[y][0]) {
          dp[y][1] = dp[y][0];
          W[y][1] = W[y][0];
          dp[y][0] = v;
          W[y][0] = x;
        } else if (v > dp[y][1]) {
          dp[y][1] = v;
          W[y][1] = x;
        }
      }
      dis[y] = max(dis[y], dis[x] + 1);
    }
  }
} BFS;
int Len[500005], dis[500005];
int Q[500005];
int D(int x) { return dp[Q1[x]][0]; }
int Dis(int x, int y) {
  int c = col[Q1[x]];
  int d1 = abs(x - y);
  int d2 = (ed[c] - st[c] + 1) - d1;
  return min(d1, d2);
}
int Nxt(int x, int len) {
  int c = col[Q1[x]];
  if (x - len >= st[c]) return x - len;
  return ed[c] - (len - (x - st[c] + 1));
}
void Pop(int x, int &L) {
  if (Q[L] == x) L++;
}
void Push(int &L, int &R, int x, int y) {
  while (L <= R && D(Q[R]) + Dis(Q[R], y) <= D(x) + Dis(x, y)) R--;
  Q[++R] = x;
}
void Calc(int c1) {
  int len = ed[c1] - st[c1] + 1;
  int L = 1, R = 0;
  for (int i = ed[c1] - 1; i >= ed[c1] - len / 2; i--) {
    Push(L, R, i, ed[c1]);
  }
  for (int i = ed[c1]; i >= st[c1]; i--) {
    Pop(i, L);
    int x = Q1[i];
    dis[x] = max(dis[x], Dis(i, Q[L]) + D(Q[L]));
    Push(L, R, Nxt(i, len / 2 + 1), i - 1);
  }
}
void f1(int x, int fa) {
  int c1 = col[x];
  if (fa != 0) {
    Len[x] = max(Len[fa], dis[fa]) + 1;
    if (W[fa][0] != x)
      Len[x] = max(Len[x], dp[fa][0] + 1);
    else
      Len[x] = max(Len[x], dp[fa][1] + 1);
  }
  for (int i = st[c1]; i < ed[c1]; i++) Len[Q1[i]] = Len[x] + Dis(i, ed[c1]);
  int len = ed[c1] - st[c1];
  if (len) {
    Calc(c1);
    for (int i = st[c1]; i < st[c1] + len / 2; i++)
      swap(Q1[i], Q1[ed[c1] - i + st[c1] - 1]);
    Calc(c1);
    for (int i = st[c1]; i < st[c1] + len / 2; i++)
      swap(Q1[i], Q1[ed[c1] - i + st[c1] - 1]);
  }
  for (int i = st[c1]; i <= ed[c1]; i++) {
    int x1 = Q1[i];
    for (int j = head[x1]; j != -1; j = G[j].nxt) {
      int y = G[j].to;
      if (col[y] == c1) continue;
      if (col[y] == col[fa]) continue;
      f1(y, x1);
    }
  }
}
int main() {
  memset(head, -1, sizeof head);
  Rd(n);
  Rd(m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    Rd(x);
    Rd(y);
    addedge(x, y);
    addedge(y, x);
  }
  Tarjan.solve();
  BFS.solve();
  f1(1, 0);
  for (int i = 1; i <= n; i++)
    printf("%d ", max(max(dis[i], Len[i]), dp[i][0]));
  return 0;
}
