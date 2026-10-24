#include <bits/stdc++.h>
using namespace std;
int n, c1, c2, a, b, cnt;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &a, &b);
    if (a == 1) c1++;
    if (b == 1) c2++;
  }
  if (n - c1 >= c1)
    cnt += c1;
  else
    cnt += n - c1;
  if (n - c2 >= c2)
    cnt += c2;
  else
    cnt += n - c2;
  printf("%d", cnt);
  return 0;
}
