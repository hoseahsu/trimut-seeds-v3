#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1111];
int bk[1111];
int used[1111];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d", &bk[i]);
  }
  int res = 0;
  for (int i = k - 1; i >= 0; --i) {
    memset(used, 0, sizeof(used));
    for (int j = i - 1; j >= 0; --j) {
      if (bk[i] == bk[j]) break;
      if (!used[bk[j]]) {
        res += a[bk[j] - 1];
        used[bk[j]] = 1;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
