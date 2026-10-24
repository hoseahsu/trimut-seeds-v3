#include <bits/stdc++.h>
using namespace std;
int n, l, a, b, p;
char s[100010];
int f[100010];
int main() {
  cin >> n;
  while (n--) {
    cin >> a >> b >> p;
    scanf("%s", s);
    l = strlen(s);
    if (s[l - 2] == 'A')
      f[l - 2] = a;
    else
      f[l - 2] = b;
    if (f[l - 2] > p) {
      printf("%d\n", l);
      continue;
    }
    int i = l - 3;
    for (i = l - 3; i >= 0; i--) {
      f[i] = f[i + 1];
      if (s[i] != s[i + 1]) {
        if (s[i] == 'A')
          f[i] += a;
        else
          f[i] += b;
      }
      if (f[i] > p) break;
    }
    printf("%d\n", i + 2);
  }
  return 0;
}
