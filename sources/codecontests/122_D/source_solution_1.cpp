#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[1000010];
int main() {
  register int i;
  while (scanf("%d%d", &n, &k) != EOF) {
    scanf("%s", s + 1);
    s[n + 1] = '\0';
    for (i = 1; i < n; i++) {
      if (!k) goto qaz;
      if (s[i] == '4' && s[i + 1] == '7') {
        if (i & 1) {
          if (s[i + 2] == '7') {
            s[i + 1] = (k & 1 ? '4' : '7');
            goto qaz;
          } else
            s[i + 1] = '4', k--;
          if (!k) goto qaz;
        } else {
          if (s[i - 1] == '4') {
            s[i] = (k & 1 ? '7' : '4');
            goto qaz;
          } else
            s[i] = '7', k--;
          if (!k) goto qaz;
        }
      }
    }
  qaz:;
    puts(s + 1);
  }
  return 0;
}
