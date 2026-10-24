#include <bits/stdc++.h>
using namespace std;
int n, k;
long long int off;
long long int p[1010];
long long int a[1010 * 2], ds[1010 * 2];
long long int mem[1010][1010 * 2];
long long int inf = LONG_LONG_MAX;
long long int dp(int prs, int key) {
  if (prs == 0) return 0;
  if (key < prs) return inf;
  if (mem[prs][key] != -1) return mem[prs][key];
  long long int mi = inf;
  mi = min(mi, dp(prs, key - 1));
  mi = min(mi, max(dp(prs - 1, key - 1), abs(p[prs] - a[key]) + ds[key]));
  return mem[prs][key] = mi;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> off;
  memset(mem, -1, sizeof(mem));
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= k; i++) cin >> a[i];
  sort(p + 1, p + n + 1);
  sort(a + 1, a + k + 1);
  for (int i = 1; i <= k; i++) {
    ds[i] = abs(a[i] - off);
  }
  cout << dp(n, k) << endl;
  return 0;
}
