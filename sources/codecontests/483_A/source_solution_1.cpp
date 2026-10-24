#include <bits/stdc++.h>
using namespace std;
int nod(long long A, long long B) {
  while (A != 0 && B != 0)
    if (A > B)
      A %= B;
    else
      B %= A;
  return A + B;
}
int main() {
  long long l, r, a, b, c, i, j, k;
  cin >> l >> r;
  a = 0;
  for (i = l; i <= r - 2; i++) {
    for (j = i + 1; j <= r - 1; j++) {
      for (k = j + 1; k <= r; k++)
        if (nod(i, j) == 1 && nod(i, k) != 1 && nod(j, k) == 1) {
          a = i;
          b = j;
          c = k;
          break;
        }
    }
  }
  if (a == 0)
    cout << "-1";
  else
    cout << a << ' ' << b << ' ' << c;
  return 0;
}
