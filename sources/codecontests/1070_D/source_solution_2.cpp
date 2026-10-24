#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    long long cur = (a[i] + k - 1) / k;
    ans += cur;
    a[i - 1] -= cur * k - a[i];
    if (a[i - 1] < 0) a[i - 1] = 0;
  }
  ans += (a[0] + k - 1) / k;
  cout << ans;
  return 0;
}
