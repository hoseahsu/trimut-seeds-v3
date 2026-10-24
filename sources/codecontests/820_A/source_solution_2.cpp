#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, v0, v1, a, l, cnt = 0, g = 0;
  scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);
  for (int i = 1; i <= 1000; i++) {
    cnt += ((v0 + (a * (i - 1)) > v1) ? v1 : v0 + (a * (i - 1)));
    if (cnt >= c) return printf("%d", i), 0;
    cnt -= l;
  }
  return 0;
}
