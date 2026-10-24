#include <bits/stdc++.h>
using namespace std;
int n, all;
int t[2100], c[2100];
long long f[5000], answer = 1e18 + 1;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d%d", &t[i], &c[i]);
    ++t[i];
    all = max(all, t[i]);
  }
  all += n;
  for (register int i = 1; i <= all; i++) f[i] = 1e18 + 1;
  for (register int i = 1; i <= n; i++)
    for (register int j = all; j >= t[i]; j--)
      f[j] = min(f[j], f[j - t[i]] + c[i]);
  for (register int i = n; i <= all; i++) answer = min(answer, f[i]);
  cout << answer;
  return 0;
}
