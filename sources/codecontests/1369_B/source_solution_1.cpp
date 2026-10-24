#include <bits/stdc++.h>
using namespace std;
int _, n;
char s[100005];
int main() {
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    s[0] = 'a';
    scanf("%s", s + 1);
    int p = -1;
    for (int i = n; i >= 1; i--) {
      if (s[i] == '0') {
        p = i;
        break;
      }
    }
    bool f = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') {
        if (s[i + 1] == '0')
          f = 1;
        else
          f = 0;
        if (i < p) {
          continue;
        }
        printf("1");
      } else {
        if (f) {
          printf("0");
          i = p;
          continue;
        }
        printf("0");
      }
    }
    puts("");
  }
}
