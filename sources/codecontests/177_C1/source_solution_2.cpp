#include <bits/stdc++.h>
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
using namespace std;
const int N = 2005;
int par[N], r[N];
int find(int a) {
  if (par[a] < 0)
    return a;
  else
    return (par[a] = find(par[a]));
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (r[a] > r[b]) {
    par[b] = a;
    r[a] += r[b];
  } else {
    par[a] = b;
    r[b] += r[a];
  }
}
void solve() {
  int n, m, k, a, b, i;
  cin >> n >> k;
  for (i = 1; i < n + 1; i++) par[i] = -1, r[i] = 1;
  for (i = 0; i < k; i++) {
    cin >> a >> b;
    merge(a, b);
  }
  cin >> m;
  if (k == 0 && m != 0) {
    for (i = 0; i < m; i++) {
      cin >> a >> b;
      merge(a, b);
    }
    int cnt = 0;
    for (i = 1; i < n + 1; i++)
      if (par[i] < 0) cnt++;
    cout << cnt;
    return;
  }
  set<pair<int, int> > s;
  for (i = 1; i < n + 1; i++) {
    if (r[i] > 1) s.insert(make_pair(r[i], i));
    if (r[i] == 1 && par[i] < 0) s.insert(make_pair(r[i], i));
  }
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    if (find(a) == find(b)) {
      int p = find(a);
      for (auto i : s) {
        if (i.second == p) {
          s.erase(i);
          break;
        }
      }
    }
  }
  if (k == 0 && m == 0)
    cout << 1;
  else if ((int)s.size()) {
    auto it = s.end();
    it--;
    cout << it->first;
  } else
    cout << 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
