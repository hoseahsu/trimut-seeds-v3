#include <bits/stdc++.h>
using namespace std;
int n, k;
bool pr[10000000 + 10];
void sieve() {
  memset(pr, true, sizeof(pr));
  pr[0] = pr[1] = false;
  for (int p = 2; p * p < 10000000;) {
    for (int i = 2; i * p < 10000000; i++) pr[i * p] = false;
    ++p;
    while (!pr[p]) ++p;
  }
}
int main() {
  sieve();
  scanf("%d %d", &n, &k);
  if (n / 2 > k) {
    printf("-1\n");
    return 0;
  }
  if (n == 1) {
    if (k == 0)
      printf("1\n");
    else
      printf("-1\n");
    return 0;
  }
  int mul = k - ((n / 2) - 1);
  printf("%d %d ", mul * 2, mul * 3);
  for (int i = 4, cnt = 0; i < 10000000 && cnt < n - 2; i++) {
    if (pr[i]) {
      cnt++;
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
