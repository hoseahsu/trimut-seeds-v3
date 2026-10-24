#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 30, Mod = 1e9 + 7;
const long long SQ = 330;
long long g[N], a[N], n;
vector<pair<long long, long long> > ans;
void _swap(long long i, long long j) {
  g[a[i]] = j;
  g[a[j]] = i;
  swap(a[i], a[j]);
  ans.push_back({i, j});
}
void change(long long i, long long j) {
  if (i > j) swap(i, j);
  if (abs(i - j) * 2 >= n) {
    _swap(i, j);
    return;
  }
  if (i <= n / 2 and j > n / 2) {
    _swap(j, 1);
    _swap(1, n);
    _swap(i, n);
    _swap(1, n);
    _swap(1, j);
    return;
  }
  if (i <= n / 2 and j <= n / 2) {
    _swap(j, n);
    _swap(i, n);
    _swap(j, n);
  } else {
    _swap(j, 1);
    _swap(i, 1);
    _swap(j, 1);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], g[a[i]] = i;
  for (int i = 1; i <= n; i++)
    if (g[i] != i) change(g[i], i);
  cout << ans.size() << endl;
  for (pair<long long, long long> u : ans)
    cout << u.first << ' ' << u.second << endl;
  return (0);
}
