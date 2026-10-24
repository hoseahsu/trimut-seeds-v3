#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 200010;
inline int read() {
  int s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
int n, m;
struct Node {
  int c, q;
} a[N];
int b[N];
inline bool cp(Node x, Node y) { return x.q == y.q ? x.c < y.c : x.q > y.q; }
int root, ch[N][2], siz[N], rnd[N], val[N], sum[N], t1[N], t2[N];
inline int New_Node(int x, int k) {
  val[k] = x, siz[k] = 1, rnd[k] = rand();
  return k;
}
inline void Push_Up(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1; }
inline void Push_Down(int x) {
  if (ch[x][0])
    t1[ch[x][0]] += t1[x], t2[ch[x][0]] += t2[x], val[ch[x][0]] -= t1[x],
        sum[ch[x][0]] += t2[x];
  if (ch[x][1])
    t1[ch[x][1]] += t1[x], t2[ch[x][1]] += t2[x], val[ch[x][1]] -= t1[x],
        sum[ch[x][1]] += t2[x];
  t1[x] = t2[x] = 0;
}
void Split(int root, int k, int &x, int &y) {
  if (!root) {
    x = y = 0;
    return;
  }
  Push_Down(root);
  if (val[root] <= k)
    x = root, Split(ch[root][1], k, ch[root][1], y);
  else
    y = root, Split(ch[root][0], k, x, ch[root][0]);
  Push_Up(root);
}
int Merge(int x, int y) {
  if (!x || !y) return x | y;
  Push_Down(x), Push_Down(y);
  if (rnd[x] < rnd[y]) {
    ch[x][1] = Merge(ch[x][1], y), Push_Up(x);
    return x;
  } else {
    ch[y][0] = Merge(x, ch[y][0]), Push_Up(y);
    return y;
  }
}
inline void Insert(int k, int ui) {
  int x, y;
  Split(root, k, x, y);
  root = Merge(Merge(x, New_Node(k, ui)), y);
}
void Change(int x, int &to, int C) {
  Push_Down(x);
  if (ch[x][0]) Change(ch[x][0], to, C);
  if (ch[x][1]) Change(ch[x][1], to, C);
  ch[x][0] = ch[x][1] = 0;
  int y, z;
  val[x] -= C, sum[x]++;
  Split(to, val[x], y, z);
  to = Merge(Merge(y, x), z);
}
inline void UpDate(int C) {
  int x, y, z;
  Split(root, C - 1, x, y);
  Split(y, C * 2 - 1, y, z);
  if (z) val[z] -= C, t1[z] += C, sum[z]++, t2[z]++;
  Change(y, x, C);
  root = Merge(x, z);
}
void Down(int x) {
  Push_Down(x);
  if (ch[x][0]) Down(ch[x][0]);
  if (ch[x][1]) Down(ch[x][1]);
}
signed main() {
  srand(time(NULL));
  n = read();
  for (register int i = 1; i <= n; i++) a[i].c = read(), a[i].q = read();
  sort(a + 1, a + 1 + n, cp);
  m = read();
  for (register int i = 1; i <= m; i++) b[i] = read(), Insert(b[i], i);
  for (register int i = 1; i <= n; i++) UpDate(a[i].c);
  Down(root);
  for (register int i = 1; i <= m; i++) printf("%d ", sum[i]);
  puts("");
  return 0;
}
