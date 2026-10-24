#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
using namespace std;
char frBB[1 << 12], *frS = frBB, *frT = frBB;
inline void read(int& x) {
  x = 0;
  char c = (frS == frT && (frT = (frS = frBB) + fread(frBB, 1, 1 << 12, stdin),
                           frS == frT)
                ? EOF
                : *frS++);
  while (!isdigit(c))
    c = (frS == frT && (frT = (frS = frBB) + fread(frBB, 1, 1 << 12, stdin),
                        frS == frT)
             ? EOF
             : *frS++);
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = (frS == frT && (frT = (frS = frBB) + fread(frBB, 1, 1 << 12, stdin),
                        frS == frT)
             ? EOF
             : *frS++);
  }
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 7;
const int len = 320;
int fa[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int mx[len], L[len], R[len];
int rt[len][N];
unsigned short cnt[N];
int a[N];
inline void build(int x) {
  mx[x] = 0;
  for (int i = L[x]; i <= R[x]; ++i) {
    if (!rt[x][a[i]]) {
      rt[x][a[i]] = i;
      fa[i] = i;
      cnt[rt[x][a[i]]] = 1;
      mx[x] = max(mx[x], a[i]);
    } else {
      fa[i] = rt[x][a[i]];
      cnt[rt[x][a[i]]]++;
    }
  }
}
int tag[len];
inline void pushdown(int x) {
  for (int i = L[x]; i <= R[x]; ++i) {
    a[i] = a[find(i)];
    cnt[rt[x][a[i]]] = 0;
    rt[x][a[i]] = 0;
  }
  for (int i = L[x]; i <= R[x]; ++i) a[i] -= tag[x];
  for (int i = L[x]; i <= R[x]; ++i) fa[i] = 0;
  tag[x] = 0;
}
unsigned short be[N];
inline void modify1(int l, int r, int v) {
  for (int i = be[l]; i <= be[r]; ++i) pushdown(i);
  for (int i = l; i <= r; ++i)
    if (a[i] > v) a[i] -= v;
  for (int i = be[l]; i <= be[r]; ++i) build(i);
}
inline void insert(int x, int p, int q) {
  if (!rt[x][p]) return;
  if (!rt[x][q]) {
    rt[x][q] = rt[x][p];
    cnt[rt[x][q]] = cnt[rt[x][p]];
    a[rt[x][p]] = q;
  } else {
    fa[rt[x][p]] = rt[x][q];
    cnt[rt[x][q]] += cnt[rt[x][p]];
  }
  rt[x][p] = 0;
  cnt[rt[x][p]] = 0;
}
inline void modify2(int x, int v) {
  if (v >= mx[x] - tag[x]) return;
  if (v * 2 > mx[x] - tag[x]) {
    for (int i = v + tag[x] + 1; i <= mx[x]; ++i) insert(x, i, i - v);
    mx[x] = max(mx[x] - v, v + tag[x]);
  } else {
    for (int i = tag[x] + 1; i <= tag[x] + v; ++i) insert(x, i, i + v);
    tag[x] += v;
  }
}
inline void modify(int l, int r, int v) {
  if (be[l] + 1 >= be[r])
    modify1(l, r, v);
  else {
    modify1(l, R[be[l]], v);
    modify1(L[be[r]], r, v);
    for (int i = be[l] + 1; i < be[r]; ++i) modify2(i, v);
  }
}
inline int query1(int l, int r, int v) {
  int ret = 0;
  for (int i = l; i <= r; ++i)
    if (a[find(i)] - tag[be[i]] == v) ret++;
  return ret;
}
inline int query2(int x, int v) {
  if (v + tag[x] > 1e5) return 0;
  return cnt[rt[x][v + tag[x]]];
}
inline int query(int l, int r, int v) {
  if (be[l] + 1 >= be[r])
    return query1(l, r, v);
  else {
    int ret = query1(l, R[be[l]], v) + query1(L[be[r]], r, v);
    for (int i = be[l] + 1; i < be[r]; ++i) ret += query2(i, v);
    return ret;
  }
}
int main() {
  int n, m;
  read(n), read(m);
  int block_size = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    be[i] = (i - 1) / block_size + 1;
    if (!L[be[i]]) L[be[i]] = i;
    R[be[i]] = i;
  }
  for (int i = 1; i <= be[n]; ++i) build(i);
  for (int opt, l, r, x; m; --m) {
    read(opt), read(l), read(r), read(x);
    if (opt == 1)
      modify(l, r, x);
    else
      write(query(l, r, x)), putchar('\n');
  }
}
