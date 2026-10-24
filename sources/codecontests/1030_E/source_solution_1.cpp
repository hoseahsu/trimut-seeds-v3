#include <bits/stdc++.h>
using namespace std;
int a[300500];
int s[300500];
long long o[2];
long long ans;
int n;
int main() {
  scanf("%i", &n);
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    while (x) {
      a[i] += x & 1;
      x = x >> 1;
    }
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) o[s[i] % 2]++;
  ans = o[0] * (o[0] - 1) / 2 + o[1] * (o[1] - 1) / 2 + o[0];
  for (int l, r, i = 1; i <= n; ++i) {
    int q, t;
    q = a[i];
    t = 0;
    for (l = 1; i - l >= 1; l++) {
      if (q - t - a[i - l] <= 0) break;
      t += a[i - l];
    }
    l--;
    t = 0;
    for (r = 1; i + r <= n; r++) {
      if (q - t - a[i + r] <= 0) break;
      t += a[i + r];
    }
    r--;
    for (int l1 = 0; l1 <= l; ++l1)
      for (int r1 = 0; r1 <= r; ++r1) {
        int v = s[i + r1] - s[i - l1 - 1];
        if (v % 2 == 0 && a[i] > v - a[i]) ans--;
      }
  }
  printf("%lld\n", ans);
}
