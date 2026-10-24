#include <bits/stdc++.h>
using namespace std;
const int primes[5] = {2, 3, 5, 7, 11};
int maxP, sz, n;
int cPrimes[55];
int a[2000000];
void run(int x, int t) {
  if (t == maxP) {
    a[sz++] = x;
    return;
  }
  while (x <= n * n * 2) {
    run(x, t + 1);
    x *= primes[t];
  }
}
int main() {
  scanf("%d", &n);
  while (true) {
    sz = 0;
    bool ok = true;
    maxP = 1 + rand() % 5;
    run(1, 0);
    random_shuffle(a, a + sz);
    if (sz < n) continue;
    for (int j = 0; j < maxP; ++j) cPrimes[j] = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < maxP; ++j)
        if (a[i] % primes[j] == 0) cPrimes[j]++;
    for (int j = 0; j < maxP; ++j)
      if (cPrimes[j] < (n + 1) / 2) {
        ok = false;
        break;
      }
    if (ok) {
      for (int i = 0; i < n; ++i) cout << a[i] << " ";
      cout << endl;
      return 0;
    }
  }
  return 0;
}
