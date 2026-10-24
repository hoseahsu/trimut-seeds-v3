#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  int mn[2 * k + 1], mx[2 * k + 1];
  for (int& x : mn) x = 1e8;
  for (int& x : mx) x = -1e8;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      mn[x] = min(mn[x], i + j);
      mx[x] = max(mx[x], i + j);
      mn[x + k] = min(mn[x + k], i - j);
      mx[x + k] = max(mx[x + k], i - j);
    }
  }
  int res = 0;
  int p, q;
  cin >> p;
  for (int i = 1; i < s; i++) {
    cin >> q;
    res = max(res, mx[p] - mn[q]);
    res = max(res, mx[q] - mn[p]);
    res = max(res, mx[p + k] - mn[q + k]);
    res = max(res, mx[q + k] - mn[p + k]);
    p = q;
  }
  cout << res << '\n';
}
