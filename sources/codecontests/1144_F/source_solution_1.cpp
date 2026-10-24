#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 7;
int N, M, head[maxN], cnt;
struct Eddge {
  int nex, to, id;
  Eddge(int a = -1, int b = 0, int c = 0) : nex(a), to(b), id(c) {}
} edge[maxN << 1];
inline void addEddge(int u, int v, int id) {
  edge[cnt] = Eddge(head[u], v, id);
  head[u] = cnt++;
}
inline void _add(int u, int v, int id) {
  addEddge(u, v, id);
  addEddge(v, u, id);
}
inline void init() {
  cnt = 0;
  for (int i = 1; i <= N; i++) head[i] = -1;
}
struct node {
  int u, v, op;
  node(int a = 0, int b = 0, int c = -1) : u(a), v(b), op(c) {}
} t[maxN];
struct Point {
  int id, op;
  Point(int a = 0, int b = 0) : id(a), op(b) {}
};
queue<Point> Q;
bool bfs() {
  t[1].op = 1;
  Q.push(Point(t[1].u, 1));
  while (!Q.empty()) {
    Point now = Q.front();
    Q.pop();
    int u = now.id;
    for (int i = head[u], v, id; ~i; i = edge[i].nex) {
      id = edge[i].id;
      if (~t[id].op) {
        if (t[id].u == u) {
          if (t[id].op == 0 && now.op == 1) return false;
          if (t[id].op == 1 && now.op == -1) return false;
        } else {
          if (t[id].op == 0 && now.op == -1) return false;
          if (t[id].op == 1 && now.op == 1) return false;
        }
        continue;
      }
      v = edge[i].to;
      if (now.op == 1) {
        Q.push(Point(v, -1));
        if (t[id].u == u)
          t[id].op = 1;
        else
          t[id].op = 0;
      } else {
        Q.push(Point(v, 1));
        if (t[id].u == u)
          t[id].op = 0;
        else
          t[id].op = 1;
      }
    }
  }
  Q.push(Point(t[1].v, -1));
  while (!Q.empty()) {
    Point now = Q.front();
    Q.pop();
    int u = now.id;
    for (int i = head[u], v, id; ~i; i = edge[i].nex) {
      id = edge[i].id;
      if (~t[id].op) {
        if (t[id].u == u) {
          if (t[id].op == 0 && now.op == 1) return false;
          if (t[id].op == 1 && now.op == -1) return false;
        } else {
          if (t[id].op == 0 && now.op == -1) return false;
          if (t[id].op == 1 && now.op == 1) return false;
        }
        continue;
      }
      v = edge[i].to;
      if (now.op == 1) {
        Q.push(Point(v, -1));
        if (t[id].u == u)
          t[id].op = 1;
        else
          t[id].op = 0;
      } else {
        Q.push(Point(v, 1));
        if (t[id].u == u)
          t[id].op = 0;
        else
          t[id].op = 1;
      }
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  init();
  for (int i = 1, u, v; i <= M; i++) {
    scanf("%d%d", &u, &v);
    t[i] = node(u, v, -1);
    _add(u, v, i);
  }
  if (bfs()) {
    printf("YES\n");
    for (int i = 1; i <= M; i++) printf("%d", t[i].op);
    printf("\n");
  } else
    printf("NO\n");
  return 0;
}
