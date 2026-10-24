#include <bits/stdc++.h>
using namespace std;
long long ans;
const int maxn = 100010;
long long pre[maxn], suf[maxn], a[maxn];
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre[1] = a[1], suf[n] = a[n];
  for (int i = 2; i <= n; i++) {
    pre[i] = gcd(pre[i - 1], a[i]);
  }
  for (int i = n - 1; i >= 1; i--) {
    suf[i] = gcd(suf[i + 1], a[i]);
  }
  for (int i = 0; i <= n - 1; i++) {
    if (i == 0)
      ans = suf[2];
    else if (i == n - 1)
      ans = ans * pre[n - 1] / gcd(pre[n - 1], ans);
    else {
      ans = ans * gcd(pre[i], suf[i + 2]) / gcd(gcd(pre[i], suf[i + 2]), ans);
    }
  }
  cout << ans << endl;
  return 0;
}
