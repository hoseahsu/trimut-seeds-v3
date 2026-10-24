#include <bits/stdc++.h>
const bool DEBUG = false;
using namespace std;
const long long maxn = 100000 + 5;
const long long INF = 4e18;
const long long M = 1e9 + 7;
const long long M2 = 311;
const int lg = 21;
int n, m, last, h, y, ans, a[maxn], id[maxn], sz[maxn];
vector<int> com[maxn], ko[maxn], vo[maxn];
vector<int> t;
bool mark[maxn], ok[maxn];
void dfsback(int v) {
  mark[v] = 1;
  id[v] = last;
  com[last].push_back(v);
  sz[last]++;
  for (auto u : vo[v])
    if (!mark[u]) dfsback(u);
}
void dfsfor(int v, int p = -1) {
  mark[v] = 1;
  for (auto u : ko[v]) {
    if (!mark[u]) dfsfor(u);
  }
  t.push_back(v);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> h;
  ans = n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y, x--, y--;
    if (a[x] == ((a[y] + 1) % h)) {
      ko[y].push_back(x);
      vo[x].push_back(y);
    }
    if (a[y] == ((a[x] + 1) % h)) {
      ko[x].push_back(y);
      vo[y].push_back(x);
    }
  }
  for (int i = 0; i < n; i++)
    if (!mark[i]) dfsfor(i);
  fill(mark, mark + maxn, 0);
  for (int j = n - 1; j >= 0; j--)
    if (!mark[t[j]]) {
      dfsback(t[j]);
      last++;
    }
  for (int i = 0; i < last; i++) {
    bool flag = 1;
    for (auto u : com[i]) {
      for (auto p : ko[u])
        if (id[p] != i) flag = 0;
    }
    if (flag and ans > sz[i]) ans = sz[i], y = i;
  }
  cout << ans << endl;
  for (auto u : com[y]) cout << u + 1 << " ";
  cout << endl;
  return 0;
}
