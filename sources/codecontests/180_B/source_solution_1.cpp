#include <bits/stdc++.h>
using namespace std;
int m, p[100], a[100];
void GetFacts(int n) {
  m = 0;
  for (int i = 2; i <= n; ++i) {
    if (n % i == 0) {
      p[m] = i;
      a[m++] = 1;
      n /= i;
      while (n % i == 0) {
        ++a[m - 1];
        n /= i;
      }
    }
  }
}
int main(void) {
  int b, d;
  scanf("%d%d", &b, &d);
  GetFacts(d);
  bool yes = true;
  for (int i = 0; i < m; ++i) {
    if (b % p[i]) {
      yes = false;
      break;
    }
  }
  if (yes) {
    puts("2-type");
    int rep = 0;
    for (int i = 0; i < m; ++i) {
      int cnt = 0, x = b;
      while (x % p[i] == 0) {
        x /= p[i];
        ++cnt;
      }
      rep = max(rep, (a[i] + cnt - 1) / cnt);
    }
    printf("%d\n", rep);
    return 0;
  }
  if ((b - 1) % d == 0) {
    puts("3-type");
    return 0;
  }
  if ((b + 1) % d == 0) {
    puts("11-type");
    return 0;
  }
  yes = true;
  for (int i = 0; i < m; ++i) {
    int q = 1;
    for (int j = 0; j < a[i]; ++j) {
      q *= p[i];
    }
    if (b % p[i] && (b - 1) % q && (b + 1) % q) {
      yes = false;
      break;
    }
  }
  if (yes) {
    puts("6-type");
    return 0;
  }
  puts("7-type");
  return 0;
}
