#include <bits/stdc++.h>
using namespace std;
int T, n, mx, val, mxe = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    mx += val;
    if (val > mxe) mxe = val;
  }
  int i = mxe;
  while (n * i - mx <= mx) i++;
  printf("%d ", i);
}
