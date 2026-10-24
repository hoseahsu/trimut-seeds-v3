#include <bits/stdc++.h>
using namespace std;
int a[201000], vis[201000], c[201000];
pair<int, int> b[201000];
int flag[201000];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      vis[i] = 1;
      b[i] = make_pair(x, y);
    } else {
      int x;
      cin >> x;
      c[i] = x;
    }
  }
  for (int i = q; i >= 1; i--) {
    if (vis[i] && !flag[b[i].first]) {
      a[b[i].first] = max(c[i + 1], b[i].second);
      flag[b[i].first] = 1;
    }
    c[i] = max(c[i + 1], c[i]);
  }
  for (int i = 1; i <= n; i++)
    if (!flag[i])
      cout << max(a[i], c[1]) << " ";
    else
      cout << a[i] << " ";
  return 0;
}
