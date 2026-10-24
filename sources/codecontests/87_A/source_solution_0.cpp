#include <bits/stdc++.h>
using namespace std;
inline int SG(double x) { return x > -1E-8 ? x < 1E-8 ? 0 : 1 : -1; }
long long gcd(long long a, long long b) {
  while ((a %= b) && (b %= a))
    ;
  return a + b;
}
int main() {
  long long a, b, i, j, d, sa;
  scanf("%I64d %I64d", &a, &b);
  d = a * b / gcd(a, b);
  sa = 0;
  for (i = 1, j = 0; i * a < d; i++) {
    while (j * b < i * a) j++;
    if ((j - 1) * b < (i - 1) * a) {
      sa += a;
    } else {
      sa += i * a - (j - 1) * b;
    }
  }
  if (a > b) {
    sa += b;
  }
  if (sa > d - sa) {
    puts("Dasha");
  } else if (sa < d - sa) {
    puts("Masha");
  } else {
    puts("Equal");
  }
  return 0;
}
