#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int a[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int p = n - 1;
  for (int i = n / 2 - 1; i >= 0; i--)
    if (a[p] >= 2 * a[i]) p--;
  printf("%d\n", p + 1);
  return 0;
}
