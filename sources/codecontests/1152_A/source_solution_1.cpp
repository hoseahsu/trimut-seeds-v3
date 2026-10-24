#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
  int n, m;
  int ja = 0, oa = 0, jb = 0, ob = 0, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x & 1)
      ja++;
    else
      oa++;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    if (x & 1)
      jb++;
    else
      ob++;
  }
  printf("%d", min(ja, ob) + min(jb, oa));
  return 0;
}
