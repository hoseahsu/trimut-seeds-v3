#include <bits/stdc++.h>
using namespace std;
int a[10005], ans;
int main() {
  int n, m, A, B, i;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  while (m--) {
    scanf("%d%d", &A, &B);
    ans += min(a[A], a[B]);
  }
  cout << ans;
  return 0;
}
