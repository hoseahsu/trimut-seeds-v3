#include <bits/stdc++.h>
using namespace std;
char s[1050], ans[1050];
int fl[1050], c[1050];
int is_prime(int n) {
  double sqd = n;
  sqd = sqrt(sqd);
  int sq = sqd;
  sq++;
  for (int i = 2; i <= sq; i++) {
    if ((n % i) == 0) return 0;
  }
  return 1;
}
int main() {
  int i, j, k, l, test, t = 1;
  scanf("%s", s);
  int len = strlen(s);
  int now = 1;
  fl[0] = 1;
  j = len / 2;
  if (j)
    for (i = j + 1; i <= len; i++) {
      if (is_prime(i)) {
        fl[i - 1] = 1;
        now++;
      }
    }
  int req = len - now;
  for (i = 0; s[i]; i++) {
    c[s[i] - 'a']++;
  }
  int flag = 0, mark = 0;
  for (i = 0; i < 26; i++) {
    if (c[i] >= req) {
      mark = i;
      flag = 1;
      c[i] -= req;
      break;
    }
  }
  if (!flag) {
    printf("NO\n");
    return 0;
  }
  j = 0;
  for (i = 0; i < len; i++) {
    if (!fl[i]) {
      ans[i] = mark + 'a';
    } else {
      while (!c[j]) {
        j++;
      }
      ans[i] = j + 'a';
      c[j]--;
    }
  }
  ans[len] = 0;
  printf("YES\n%s\n", ans);
  return 0;
}
