#include <bits/stdc++.h>
using namespace std;
int n, nr, i;
char s[104];
int main() {
  scanf("%d", &n);
  scanf("%s", &s);
  n--;
  nr = 0;
  for (i = 0; i <= n; i++) {
    if (s[i] == '0')
      nr++;
    else
      nr--;
  }
  if (nr != 0)
    printf("%d\n%s\n", 1, s);
  else {
    printf("2\n%c ", s[0]);
    for (i = 1; i <= n; i++) printf("%c", s[i]);
    printf("\n");
  }
  return 0;
}
