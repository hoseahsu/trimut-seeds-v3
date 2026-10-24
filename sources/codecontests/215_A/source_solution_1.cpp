#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, a[102], b[102], c[200002];
float f;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f = (float)b[j] / a[i];
      if (f - (int)f == 0) {
        c[k] = (int)f;
        k++;
      }
    }
  }
  sort(c, c + k);
  for (int i = k - 2; i >= 0; i--) {
    if (c[i] == c[k - 1]) {
      l++;
    } else {
      break;
    }
  }
  cout << l + 1;
  return 0;
}
