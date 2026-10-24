#include <bits/stdc++.h>
using namespace std;
int main() {
  int d[32];
  int k = 0;
  int a, c;
  cin >> a >> c;
  while (a || c) {
    int r1 = a % 3, r2 = c % 3;
    for (int i = 0; i < 3; i++) {
      if ((r1 + i) % 3 == r2) {
        d[k++] = i;
        break;
      }
    }
    a /= 3;
    c /= 3;
  }
  long long ans = 0, p = 1;
  for (int i = 0; i < k; i++) {
    ans += d[i] * p;
    p *= 3;
  }
  cout << ans;
  return 0;
}
