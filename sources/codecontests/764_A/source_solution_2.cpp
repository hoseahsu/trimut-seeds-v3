#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m) {
  while (m) {
    int tmp = n % m;
    n = m;
    m = tmp;
  }
  return n;
}
int main() {
  int n, m, z;
  while (~scanf("%d %d %d", &n, &m, &z)) {
    if (!(m % n) || !(n % m))
      printf("%d\n", z / max(n, m));
    else
      printf("%d\n", z * gcd(max(n, m), min(n, m)) / (n * m));
  }
}
