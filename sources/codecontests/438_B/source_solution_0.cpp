#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m;
int a[maxn];
struct Edge {
  int x, y, w;
  bool operator<(const Edge &rhs) const { return w < rhs.w; }
} e[maxn];
int sum[maxn], fa[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main(int argc, char *argv[]) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> e[i].x >> e[i].y;
    e[i].w = min(a[e[i].x], a[e[i].y]);
  }
  sort(e, e + m);
  reverse(e, e + m);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    sum[i] = 1;
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    int fx = find(e[i].x), fy = find(e[i].y);
    if (fx != fy) {
      ans += 1LL * sum[fx] * sum[fy] * e[i].w;
      fa[fx] = fy;
      sum[fy] += sum[fx];
    }
  }
  ans <<= 1;
  cout.precision(8);
  cout << (double)ans / (1LL * n * (n - 1)) << endl;
  return 0;
}
