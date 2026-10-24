#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
int num[40];
int cnt;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int x = a[i];
    int tmp = 0;
    while (x) {
      if (x & 1)
        num[tmp++] += 1;
      else
        num[tmp++] += 0;
      x >>= 1;
    }
    cnt = max(cnt, tmp);
  }
  int pos = -1;
  for (int i = cnt - 1; i >= 0; i--)
    if (num[i] == 1) {
      pos = i;
      break;
    }
  if (pos == -1) {
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] >> pos & 1) {
      swap(a[i], a[1]);
      break;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
