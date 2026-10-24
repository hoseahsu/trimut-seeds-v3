#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    a[i] = x;
  }
  sort(a.begin(), a.end());
  long long int ans = 0;
  for (long long int k = 0; k < 27; k++) {
    vector<long long int> b(n);
    for (long long int i = 0; i < n; i++) {
      b[i] = a[i] % (1 << (k + 1));
    }
    sort(b.begin(), b.end());
    long long int ctrl = 0;
    for (long long int i = 0; i < n; i++) {
      long long int l =
          lower_bound(b.begin() + i + 1, b.end(), ((1 << k) - b[i])) -
          b.begin();
      long long int r =
          lower_bound(b.begin() + i + 1, b.end(), ((1 << (k + 1)) - b[i])) -
          b.begin();
      ctrl += (r - l);
      long long int r1 = lower_bound(b.begin() + i + 1, b.end(),
                                     ((1 << k) + (1 << (k + 1)) - b[i])) -
                         b.begin();
      ctrl += (n - r1);
    }
    ans += (ctrl % 2) * 1LL * (1 << k);
  }
  cout << ans << "\n";
}
