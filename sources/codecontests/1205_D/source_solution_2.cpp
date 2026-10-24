#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int p = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -p;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
  x = x * p;
}
const int maxn = 1005;
int siz[maxn], n, root, son[maxn], head[maxn], cnt, tot, hh[maxn], a, b, now;
struct node {
  int from, to, v;
} ans[maxn];
struct edge {
  int to, next;
} e[maxn << 1];
vector<int> vec;
void add(int x, int y) {
  e[cnt].to = y;
  e[cnt].next = head[x];
  head[x] = cnt++;
}
void findroot(int u, int pre) {
  siz[u] = 1;
  son[u] = 0;
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].to == pre) continue;
    findroot(e[i].to, u);
    siz[u] += siz[e[i].to];
    son[u] = max(son[u], siz[e[i].to]);
  }
  son[u] = max(son[u], n - siz[u]);
  if (son[root] > son[u]) root = u;
}
bool cmp(const int &a, const int &b) { return siz[a] > siz[b]; }
void dfs(int u, int pre) {
  siz[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].to == pre) continue;
    dfs(e[i].to, u);
    siz[u] += siz[e[i].to];
    if (u == root) vec.push_back(e[i].to);
  }
}
void dfs1(int u, int pre, int g) {
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].to == pre) continue;
    now++;
    ans[++tot] = (node){u, e[i].to, now - g};
    dfs1(e[i].to, u, now);
  }
}
void dfs2(int u, int pre, int g) {
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].to == pre) continue;
    now += a;
    ans[++tot] = (node){u, e[i].to, now - g};
    dfs2(e[i].to, u, now);
  }
}
int main() {
  cnt = 1;
  tot = -0;
  a = 0;
  b = 0;
  son[0] = 99999999;
  root = 0;
  read(n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    read(x);
    read(y);
    add(x, y);
    add(y, x);
  }
  findroot(1, 0);
  dfs(root, 0);
  sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < vec.size(); ++i) {
    int to = vec[i];
    if (a <= b)
      hh[to] = 0, a += siz[to];
    else
      hh[to] = 1, b += siz[to];
  }
  now = 0;
  for (int i = head[root]; i; i = e[i].next) {
    if (hh[e[i].to]) continue;
    ans[++tot] = (node){root, e[i].to, now + 1};
    now++;
    dfs1(e[i].to, root, now);
  }
  now = a;
  for (int i = head[root]; i; i = e[i].next) {
    if (!hh[e[i].to]) continue;
    ans[++tot] = (node){root, e[i].to, now};
    now += a;
    dfs2(e[i].to, root, now);
  }
  for (int i = 1; i < n; ++i) {
    printf("%d %d %d\n", ans[i].from, ans[i].to, ans[i].v);
  }
}
