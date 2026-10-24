#include <bits/stdc++.h>
using namespace std;
int n, L[500010], R[500010], a[500010];
pair<int, int> b[500010];
void erase(int x) {
  int u = L[x], v = R[x];
  L[v] = u, R[u] = v;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = make_pair(a[i], i);
  sort(b + 1, b + n + 1);
  for (int i = 0; i <= n; i++) R[i] = i + 1, L[i + 1] = i;
  long long ans = 0;
  for (int i = 1; i < n - 1; i++) {
    int x = b[i].second;
    if (L[x] == 0 || R[x] == n + 1)
      ans += a[x];
    else
      ans += min(a[L[x]], a[R[x]]);
    erase(x);
  }
  cout << ans << endl;
}
