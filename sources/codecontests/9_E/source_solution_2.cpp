#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 55;
int n, m;
int deg[N], pre[N], st[N], ed[N];
pair<int, int> e[N * N];
vector<pair<int, int> > ans;
int find(int x) {
  if (x == pre[x]) return x;
  return pre[x] = find(pre[x]);
}
bool join(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return 1;
  if (x == ed[fx]) swap(st[fx], ed[fx]);
  if (y == ed[fy]) swap(st[fy], ed[fy]);
  st[fx] = ed[fy];
  pre[fy] = fx;
  return 0;
}
bool solve() {
  for (int i = (1); i < (n + 1); i++) pre[i] = st[i] = ed[i] = i;
  for (int i = (0); i < (m); i++) {
    int u, v;
    cin >> u >> v;
    e[i] = make_pair(u, v);
    ++deg[u], ++deg[v];
  }
  for (int i = (1); i < (n + 1); i++)
    if (deg[i] > 2) return 0;
  bool ring = 0;
  for (int i = (0); i < (m); i++) {
    int u = e[i].first, v = e[i].second;
    ring |= join(u, v);
  }
  multiset<pair<int, int> > s;
  for (int i = (1); i < (n + 1); i++)
    if (i == find(i)) {
      s.insert(make_pair(st[i], i));
      s.insert(make_pair(ed[i], i));
    }
  if (ring) return (int)s.size() == 2;
  while ((int)s.size()) {
    auto u = s.begin(), v = u;
    ++v;
    if (find(u->second) == find(v->second) && (int)s.size() > 2) ++v;
    ans.push_back(make_pair(u->first, v->first));
    join(u->first, v->first);
    s.erase(u), s.erase(v);
  }
  return 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> m;
  if (solve()) {
    cout << "YES"
         << "\n";
    cout << (int)ans.size() << "\n";
    for (auto u : ans) cout << u.first << " " << u.second << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
