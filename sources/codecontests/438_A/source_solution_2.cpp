#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], u[2010], v[2010], w[2010];
long long ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", u + i, v + i);
    if (a[v[i]] <= a[u[i]]) swap(u[i], v[i]);
    ans += a[u[i]];
    w[i] = a[v[i]] - a[u[i]];
  }
  cout << ans << endl;
}
