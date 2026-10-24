#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010], po[100010];
long long ans, sav, te, last, l, r, cur;
long long fac[100010], dfac[100010];
inline long long C(int a, int b) {
  long long res = fac[a] * dfac[a - b] % 1000000007ll * dfac[b] % 1000000007ll;
  return res;
}
inline long long poww(long long x, long long k) {
  if (k == 1) return x;
  long long te = poww(x, k / 2);
  te = te * te % 1000000007ll;
  if (k & 1) te = te * x % 1000000007ll;
  return te;
}
int main() {
  scanf("%d", &n);
  n++;
  a[n] = n;
  po[n] = n;
  cur = n;
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % 1000000007ll;
  for (int i = 0; i <= n; i++) dfac[i] = poww(fac[i], 1000000007ll - 2);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d", &a[i]);
    if (a[i]) {
      po[a[i]] = i;
      if (a[i] < a[cur]) cur = i;
    }
  }
  l = cur - a[cur] + 1;
  r = cur;
  te = 0;
  for (int i = l; i <= r - 1; i++)
    te = (te + C(r - l - 1, i - l)) % 1000000007ll;
  if (te == 0) te = 1;
  ans = te;
  last = a[cur];
  for (int i = a[cur] + 1; i <= n; i++)
    if (po[i]) {
      if (po[i] - r > i - last || l - po[i] > i - last ||
          ((po[i] >= l) && (po[i] <= r))) {
        ans = 0;
        break;
      }
      if (po[i] > r)
        ans = ans * C(i - last - 1, po[i] - r - 1) % 1000000007ll,
        l = l - (i - last - (po[i] - r)), r = po[i];
      else
        ans = ans * C(i - last - 1, l - po[i] - 1) % 1000000007ll,
        r = r + (i - last - (l - po[i])), l = po[i];
      if (l < 1 || r > n) {
        ans = 0;
        break;
      }
      last = i;
    }
  if (l < 1 || r > n) ans = 0;
  sav = ans;
  l = cur;
  r = a[cur] + cur - 1;
  te = 0;
  for (int i = l + 1; i <= r; i++)
    te = (te + C(r - l - 1, i - l - 1)) % 1000000007ll;
  ans = te;
  last = a[cur];
  for (int i = a[cur] + 1; i <= n; i++)
    if (po[i]) {
      if (po[i] - r > i - last || l - po[i] > i - last ||
          ((po[i] >= l) && (po[i] <= r))) {
        ans = 0;
        break;
      }
      if (po[i] > r)
        ans = ans * C(i - last - 1, po[i] - r - 1) % 1000000007ll,
        l = l - (i - last - (po[i] - r)), r = po[i];
      else
        ans = ans * C(i - last - 1, l - po[i] - 1) % 1000000007ll,
        r = r + (i - last - (l - po[i])), l = po[i];
      if (l < 1 || r > n) {
        ans = 0;
        break;
      }
      last = i;
    }
  if (l < 1 || r > n) ans = 0;
  ans = (ans + sav) % 1000000007ll;
  cout << ans << endl;
  return 0;
}
