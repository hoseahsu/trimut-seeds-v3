#include <bits/stdc++.h>
using namespace std;
void magic_io() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long MOD = 1000000007LL;
const int MAXN = 300009;
class SegmentTree {
 private:
  long long vals[MAXN * 4];
  long long lazy[MAXN * 4];
  void pushDown(int node) {
    if (lazy[node] != 0) {
      vals[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
      vals[node * 2 + 1] = (vals[node * 2 + 1] + lazy[node]) % MOD;
      lazy[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
      lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % MOD;
      lazy[node] = 0;
    }
  }
  void update(int node, int ql, int qr, int nl, int nr, int val) {
    if (ql <= nl && nr <= qr) {
      vals[node] = (vals[node] + val) % MOD;
      lazy[node] = (lazy[node] + val) % MOD;
      return;
    }
    pushDown(node);
    int m = (nl + nr) / 2;
    if (ql <= m) update(node * 2, ql, qr, nl, m, val);
    if (m < qr) update(node * 2 + 1, ql, qr, m + 1, nr, val);
  }
  long long query(int node, int q, int nl, int nr) {
    if (q <= nl && nr <= q) {
      return vals[node] % MOD;
    }
    pushDown(node);
    int m = (nl + nr) / 2;
    if (q <= m) return query(node * 2, q, nl, m);
    if (m < q) return query(node * 2 + 1, q, m + 1, nr);
  }

 public:
  void update(int ql, int qr, int val) { update(1, ql, qr, 0, MAXN - 1, val); }
  long long query(int q) { return query(1, q, 0, MAXN - 1); }
};
map<int, vector<int>> edges;
int L[MAXN], R[MAXN], D[MAXN], TikTok = 0;
SegmentTree segmenttreescan, gotohell;
void dfs(int node, int depth) {
  L[node] = TikTok++;
  D[node] = depth;
  for (int dst : edges[node]) {
    dfs(dst, depth + 1);
  }
  R[node] = TikTok - 1;
}
int main() {
  magic_io();
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    edges[p].push_back(i);
  }
  dfs(0, 0);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      long long v, x, k;
      scanf("%lld%lld%lld", &v, &x, &k);
      v--;
      segmenttreescan.update(L[v], R[v], (x + (D[v] * k) % MOD) % MOD);
      gotohell.update(L[v], R[v], k % MOD);
    } else if (type == 2) {
      long long v;
      scanf("%lld", &v);
      v--;
      long long k1 = segmenttreescan.query(L[v]);
      long long k2 = gotohell.query(L[v]);
      long long res = ((k1 - D[v] * k2 + MOD) % MOD + MOD) % MOD;
      printf("%lld\n", res);
    }
  }
  return 0;
}
