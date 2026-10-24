#include <bits/stdc++.h>
using namespace std;
const int N = 10;
long long a[N];
int x[N];
int n, sum, ans;
void dfs(int k, int cnt, int groups) {
  if (k == n) {
    ans = min(ans, sum - cnt - (groups == 1));
    return;
  }
  dfs(k + 1, cnt, groups);
  for (int i = 0; i < k; i++) {
    if (a[i] % a[k] == 0) {
      a[i] /= a[k];
      dfs(k + 1, cnt + x[k] + (!x[k]), groups - 1);
      a[i] *= a[k];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  sort(a, a + n);
  reverse(a, a + n);
  sum = n + 1;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    long long tmp = a[i];
    for (long long j = 2; j * j <= a[i] && tmp > 1; j++) {
      while (tmp > 1 && tmp % j == 0) {
        tmp /= j;
        cnt++;
      }
    }
    if (tmp > 1 && tmp != a[i]) cnt++;
    x[i] = cnt;
    sum += cnt;
  }
  ans = 123456789;
  dfs(0, 0, n);
  printf("%d\n", ans);
  return 0;
}
