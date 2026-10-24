#include <bits/stdc++.h>
using namespace std;
long long s[200009];
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long i, j, n, l, r, ql, qr, ans = 1e14, k, m;
  cin >> n >> l >> r >> ql >> qr;
  for (i = 1; i <= n; i++) {
    long long w;
    cin >> w;
    s[i] = s[i - 1] + w;
  }
  for (i = 0; i <= n; i++) {
    m = l * s[i] + r * (s[n] - s[i]);
    k = 2 * i;
    if (k > n)
      m += (k - n - 1) * ql;
    else if (k < n)
      m += (n - k - 1) * qr;
    ans = min(ans, m);
  }
  cout << ans;
}
