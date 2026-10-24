#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int b, c, d = 0, e, f = 0, g, h, i, j = 1, k = 0, max = 0, l, m, n,
                      x, y, min = 0;
  cin >> n >> m;
  int a[n], a1[100];
  string s, s1;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    d = d + a[i];
    if (a[i] > max) {
      max = a[i];
      c = i;
    }
  }
  min = a[1];
  if (d <= m) {
    cout << n << endl;
    for (i = 1; i <= n; i++) {
      cout << i << " ";
    }
  } else {
    while (1) {
      b = c;
      for (i = 1; i <= n; i++) {
        if (a[i] != 0 && a[i] <= min) {
          min = a[i];
          b = i;
        }
      }
      a[b] = 0;
      k = k + min;
      if (k < m) {
        f++;
        a1[j] = b;
        j++;
      } else if (k == m) {
        f++;
        a1[j] = b;
        j++;
        cout << f << endl;
        break;
      } else if (k > m) {
        if (f == 0) {
          cout << f;
          return 0;
        } else {
          cout << f << endl;
          break;
        }
      }
      min = a[c];
    }
    for (i = 1; i < j; i++) {
      cout << a1[i] << " ";
    }
  }
  return 0;
}
