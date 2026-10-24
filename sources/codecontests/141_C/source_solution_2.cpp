#include <bits/stdc++.h>
using namespace std;
int n;
struct pe {
  char na[20];
  int bef, h;
  bool operator<(const pe& b) const { return bef < b.bef; }
} a[3005];
char ch[20];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s%d", a[i].na, &a[i].bef);
    a[i].h = 1;
  }
  sort(a + 1, a + 1 + n);
  int mx = 50000;
  for (int i = 1; i <= n; i++) {
    if (i <= a[i].bef) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].bef != a[i - 1].bef) {
      mx--;
      int now = a[i].bef - a[i - 1].bef;
      for (int j = i - 1; (j != 0) && (now != 0); j--) {
        if (a[j].h == 1) {
          a[j].h = mx;
          now--;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%s %d\n", a[i].na, a[i].h);
  }
}
