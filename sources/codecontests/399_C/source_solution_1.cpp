#include <bits/stdc++.h>
const long long int INFA = 1000000000;
const long long int INF = INFA * 10000000;
long long int somafeia(long long int a, long long int b, long long int ka,
                       long long int kb) {
  long long int piso = (long long int)floor(b / kb);
  long long int res = 0;
  res += (a - ka + 1) * (a - ka + 1);
  res += ka - 1;
  res -= piso * piso * kb;
  res -= (2 * piso + 1) * (b - (piso * kb));
  return res;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int a, b;
  int ra, rb;
  scanf("%d %d", &a, &b);
  long long int maximo = -INF;
  for (int kb = 1; kb <= b; kb++) {
    int ka;
    if (kb > a + 1) continue;
    if (kb > 1)
      ka = kb - 1;
    else
      ka = kb;
    long long int somafei = somafeia(a, b, ka, kb);
    if (somafei > maximo) {
      rb = kb;
      ra = ka;
    }
    maximo = max(maximo, somafei);
  }
  if (b == 0) {
    maximo = ((long long)(a)) * a;
    printf("%I64d\n", maximo);
    for (int i = 0; i < a; i++) printf("o");
  } else if (a == 0) {
    maximo = ((long long)(-b)) * b;
    printf("%I64d\n", maximo);
    for (int i = 0; i < b; i++) printf("x");
  } else {
    printf("%I64d\n", maximo);
    int piso = (int)floor(b / rb);
    int quantpiso = b - (piso * rb);
    int curb = 0;
    int cura = 0;
    for (int i = 0; i < ra + rb; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < piso; j++) {
          printf("x");
        }
        if (curb < quantpiso) {
          printf("x");
        }
        curb++;
      } else {
        if (cura == ra - 1) {
          for (int j = 0; j < a - ra + 1; j++) {
            printf("o");
          }
        } else
          printf("o");
        cura++;
      }
    }
  }
}
