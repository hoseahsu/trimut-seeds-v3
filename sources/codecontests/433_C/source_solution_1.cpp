#include <bits/stdc++.h>
using namespace std;
const int N = 100500;
int n, m, a[N];
long long now = 0, ans;
vector<int> id[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < m; ++i) {
    now += abs(a[i + 1] - a[i]);
    if (a[i] == a[i + 1]) continue;
    id[a[i]].push_back(a[i + 1]);
    id[a[i + 1]].push_back(a[i]);
  }
  ans = now;
  for (int i = 1; i <= n; ++i) {
    if (id[i].size()) {
      sort(id[i].begin(), id[i].end());
      long long nxt = id[i][id[i].size() / 2];
      long long cur = now;
      for (int j = 0; j < id[i].size(); ++j) {
        cur -= abs(i - id[i][j]);
        cur += abs(nxt - id[i][j]);
      }
      ans = min(ans, cur);
    }
  }
  cout << ans;
  return 0;
}
