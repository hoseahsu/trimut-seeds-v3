#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 1e18;
priority_queue<pair<long long, pair<long long, long long> > > Q;
long long cal(long long x, long long p) {
  long long a = x / p;
  long long b = x % p;
  return (p - b) * a * a + b * (a + 1) * (a + 1);
}
void rua() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ans += 1ll * x * x;
    Q.push({cal(x, 1) - cal(x, 2), {x, 2}});
  }
  int m = k - n;
  while (m--) {
    auto u = Q.top();
    Q.pop();
    ans -= u.first;
    int x = u.second.first, y = u.second.second;
    Q.push({cal(x, y) - cal(x, y + 1), {x, y + 1}});
  }
  printf("%lld\n", ans);
}
int main() {
  rua();
  return 0;
}
