#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
long long fastexp(long long a, long long n, long long nod = LLONG_MAX) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % nod;
    a = (a * a) % nod;
    n >>= 1;
  }
  return ans;
}
void fun() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n;) {
    int j = i;
    while (j + 1 < n && a[j] != a[j + 1]) j++;
    j++;
    ans = max(ans, (j - i - 1) / 2);
    if ((j - i) % 2 == 1) {
      for (int k = i; k < j; k++) {
        a[k] = a[i];
      }
    } else {
      for (int k = i; k < (i + j) / 2; k++) {
        a[k] = a[i];
      }
      for (int k = (i + j) / 2; k < j; k++) {
        a[k] = a[j - 1];
      }
    }
    i = j;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(20);
  cout << fixed;
  int t = 1;
  while (t--) {
    fun();
  }
}
