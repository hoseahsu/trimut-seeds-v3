#include <bits/stdc++.h>
using namespace std;
int n;
int spe[111111], sz[111111], dd[111111], belong[111111], h[111111], sl;
long long up[111111], down[111111], ans, M, PHI;
vector<pair<int, int> > a[111111];
vector<int> vlist;
void nhap() {
  scanf("%I64d %I64d", &n, &M);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u++;
    v++;
    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
  }
}
int phi(int x) {
  int ans = 1;
  int y = x;
  for (long long i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      y /= i;
      ans *= (i - 1);
    }
    while (x % i == 0) x /= i;
  }
  if (x > 1) {
    y /= x;
    ans *= (x - 1);
  }
  x = 1;
  ans *= y;
  return ans;
}
long long Pow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return r;
}
long long inv(long long a) { return Pow(a, PHI - 1); }
void dfsCentroid(int u) {
  spe[u] = 0;
  sz[u] = 1;
  dd[u] = 1;
  for (pair<int, int> &z : a[u]) {
    int v = z.first;
    if (dd[v]) continue;
    dfsCentroid(v);
    if (sz[v] > sz[spe[u]]) spe[u] = v;
    sz[u] += sz[v];
  }
  dd[u] = 0;
}
int centroid(int u) {
  int siz = sz[u] / 2;
  while (sz[spe[u]] > siz) u = spe[u];
  return u;
}
void DFS1(int u, int p, int cent) {
  if (p == cent)
    belong[u] = sl++;
  else if (p != -1)
    belong[u] = belong[p];
  vlist.push_back(u);
  for (auto z : a[u]) {
    int v = z.first;
    int w = z.second;
    if (v == p || dd[v]) continue;
    up[v] = (up[u] + (1ll * w * Pow(10, h[u])) % M) % M;
    down[v] = ((down[u] * 10) % M + w) % M;
    h[v] = h[u] + 1;
    DFS1(v, u, cent);
  }
}
void solve(int u) {
  dfsCentroid(u);
  u = centroid(u);
  dd[u] = 1;
  vlist.clear();
  sl = 0;
  up[u] = down[u] = h[u] = 0;
  belong[u] = -1;
  DFS1(u, -1, u);
  map<long long, long long> all;
  vector<map<long long, long long> > only;
  only.resize(sl + 2);
  all[0]++;
  for (int &v : vlist) {
    if (v == u) continue;
    all[up[v]]++;
    only[belong[v]][up[v]]++;
  }
  for (int &v : vlist) {
    int dep = h[v];
    int comp = belong[v];
    if (v == u) {
      ans += all[0] - 1;
    } else {
      long long val = (-down[v] + M) % M;
      val = (val * inv(Pow(10, dep))) % M;
      ans += all[val] - only[comp][val];
    }
  }
  for (pair<int, int> &z : a[u])
    if (!dd[z.first]) solve(z.first);
}
void xuli() {
  if (M == 1)
    ans = 1ll * n * (n - 1);
  else {
    PHI = phi(M);
    solve(1);
  }
  cout << ans;
}
int main() {
  nhap();
  xuli();
  return 0;
}
