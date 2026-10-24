#include <bits/stdc++.h>
int pow(int x, long long n, int p) {
  if (n == 0) return (1);
  long long temp = pow(x, n / 2, p);
  temp = temp * temp % p;
  if (n % 2 != 0) temp = temp * x % p;
  return (temp);
}
int work(int k, long long l, long long r, int p) {
  if (p == 2)
    if (k % 2 == 0)
      return (1);
    else
      return (0);
  int q = pow(k, pow(2, l, p - 1), p), n = pow(2, r - l + 1, p - 1);
  long long s;
  if (q % p != 1) {
    int x = (pow(q, n, p) + (p - 1)) % p;
    int y = (q + p - 1) % p;
    s = x;
    s = s * pow(y, p - 2, p) % p;
  } else
    s = pow(2, r - l + 1, p);
  if (k % p == 0) s = 1;
  if (k % 2 == 0) return (s);
  int temp = pow(2, r - l, p);
  s = s * pow(temp, p - 2, p) % p;
  return (s);
}
int main() {
  int t, k, p;
  long long l, r;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %I64d %I64d %d", &k, &l, &r, &p);
    printf("%d\n", work(k, l, r, p));
  }
  return (0);
}
