#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n, q;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> q;
  vector<int> vp(q + 1, 0), when(n, 0);
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      a[p] = x;
      when[p] = i;
    } else {
      int x;
      cin >> x;
      vp[i] = x;
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    vp[i] = max(vp[i], vp[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    cout << max(a[i], vp[when[i]]) << " ";
  }
}
