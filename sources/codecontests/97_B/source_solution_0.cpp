#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int N = 1e4 + 20;
pair<int, int> a[N];
set<pair<int, int> > s;
int n;
void solve(int l, int r) {
  if (r - l < 2) return;
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid, r);
  int x = a[mid].first;
  for (int i = l; i < r; i++) s.insert(make_pair(x, a[i].second));
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    s.insert(a[i]);
  }
  sort(a, a + n);
  solve(0, n);
  cout << s.size() << endl;
  for (auto x : s) cout << x.first << ' ' << x.second << endl;
}
