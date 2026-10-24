#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const long long mod = 100000793;
int n, a[MAXN], b[MAXN], c[MAXN];
long long pw[MAXN], sumb, sumc, suma;
struct discretization_node {
  int num;
  int ki;
} disc[MAXN];
bool cmp(discretization_node x, discretization_node y) { return x.num < y.num; }
void discretization(int a[], int n, discretization_node disc[]) {
  for (int i = 1; i <= n; ++i) {
    disc[i].num = a[i];
    disc[i].ki = i;
  }
  sort(disc + 1, disc + 1 + n, cmp);
  int cnt = 0, pre;
  for (int i = 1; i <= n; ++i) {
    if (i == 1 || a[disc[i].ki] != pre) ++cnt;
    pre = a[disc[i].ki];
    a[disc[i].ki] = cnt;
  }
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  discretization(a, n, disc);
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; ++i) {
    c[i] = b[n - i + 1];
  }
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 97 % mod;
  for (int i = 1; i <= n; ++i) {
    sumb = (sumb + pw[i] * b[i] % mod) % mod;
    sumc = (sumc + pw[i] * c[i] % mod) % mod;
    suma = (suma + pw[i] * a[i] % mod) % mod;
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i + 1]) continue;
    long long temp = suma;
    suma =
        ((suma - pw[i] * a[i] % mod - pw[i + 1] * a[i + 1] % mod) % mod + mod) %
        mod;
    suma = (suma + pw[i] * a[i + 1] % mod + pw[i + 1] * a[i] % mod) % mod;
    if (suma != sumb && suma != sumc) {
      printf("%d %d\n", i, i + 1);
      return 0;
    }
    suma = temp;
  }
  printf("-1\n");
  return 0;
}
