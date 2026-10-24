#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
  int n;
  int oor, ob;
  int er, eb;
  while (scanf("%d", &n) != EOF) {
    scanf("%s", s + 1);
    oor = ob = er = eb = 0;
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
      if (i % 2 == 1) {
        if (s[i] == 'r')
          oor++;
        else
          ob++;
      } else {
        if (s[i] == 'r')
          er++;
        else
          eb++;
      }
    }
    int ans = min(max(er, ob), max(oor, eb));
    printf("%d\n", ans);
  }
  return 0;
}
