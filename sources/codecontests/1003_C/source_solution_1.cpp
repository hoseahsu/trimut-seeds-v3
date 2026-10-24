#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k, t, i, j, a[5001];
  double x, y, ans = 0.0;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < n; i++) a[i] += a[i - 1];
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      if (j - i + 1 < k) continue;
      x = a[j];
      if (i > 0) x -= a[i - 1];
      y = j - i + 1;
      ans = max(ans, x / y);
    }
  }
  printf("%.12lf", ans);
}
