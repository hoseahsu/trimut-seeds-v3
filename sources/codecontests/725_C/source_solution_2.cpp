#include <bits/stdc++.h>
using namespace std;
char grid[2][15];
int used[26];
int main() {
  char s[30], k;
  int p, q, d;
  memset(used, 0, sizeof(used));
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    used[s[i] - 'A']++;
    if (used[s[i] - 'A'] >= 2) {
      k = s[i];
      p = i;
    }
  }
  for (int i = 0; s[i]; i++)
    if (s[i] == k) {
      q = i;
      break;
    }
  d = p - q - 1;
  if (d == 0)
    printf("Impossible");
  else {
    grid[0][12 - d / 2] = k;
    if (d % 2 == 1) {
      grid[1][12 - d / 2 - 1] = s[q - 1];
    } else {
      grid[1][12 - d / 2] = s[q - 1];
    }
    int r = 0, dc = 1, cur = 13 - d / 2;
    for (int i = q + 1; i < p; i++) {
      if (cur == 13) {
        r = 1;
        cur = 12;
        dc = -1;
      }
      grid[r][cur] = s[i];
      if (cur == 12 && r == 0) {
        r = 1;
        dc = 0;
      } else if (cur == 12 && r == 1)
        dc = -1;
      cur += dc;
    }
    r = 0, dc = -1, cur = 12 - d / 2 - 1;
    for (int i = p + 1; s[i]; i++) {
      if (cur <= -1) {
        dc = 1;
        cur = 0;
        r = 1;
      }
      grid[r][cur] = s[i];
      if (cur == 0 && r == 0) {
        r = 1;
        dc = 0;
      } else if (cur == 0 && r == 1)
        dc = 1;
      cur += dc;
    }
    for (int i = 0; i < q - 1; i++) {
      grid[r][cur] = s[i];
      if (cur == 0 && r == 0) {
        r = 1;
        dc = 0;
      } else if (cur == 0 && r == 1)
        dc = 1;
      cur += dc;
    }
  }
  printf("%s\n%s", grid[0], grid[1]);
  return 0;
}
