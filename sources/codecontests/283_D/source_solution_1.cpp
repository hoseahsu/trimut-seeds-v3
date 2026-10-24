#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
const int maxn = 5000;
long long a[maxn], d[maxn];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int cntTwo[maxn];
long long without[maxn];
bool ok(int i, int j) {
  if (without[i] % without[j]) return 0;
  return (cntTwo[i] - cntTwo[j] == i - j) || (cntTwo[j] < (j - i));
}
int main() {
  srand(rdtsc());
  int n;
  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) {
      int &cnt = cntTwo[i];
      cnt = 0;
      for (long long x = a[i]; x && !(x & 1); x >>= 1) cnt++;
      without[i] = (a[i] >> cnt);
    }
    d[0] = 0;
    long long ans = n - 1;
    for (int i = 1; i < n; i++) {
      d[i] = i;
      for (int j = 0; j < i; j++) {
        if (ok(j, i)) d[i] = min(d[i], d[j] + i - j - 1);
      }
      ans = min(ans, n - i - 1 + d[i]);
    }
    printf(
        "%lld"
        "\n",
        ans);
  }
  return 0;
}
