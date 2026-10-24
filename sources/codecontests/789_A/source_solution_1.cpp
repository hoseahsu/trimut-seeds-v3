#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int a[100005];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int i = 0;
  int cnt = 0;
  while (i < n) {
    if (a[i] <= 0) {
      i++;
      continue;
    }
    if (a[i] >= 2 * k) {
      ans += a[i] / (2 * k);
      a[i] %= (2 * k);
    } else if (a[i] > 0) {
      cnt++;
      a[i] -= k;
      if (a[i] <= 0) i++;
      if (cnt == 2) {
        ans++;
        cnt = 0;
      }
    }
  }
  if (cnt > 0) ans++;
  cout << ans;
  return 0;
}
