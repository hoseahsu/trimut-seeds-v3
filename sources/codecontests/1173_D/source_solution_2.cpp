#include <bits/stdc++.h>
const int N = 2e5 + 1, P = 998244353;
int deg[N];
int main() {
  int n, ans;
  scanf("%d", &n);
  ans = n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ans = (long long)ans * ++deg[u] % P;
    ans = (long long)ans * ++deg[v] % P;
  }
  printf("%d\n", ans);
  return 0;
}
