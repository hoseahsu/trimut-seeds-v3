#include <bits/stdc++.h>
using namespace std;
long long h[100000], f[100000], r[100000];
int main() {
  int n;
  long long k;
  while (cin >> n >> k) {
    long long pt = 0;
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
      f[i] = h[i] % 10;
      r[i] = 100 - h[i];
      if (f[i] > 0) r[i] -= 1;
      pt += h[i] / 10;
    }
    sort(f, f + n);
    int i = n;
    while (--i >= 0 && k > 0) {
      if (f[i] && k >= 10 - f[i]) {
        k -= 10 - f[i];
        pt += 1;
      }
    }
    i = -1;
    while (++i < n && k >= 10) {
      long long x = min(k, r[i]) / 10;
      k -= 10 * x;
      pt += x;
    }
    cout << pt << endl;
  }
  return 0;
}
