#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
int n;
char s[2][N], ans[N];
int m;
int main() {
  scanf("%s", s[0]);
  scanf(" %s", s[1]);
  n = strlen(s[0]);
  sort(s[0], s[0] + n);
  sort(s[1], s[1] + n);
  reverse(s[1], s[1] + n);
  int k = 0;
  int it[2] = {0, 0};
  while (m < n && s[0][it[0]] < s[1][it[1]]) {
    ans[m] = s[k][it[k]++];
    m++;
    k ^= 1;
  }
  if (n % 2 == 0)
    k = 1;
  else
    k = 0;
  while (m < n) {
    ans[m] = s[k][it[k]++];
    m++;
    k ^= 1;
  }
  ans[n] = '\0';
  printf("%s\n", ans);
  return 0;
}
