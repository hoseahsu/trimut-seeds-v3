#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  char c = getchar();
  for (; c < 48; c = getchar())
    ;
  for (; c > 47; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
inline void Min(int &x, int y) {
  if (x > y) x = y;
}
inline void Max(int &x, int y) {
  if (x < y) x = y;
}
int n;
struct Tree {
  int son[1000005][2], fa[1000005], sz[1000005], val[1000005], tot, rt,
      laz[1000005];
  inline bool dir(int x) { return son[fa[x]][1] == x; }
  inline void up(int p) {
    if (p) {
      down(p);
      sz[p] = 1;
      if ((son[p][0])) {
        sz[p] += sz[(son[p][0])];
      }
      if ((son[p][1])) {
        sz[p] += sz[(son[p][1])];
      }
    }
  }
  inline int newnode(int Fa, int Val) {
    ++tot;
    fa[tot] = Fa;
    val[tot] = Val;
    son[tot][0] = son[tot][1] = 0;
    sz[tot] = 1;
    return tot;
  }
  inline void ro(int x) {
    int f = fa[x], gf = fa[f], d = dir(x), fd = dir(f);
    son[f][d] = son[x][!d];
    son[x][!d] = f;
    fa[son[f][d]] = f;
    fa[f] = x;
    fa[x] = gf;
    if (gf) son[gf][fd] = x;
    up(f);
    up(x);
  }
  inline void down(int p) {
    if (p && laz[p]) {
      if ((son[p][0])) {
        val[(son[p][0])] += laz[p];
        laz[(son[p][0])] += laz[p];
      }
      if ((son[p][1])) {
        val[(son[p][1])] += laz[p];
        laz[(son[p][1])] += laz[p];
      }
      laz[p] = 0;
    }
  }
  int Q[1000005];
  inline void cl(int x) {
    int tot = 0;
    for (; x; x = fa[x]) Q[++tot] = x;
    for (int i = tot; i; i--) down(Q[i]);
  }
  inline void splay(int x, int y) {
    cl(x);
    for (; fa[x] != y;) {
      if (fa[fa[x]] == y)
        ro(x);
      else {
        if (dir(x) == dir(fa[x]))
          ro(fa[x]);
        else
          ro(x);
        ro(x);
      }
    }
    if (y == 0) rt = x;
  }
  inline int pos(int k) {
    int p = rt;
    for (;;) {
      down(p);
      if ((son[p][0])) {
        if (sz[(son[p][0])] >= k) {
          p = (son[p][0]);
          continue;
        }
        k -= sz[(son[p][0])];
      }
      if (k == 1) return p;
      k--;
      p = (son[p][1]);
    }
  }
  inline int getid(int p) {
    splay(p, 0);
    return sz[(son[p][0])] + 1;
  }
  int pos_l(int p, int Val) {
    if (!p) return 0;
    down(p);
    if (val[p] >= Val) {
      int res = pos_l((son[p][0]), Val);
      if (res > 0) return res;
      return p;
    }
    return pos_l((son[p][1]), Val);
  }
  int pos_r(int p, int Val) {
    if (!p) return 0;
    down(p);
    if (val[p] < Val) {
      int res = pos_r((son[p][1]), Val);
      if (res > 0) return res;
      return p;
    }
    return pos_r((son[p][0]), Val);
  }
  inline void del(int p) {
    int id;
    splay(pos(p - 1), 0);
    splay(id = pos(p + 1), rt);
    son[id][0] = 0;
    splay(id, 0);
  }
  inline void ins(int val) {
    if (!rt)
      rt = newnode(0, val);
    else {
      int p = rt;
      for (; (son[p][1]); p = (son[p][1]))
        ;
      (son[p][1]) = newnode(p, val);
      splay((son[p][1]), 0);
    }
  }
  inline void add(int k, int val) {
    int id;
    splay(pos(k - 1), 0);
    splay(id = pos(k), rt);
    son[id][0] = newnode(id, val);
    splay(tot, 0);
  }
  inline void upd(int l, int r) {
    splay(l, 0);
    splay(r, l);
    if (son[r][0]) {
      laz[son[r][0]]++;
      val[son[r][0]]++;
    }
    splay(son[r][0], 0);
  }
  inline void cal(int l, int r) {
    int posl, posr, id;
    posl = getid(pos_l(rt, l));
    posr = getid(pos_r(rt, r));
    if (posl <= posr) {
      upd(pos(posl - 1), pos(posr + 1));
      del(posr + 1);
      add(posl, l);
    } else {
      Min(val[pos(posl)], l);
    }
  }
  int tmp;
  void dfs(int p, int id) {
    down(p);
    if ((son[p][0])) dfs((son[p][0]), id);
    if (id + sz[(son[p][0])] > 0 && val[p] <= 1001000000)
      Max(tmp, id + sz[(son[p][0])] - 1);
    if ((son[p][1])) dfs((son[p][1]), id + sz[(son[p][0])] + 1);
  }
  inline int dfs_res() {
    tmp = 0;
    dfs(rt, 0);
    return tmp;
  }
  void build() {
    ins(-1);
    ins(0);
    for (int i = 1; i <= n; i++) ins(1001000000 + i);
    ins(1001000000 + n + 1);
    ins(1001000000 + n + 2);
  }
} T;
int main() {
  read(n);
  T.build();
  int l, r;
  for (int i = 1; i <= n; i++) {
    read(l);
    read(r);
    T.cal(l, r);
  }
  int pos = T.dfs_res();
  printf("%d\n", pos);
  return 0;
}
