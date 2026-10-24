#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
static inline int popcnt(unsigned x) { return __builtin_popcount(x); }
static inline int popcntll(unsigned long long x) {
  return __builtin_popcountll(x);
}
struct Node {
  vector<int> adj;
  int l, r;
  int d, p;
};
long long a[2 * 1000008];
Node nds[1000008];
bool take[1000008];
void add(int n, int i, int x) {
  for (; i <= n; i += i & -i) a[i] += x;
}
long long get(int i) {
  long long r = 0;
  for (; i > 0; i -= i & -i) r += a[i];
  return r;
}
void dfs(int u, int p = 0) {
  static int nxt = 0;
  nds[u].p = p;
  nds[u].l = ++nxt;
  a[nds[u].l] += nds[u].d;
  a[nds[u].l + 1] -= nds[u].d;
  for (int v : nds[u].adj) {
    if (v == p) continue;
    nds[v].d = nds[u].d + 1;
    dfs(v, u);
  }
  nds[u].r = ++nxt;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    nds[a].adj.push_back(b);
    nds[b].adj.push_back(a);
  }
  dfs(n);
  take[n] = true;
  k = n - k - 1;
  for (int i = 1; i <= 2 * n; ++i) {
    int j = i + (i & -i);
    if (j <= 2 * n) a[j] += a[i];
  }
  for (int i = n - 1; i > 0; --i) {
    if (take[i]) continue;
    long long c = get(nds[i].l);
    if (k < c) continue;
    k -= c;
    for (int u = i;;) {
      take[u] = true;
      add(2 * n, nds[u].l, -1);
      add(2 * n, nds[u].r, 1);
      u = nds[u].p;
      if (take[u]) break;
    }
    if (!k) break;
  }
  for (int i = 1; i < n; ++i)
    if (!take[i]) printf("%d ", i);
  return 0;
}
