#include <bits/stdc++.h>
using namespace std;
long long n = 1, a[1000000], l, r;
int main() {
  long long i, j, k, s = 0, res = 0;
  cin >> n >> k;
  char cc = getchar();
  for (i = 0; i < n; i++) {
    char c = getchar();
    a[i] = c - 48;
  }
  for (i = 0; i < n && k > 0; i++) {
    if (a[i] == 7) {
      if (i == 0) continue;
      if ((i - 1) % 2 == 0 && a[i - 1] == 4) {
        a[i] = 4;
        k--;
        continue;
      }
      if (i == 1) continue;
      if (a[i - 2] == 4 && a[i - 1] == 4) {
        if (k % 2 == 1) a[i - 1] = 7;
        for (i = 0; i < n; i++) cout << a[i];
        return 0;
      }
      if (a[i - 1] == 4) {
        a[i - 1] = 7;
        k--;
      }
    }
  }
  for (i = 0; i < n; i++) cout << a[i];
  return 0;
}
