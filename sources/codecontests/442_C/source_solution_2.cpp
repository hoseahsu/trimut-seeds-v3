#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long s = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s;
}
long long a[500005], n, cnt;
long long ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[++cnt] = read();
    while (cnt > 2 && a[cnt - 2] >= a[cnt - 1] && a[cnt] >= a[cnt - 1]) {
      ans += min(a[cnt - 2], a[cnt]);
      a[cnt - 1] = a[cnt];
      a[cnt] = 0;
      cnt--;
    }
  }
  sort(a + 1, a + cnt + 1);
  for (int i = 1; i <= cnt - 2; i++) ans += a[i];
  printf("%lld", ans);
  return 0;
}
