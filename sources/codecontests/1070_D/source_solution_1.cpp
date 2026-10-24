#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int MOD = 1e9 + 7;
long long n, k;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  long long p = 0;
  for (int i = 1; i <= n; i++) {
    if (i == n && (a[i] + p)) {
      ans += (a[i] + p - 1) / k + 1;
    } else {
      if (p) {
        long long c = max((a[i] + p) / k, 1ll);
        ans += c;
        p = max(0ll, a[i] + p - c * k);
      } else {
        ans += a[i] / k;
        p += a[i] % k;
      }
    }
  }
  cout << ans;
}
