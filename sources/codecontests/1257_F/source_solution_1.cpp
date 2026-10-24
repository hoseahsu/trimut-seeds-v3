#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N];
vector<pair<vector<int>, int>> c;
int main() {
  scanf("%d", &n);
  vector<int> x(n - 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0, u; i < 32768; i++) {
    u = __builtin_popcount((a[1] & 32767) ^ i);
    for (int j = 2; j <= n; j++)
      x[j - 2] = __builtin_popcount((a[j] & 32767) ^ i) - u;
    c.emplace_back(x, i);
  }
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end(),
                 [&](const pair<vector<int>, int>& i,
                     const pair<vector<int>, int>& j) {
                   return i.first == j.first;
                 }),
          c.end());
  for (int i = 0, u; i < 32768; i++) {
    u = __builtin_popcount((a[1] >> 15) ^ i);
    for (int j = 2; j <= n; j++)
      x[j - 2] = u - __builtin_popcount((a[j] >> 15) ^ i);
    auto it = lower_bound(c.begin(), c.end(), make_pair(x, 0));
    if (it != c.end() && (*it).first == x)
      return printf("%d\n", (i << 15) | it->second), 0;
  }
  return puts("-1"), 0;
}
