#include <bits/stdc++.h>
using namespace std;
long long n, a[1000000], k, k1, p;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i > 1; i--) {
    if (a[i] < a[i - 1]) {
      k = i;
      break;
    }
  }
  a[n + 1] = 1000000001;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      k1 = i;
      break;
    }
  }
  if (k1 == 0 && k == 0) {
    cout << "yes" << endl << 1 << " " << 1;
    return 0;
  }
  if (a[k] < a[k1 - 1]) {
    cout << "no";
    return 0;
  }
  if (a[k1] < a[k + 1]) {
    for (int i = k1; i < k; i++)
      if (a[i] > a[i + 1]) p++;
  }
  if (p == k - k1)
    cout << "yes" << endl << k1 << " " << k;
  else
    cout << "no";
}
