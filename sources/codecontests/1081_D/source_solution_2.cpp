#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k, byk[N];
int par[N];
pair<int, pair<int, int> > edge[N];
int now;
int find(int u) {
  if (par[u] == u) return u;
  return par[u] = find(par[u]);
}
void merge(int x, int y) {
  byk[find(x)] += byk[find(y)];
  byk[find(y)] = 0;
  par[find(y)] = find(x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    byk[x]++;
  }
  for (int i = 1; i <= m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edge[i] = {w, {a, b}};
  }
  int ans = 0;
  sort(edge + 1, edge + m + 1);
  for (int i = 1; i <= m; i++) {
    pair<int, pair<int, int> > isi = edge[i];
    if (find(isi.second.first) == find(isi.second.second)) continue;
    now = isi.first;
    merge(isi.second.first, isi.second.second);
    if (byk[find(isi.second.first)] == k) {
      ans = now;
      break;
    }
  }
  for (int i = 1; i <= k; i++) {
    cout << ans << " ";
  }
  cout << endl;
}
