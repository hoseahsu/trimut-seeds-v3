#include <bits/stdc++.h>
using namespace std;
int a[500500], n, len, ans;
int main() {
  scanf("%d", &n);
  ans = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    int k = i;
    len = 0;
    while (a[k + 1] != a[k] && k < n - 1) {
      len++;
      k++;
    }
    if (i != k) {
      if (a[i] == a[k])
        for (i++; i < k; i++) a[i] = a[k];
      else {
        int j;
        for (j = 1; j <= (k - i) / 2; j++) a[j + i] = a[i];
        for (; j + i < k; j++) a[j + i] = a[k];
        i = k;
      }
    }
    ans = (ans > len ? ans : len);
  }
  if (ans == n) ans--;
  printf("%d\n", ans / 2);
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      cout << a[i] << endl;
    else
      cout << a[i] << " ";
  }
  printf("\n");
  return 0;
}
