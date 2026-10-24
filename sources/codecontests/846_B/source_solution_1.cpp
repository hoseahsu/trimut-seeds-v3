#include <bits/stdc++.h>
using namespace std;
int n, k, m, a[50], all, ans;
int _try(int x) {
  int t = m - x * all;
  int points = x * (k + 1);
  if (t < 0) return 0;
  for (int j = 0; j < k; j++)
    for (int i = 0; i < n - x; i++)
      if (t >= a[j]) t -= a[j], points++;
  return points;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < k; i++) scanf("%d", &a[i]), all += a[i];
  sort(a, a + k);
  for (int i = 0; i <= n; i++) ans = max(ans, _try(i));
  cout << ans << endl;
}
