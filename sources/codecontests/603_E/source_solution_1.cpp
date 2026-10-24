#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "no-stack-protector", "unroll-loops")
using namespace std;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <class I>
inline void gi(I &x) {
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = (x << 1) + (x << 3) + (c & 15);
}
template <class I>
inline void print(I x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::gi;
using io ::print;
using io ::putc;
const int N = 400005;
int n, m;
set<int> s[N];
struct Edge {
  int u, v, w;
} e[N];
struct LinkCutTree {
  int ch[N][2], fa[N], size[N], si[N], val[N], pos[N];
  bool rev[N];
  bool get(int x) { return ch[fa[x]][1] == x; }
  inline bool isrt(int x) { return (ch[fa[x]][1] != x) && (ch[fa[x]][0] != x); }
  inline void pushup(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + si[x] + (x <= n);
    pos[x] = x;
    if (val[pos[ch[x][0]]] > val[pos[x]]) pos[x] = pos[ch[x][0]];
    if (val[pos[ch[x][1]]] > val[pos[x]]) pos[x] = pos[ch[x][1]];
  }
  void rotate(int x) {
    int old = fa[x], oldf = fa[fa[x]], k = get(x);
    if (!isrt(old)) ch[oldf][ch[oldf][1] == old] = x;
    ch[old][k] = ch[x][k ^ 1], ch[x][k ^ 1] = old;
    fa[ch[old][k]] = old, fa[old] = x, fa[x] = oldf;
    pushup(old), pushup(x);
  }
  void pushdown(int x) {
    if (rev[x]) {
      rev[ch[x][0]] ^= 1, rev[ch[x][1]] ^= 1;
      ch[x][0] ^= ch[x][1] ^= ch[x][0] ^= ch[x][1];
      rev[x] = false;
    }
  }
  void push(int x) {
    if (!isrt(x)) push(fa[x]);
    pushdown(x);
  }
  void Splay(int x) {
    push(x);
    for (; !isrt(x); rotate(x))
      if (!isrt(fa[x])) rotate(get(x) == get(fa[x]) ? fa[x] : x);
    pushup(x);
  }
  void Access(int x) {
    for (int e = 0; x; e = x, x = fa[x])
      Splay(x), si[x] += size[ch[x][1]], si[x] -= size[ch[x][1] = e], pushup(x);
  }
  void Makeroot(int x) { Access(x), Splay(x), rev[x] ^= 1; }
  void link(int u, int v) {
    Makeroot(u), Access(v), Splay(v);
    fa[u] = v, si[v] += size[u], pushup(v);
  }
  void cut(int u, int v) {
    Makeroot(u), Access(v), Splay(v);
    ch[v][0] = fa[u] = 0;
    pushup(v);
  }
  void Cut(int u, int v, int id) { cut(u, id), cut(v, id); }
  inline int getrt(int x) {
    Access(x), Splay(x);
    while (ch[x][0]) x = ch[x][0];
    Splay(x);
    return x;
  }
  void insert(int x, int y, int id) {
    if (getrt(x) != getrt(y)) {
      link(x, id), link(y, id);
      s[e[id - n].w].insert(id);
    } else {
      Makeroot(x), Access(y), Splay(y);
      int p = pos[y];
      if (val[p] > val[id]) {
        Cut(e[p - n].u, e[p - n].v, p);
        s[e[p - n].w].erase(p);
        link(x, id), link(y, id);
        s[e[id - n].w].insert(id);
      }
    }
  }
  inline int query(int x) {
    Makeroot(x), Access(x), Splay(x);
    return size[x];
  }
} LCT;
int w[N];
int main() {
  gi(n), gi(m);
  for (int i = 1; i <= n; i++) LCT.pushup(i);
  for (int i = 1; i <= m; i++) {
    gi(e[i].u), gi(e[i].v), gi(e[i].w);
    w[i] = e[i].w;
  }
  sort(w + 1, w + m + 1);
  int cnt = unique(w + 1, w + m + 1) - w - 1;
  for (int i = 1; i <= m; i++)
    LCT.val[i + n] = e[i].w = lower_bound(w + 1, w + cnt + 1, e[i].w) - w;
  int ans = cnt + 1, tot = n;
  w[ans] = -1;
  for (int i = 1; i <= m; i++) {
    if (e[i].w >= ans) {
      print(w[ans]), putc('\n');
      continue;
    } else {
      tot -= (LCT.query(e[i].u) & 1);
      if (LCT.getrt(e[i].u) != LCT.getrt(e[i].v))
        tot -= (LCT.query(e[i].v) & 1);
      LCT.insert(e[i].u, e[i].v, i + n);
      tot += (LCT.query(e[i].u) & 1);
      while (tot == 0) {
        ans--;
        for (set<int>::iterator it = s[ans].begin(); it != s[ans].end(); it++) {
          int u = e[(*it) - n].u, v = e[(*it) - n].v;
          tot -= (LCT.query(u) & 1);
          LCT.Cut(u, v, *it);
          tot += (LCT.query(u) & 1);
          tot += (LCT.query(v) & 1);
        }
      }
      print(w[ans]), putc('\n');
    }
  }
  return 0;
}
