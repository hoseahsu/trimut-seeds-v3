#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool mmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool mmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  map<long long, long long> cnt;
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 10000; i++) {
    for (long long j = i; j <= 10000; j++) {
      if (__builtin_popcount(i ^ j) == k) {
        if (cnt[i] == 0) continue;
        if (i == j)
          ans += cnt[i] * (cnt[i] - 1) / 2;
        else
          ans += cnt[i] * cnt[j];
      }
    }
  }
  cout << ans;
  return 0;
}
