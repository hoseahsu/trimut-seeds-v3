#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
struct IN {
  int pm, num;
} am[26];
int n, m, s, len;
bool b[maxn];
char str1[maxn], str2[maxn];
void init() {
  memset(am, 0, sizeof(am));
  for (int i = 0; i < 26; i++) am[i].pm = i;
}
void prim() {
  memset(b, true, sizeof(b));
  for (int i = 2; i < maxn; i++) {
    if (b[i]) {
      for (int j = 2 * i; j < maxn; j += i) {
        b[j] = false;
      }
    }
  }
  b[0] = false;
  b[1] = false;
}
int cmp1(IN a, IN b) { return a.pm < b.pm; }
int cmp2(IN a, IN b) { return a.num > b.num; }
void deal() {
  prim();
  int flag;
  for (int i = 0; i < len; i++) {
    if ((i != 0 && !b[i + 1]) || (b[i + 1] && (2 * (i + 1)) <= len)) {
      str2[i] = am[0].pm + 'a';
      am[0].num--;
    } else {
      flag = 0;
      for (int j = 1; j < 26; j++) {
        if (am[j].num) {
          str2[i] = am[j].pm + 'a';
          am[j].num--;
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        str2[i] = am[0].pm + 'a';
        am[0].num--;
      }
    }
  }
  if (am[0].num < 0)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < len; i++) printf("%c", str2[i]);
    printf("\n");
  }
}
int main() {
  while (scanf("%s", str1) != EOF) {
    memset(str2, 'A', sizeof(str2));
    init();
    len = strlen(str1);
    for (int i = 0; i < len; i++) am[str1[i] - 'a'].num++;
    sort(am, am + 26, cmp2);
    deal();
  }
  return 0;
}
