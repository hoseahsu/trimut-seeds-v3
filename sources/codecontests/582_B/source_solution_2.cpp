#include <bits/stdc++.h>
using namespace std;
int n, t, len, a[10001], b[10001], f[10001];
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int len = min(n, t) * n;
  for (int i = 1; i <= n; i++) b[a[i]]++;
  int mxa = 1;
  for (int i = n + 1; i <= len; i++) a[i] = a[i - n];
  for (int i = 1; i <= len; i++) {
    f[i] = 1;
    for (int j = i - 1; j >= max(i - n, 1); j--) {
      if (a[i] >= a[j]) f[i] = max(f[i], f[j] + 1);
    }
    mxa = max(mxa, f[i]);
  }
  if (n >= t) {
    cout << mxa;
    return 0;
  } else {
    int maxx = 0;
    for (int i = 0; i <= 305; i++) maxx = max(maxx, b[i]);
    cout << mxa + maxx * (t - n);
    return 0;
  }
}
