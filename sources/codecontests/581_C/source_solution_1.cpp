#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long n, k, i;
    cin >> n >> k;
    vector<pair<long long, long long>> a;
    for (i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a.push_back({10 - x % 10, x});
    }
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++) {
      if (k >= a[i].first) {
        k = k - a[i].first;
        a[i].second = a[i].second + a[i].first;
        a[i].first = 0;
      } else {
        a[i].second = a[i].second + k;
        k = 0;
        break;
      }
    }
    long long ans = 0, kd = 0;
    for (i = 0; i < n; i++) {
      long long x = 100 - a[i].second;
      if (x <= k && a[i].second + x == 100) {
        k = k - x;
        a[i].second = a[i].second + x;
      } else {
        a[i].second = a[i].second + k;
        k = 0;
        break;
      }
    }
    for (i = 0; i < n; i++) {
      ans = ans + a[i].second / 10;
    }
    cout << ans;
  }
  return 0;
}
