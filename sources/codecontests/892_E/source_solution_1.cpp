#include <bits/stdc++.h>
using namespace std;
const int M = 500001;
struct edge {
  int x, y, idx;
  edge(int a, int b, int c) {
    x = a;
    y = b;
    idx = c;
  }
  bool operator<(const edge &a) const { return idx < a.idx; }
};
int n, m, x, y, z, q, c = 0, ds[M], ds1[M], vis[M];
bool is[M];
vector<pair<int, pair<int, int> > > v;
vector<pair<int, int> > g[M];
vector<edge> que[M];
int find(int i) {
  if (i == ds[i]) return i;
  return ds[i] = find(ds[i]);
}
int find1(int i) {
  if (vis[i] != c) {
    vis[i] = c;
    ds1[i] = find(i);
  }
  if (i == ds1[i]) return i;
  return ds1[i] = find1(ds1[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    v.push_back(make_pair(x, make_pair(y, z)));
    g[z].push_back(make_pair(x, y));
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> y;
    for (int j = 0; j < y; j++) {
      cin >> x;
      x--;
      que[v[x].second.second].push_back(edge(v[x].first, v[x].second.first, i));
    }
  }
  for (int i = 1; i <= n; i++) ds[i] = ds1[i] = i;
  for (int i = 1; i < M; i++) {
    sort(que[i].begin(), que[i].end());
    for (int j = 0; j < que[i].size(); j++) {
      edge a = que[i][j];
      if (!j || a.idx != que[i][j - 1].idx) c++;
      int one = find1(a.x), two = find1(a.y);
      if (one != two) {
        ds1[one] = two;
      } else
        is[a.idx] = true;
    }
    for (int j = 0; j < g[i].size(); j++) {
      int one = find(g[i][j].first), two = find(g[i][j].second);
      if (one != two) ds[one] = two;
    }
  }
  for (int i = 0; i < q; i++)
    if (!is[i])
      puts("YES");
    else
      puts("NO");
  return 0;
}
