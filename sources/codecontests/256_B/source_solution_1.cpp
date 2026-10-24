#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
long long n, Lx, Ly, c, Rx, Ry, x, y;
long long cb(long long x) { return x * (x - 1) / 2; }
unsigned long long check(long long t) {
  unsigned long long ret = sqr(t) + sqr(t + 1);
  long long lx = x - t, rx = x + t, ly = y - t, ry = y + t;
  if (lx < 1) ret -= sqr(1 - lx);
  if (rx > n) ret -= sqr(rx - n);
  if (ly < 1) ret -= sqr(1 - ly);
  if (ry > n) ret -= sqr(ry - n);
  if (t > Lx + Ly) ret += cb(t - Lx - Ly);
  if (t > Lx + Ry) ret += cb(t - Lx - Ry);
  if (t > Rx + Ly) ret += cb(t - Rx - Ly);
  if (t > Rx + Ry) ret += cb(t - Rx - Ry);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> x >> y >> c;
  Rx = n - x, Ry = n - y, Lx = x - 1, Ly = y - 1;
  long long L = 0, R = n * 2, m;
  for (; m = (L + R) >> 1, L < R;) check(m) >= c ? (R = m) : (L = m + 1);
  cout << m << endl;
  return 0;
}
