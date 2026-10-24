#include <bits/stdc++.h>
using namespace std;
long long n, d, ans, a[100000 + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0, j = 0; i < n; ++i) {
    while (a[j] - a[i] <= d and j < n) j++;
    ans += ((j - i - 1) * (j - i - 2)) / 2;
  }
  cout << ans << endl;
  return 0;
}
