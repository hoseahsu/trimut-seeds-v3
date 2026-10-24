#include <bits/stdc++.h>
using namespace std;
long long const inf = 1e9 + 7;
int32_t main() {
  long long t;
  cin >> t;
  for (long long k = 0; k < t; ++k) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long l = 0, r = n - 1;
    long long shitl = 0, shitr = 0;
    long long sosat = 0;
    while (r > l + 1) {
      if (a[l] < shitl || a[r] < shitr) {
        sosat = 1;
        break;
      } else {
        ++l;
        --r;
        ++shitl;
        ++shitr;
      }
    }
    if (sosat) {
      cout << "No" << '\n';
      continue;
    }
    if (l == r) {
      if (a[l] >= shitl)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
      continue;
    } else {
      l = n / 2 - 1;
      r = l + 1;
      shitl = l;
      shitr = shitl;
      if (a[l] >= shitl + 1 && a[r] >= shitr ||
          a[l] >= shitl && a[r] >= shitr + 1)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
      continue;
    }
  }
  return 0;
}
