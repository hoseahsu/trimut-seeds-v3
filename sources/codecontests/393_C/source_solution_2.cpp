#include <bits/stdc++.h>
using namespace std;
long long n, ans;
bool a[40000005], b[40000005];
int main() {
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++)
    if (!a[i]) {
      a[i] = 1;
      ans++;
      long long p = trunc(sqrt(n * n - i * i));
      if (!b[p]) b[p] = 1;
    }
  for (long long i = 1; i <= n; i++)
    if (!b[i]) ans++;
  ans -= 1;
  ans *= 4;
  if (!n) ans = 1;
  printf("%I64d\n", ans);
  return 0;
}
