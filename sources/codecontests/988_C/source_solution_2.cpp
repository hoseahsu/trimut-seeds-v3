#include <bits/stdc++.h>
using namespace std;
const long long N = 300010, M = 10000;
long long t, n;
vector<pair<long long, long long>> a;
map<long long, pair<long long, long long>> v;
int main() {
  scanf("%lld", &t);
  bool f = 0;
  for (int i = 1; i <= t; i++) {
    a.clear();
    scanf("%lld", &n);
    long long sum = 0;
    for (int j = 1; j <= n; j++) {
      long long x;
      scanf("%lld", &x);
      a.push_back({x, j});
      sum += x;
    }
    if (f) continue;
    sort(a.begin(), a.end());
    for (int j = 0; j < n; j++) {
      if (j == 0 || a[j].first != a[j - 1].first) {
        long long ns = sum - a[j].first, k = a[j].second;
        if (v[ns].first != 0) {
          printf("YES\n");
          printf("%d %lld\n", i, k);
          printf("%lld %lld\n", v[ns].first, v[ns].second);
          f = 1;
          break;
        }
        v[ns] = {i, k};
      }
    }
  }
  if (f == 0) printf("NO\n");
  return 0;
}
