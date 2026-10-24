#include <bits/stdc++.h>
using namespace std;
int cnt[1000101], vis[1000101], a[5001];
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  int i, j, n, k, limit, sum = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) cnt[a[j] - a[i]]++;
  }
  limit = (k * (k + 1)) / 2;
  for (i = 1; i <= a[n] + 1; i++) {
    sum = 0;
    for (j = i; j <= a[n] + 1; j += i) {
      sum += cnt[j];
      if (sum > limit) break;
    }
    if (sum > limit) continue;
    sum = 0;
    for (j = 1; j <= n; j++) {
      if (vis[a[j] % i] == i)
        sum++;
      else
        vis[a[j] % i] = i;
    }
    if (sum <= k) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
